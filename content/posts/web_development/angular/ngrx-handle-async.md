---
date: 2019-11-17
title: "A scalable approach for async state handling in NgRx"
---

It boils down to: store or not to store...

Pending state should be stored in both cases, since the reducer can
automatically clear.

Store success/error 
* Advantages
  * canonical way 
  * component can become stateless
* Drawbacks
  * take care to clear status variables
    * Boilerplate
  * one-shot side effect harder to handle
  * Minimal runtime cost

Not store success/error 
* Advantages
  * one-shot side effect easier to handle
* Drawbacks
  * Side effect that must be kept is harder to handle. Need to introduce local
  state in component.
  * Seems to be an antipattern (Why?)

# Introduction

Handling async state (mostly HTTP requests) in a web app is painful: for each
possible request to the server pending state, success state and error state
need to be handled.

## Storing status flags in the store

```ts
interface State {
  loading: boolean;
  success: boolean;
  error: HttpErrorResponse | null;
  ...
}

export const initialState: AuthState = {
  loading: false;
  success: false;
  error: null;
};
const asyncStateReducer = createReducer(
  initialState,
  on(Actions.load,
     (state, action) => ({ ...state, loading: true }) 
  ),
  on(Actions.loadSuccess,
     (state, action) => ({ ...state, ...payload, loading: false, success: true })
  ),
  on(Actions.loadFailure,
     (state, action) => ({ ...state, loading: false, error: action.error })
  ),
)
```

```ts
load$ = createEffect(() => this.actions$.pipe(
  ofType(Actions.load),
  exhaustMap((action) => this.someService.load(action.payload).pipe(
    map(data => Actions.loadSuccess({ payload: data })),
    catchError(error => of(Actions.loadFailure({ error })))
  ),
  )),
);
```

### Pitfall

Imagine the following scenario: two components A and B dispatch contemporarily
the `Actions.load` action and subscribe to the success, loading and error
state with the specific selectors, so as to show in the view different elements
(spinner, error messages, success notification toast).
The first HTTP request succeeds, whereas the second fails. Both will have
the error message and success message in the view.j

### Moral of the story

Single state flags are not enough for a feature state, since we can have
multiple components triggering different actions of the feature state with HTTP
requests as side effects, and these async states sometimes need to be handled
singularly.

## Subscribing to the action in the component

https://stackoverflow.com/a/43227485

### Pitfall

Same problem on multiple components dispatching the same action.
We could add a `source` parameter in the prop of the action to disambiguate
between the dispatchers and then filter of the actions of the current dispacher
in the selector.

Tight coupling action with action success/ action error.


## Proposed solution

* Not store error: sometimes we need to know details about the error
* Not store success: hard to derive success from error and pending
* Store success and error: further boilerplate code to clear them.
  * Use class decorator!

Mike Ryan in https://www.youtube.com/watch?v=JmnsEvoy-gY highlights a few
best practises regarding the use of actions in a NgRx application.
One of his claims is that actions are not supposed to be reused, since
the reuse of actions defeats one of the advantages of adopting NgRx:
traceability of state changes, in the specific case of knowledge of **where
do they come from**, i.e. which part of the application triggered them.

We encountered the other face of the problem before

References:

* https://stackoverflow.com/questions/48854931/right-approach-to-display-success-error-messages-via-ngrx
* https://stackoverflow.com/questions/43226681/how-to-subscribe-to-action-success-callback-using-ngrx-and-effects
* https://stackoverflow.com/questions/43112695/ngrx-populate-success-dispatched-actions-on-component
