---
date: 2019-11-21
---

# Pocket note on RxJS operators

Most operators in RxJS are pretty straightforward to understand, but some of
them, mostly those that work with *higher order Observables* have caused me
some confusion.
I end up re-learning them each time I need to cope with higher order observables,
which eventually lead me to write this pocket reference for myself.

## What are higher order observables?

It's just a fancy name for observables that emit observables.

Let's make an easy example:

```ts
const coolHigherOrderObservable$ = of(1, 2, 3).pipe(
  map(num => of(num))
)
// No, it won't print 1, 2, 3. It'll print 3 observable objects.
// Something like:
// Observable { _isScalar: false, _subscribe: [Function] }
// Observable { _isScalar: false, _subscribe: [Function] }
// Observable { _isScalar: false, _subscribe: [Function] }
coolHigherOrderObservable$.subscribe(observable => { console.log(observable) })
```

What we've done in the `pipe` is to map each emitted number into a new
observable `of`...  that number.
By subscribing to `coolHigherOrderObservable`, that we receive are other
observables and if we want to get the actual values, we have to subscribe
to them too.

```ts
const coolHigherOrderObservable$ = of(1, 2, 3).pipe(
  map(num => of(num))
)
// 1
// 2
// 3
coolHigherOrderObservable$.subscribe(observable$ => {
  observable$.subscribe((value) => console.log(value))
})
```

For mere mortals, dealing with higher order stuff, meta stuff, etc. can be quite
challenging, but fortunately we have at our disposal the flattening operators.

These operators subscribe to the inner-observable(s) that the outer higher order
observable emits and we at the end of the pipe can relax ourselves and just
receive the values that we expects.

What differentials between them, is the *strategy* they use to subscribe to the
inner observables.

## `mergeAll`

Subscribe to all the inner observables and merge their values.

## `switchAll`

Unsubscribing from the last inner observable, when the new one arrives.

## `concatAll`

Queuing up every new Observable, and subscribing to a new observable only when
the last observable completed.

## `exhaust`

“Exhaust” strategy — the “don’t interrupt me” strategy, ignores (and never
subscribe to) any new mapped Observable while the current Observable is still
emitting values.

Often, instead of having higher-order observable to be flattened with the
operators listed above, we end up creating them in a `pipe`, i.e.  we take the
values emitted by a observable and map them into observables. Still, what we
care at the end of the pipe, is values from these inner-observable.

Fortunately, RxJS provides the *map version of the flattening operators.

* `mergeMap`
* `switchMap`
* `concatMap`
* `exhaustMap`

Source:
* https://rxjs-dev.firebaseapp.com/api/operators/switchMap
* https://medium.com/@luukgruijs/understanding-rxjs-map-mergemap-switchmap-and-concatmap-833fc1fb09ff
* https://netbasal.com/understanding-mergemap-and-switchmap-in-rxjs-13cf9c57c885
* https://medium.com/@shairez/a-super-ninja-trick-to-learn-rxjss-switchmap-mergemap-concatmap-and-exhaustmap-forever-88e178a75f1b
