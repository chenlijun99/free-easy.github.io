---
date: 2019-11-13
---

# Propositional logic

Propositional logic

For sake of succinctness, we'll be using PL to refer to Propositional Logic.

## The language of PL

The language of a propositional calculus consists of:

* A set of primitive symbols ($\mathcal{P}$ or $\mathcal{PROP}$ [@cite unitn]), variously referred as:
  * atomic formula
  * (propositional) variables
  * statement letters

* A set of operator symbols, variously referred as *logical operators* or
  *logical connectives*, which are, in order of precedence:
  * $\neg$: negation
  * $\wedge$: and
  * $\vee$: or
  * $\supset$ or $\rightarrow$: [material conditional](https://en.wikipedia.org/wiki/Material_conditional)
  * $\equiv$: equivalence

### (Well formed) PL formulas

A propositional formula (often more briefly referred as "proposition")
is defined as follows:

1. Every $\mathscr{P} \in \mathcal{P}$ is a *atomic formula*.
2. Every *atomic formula* is a *formula*.
3. If $\phi, \psi$ are formulas then $\neg \phi$,  $\phi \wedge \psi$,  $\phi
  \vee \psi$ ,$\phi \supset \psi$, $\phi \equiv \psi$ are formulas.

### Notation [@cite Wikipedia]

* $A, B, C$ will be used as *propositional constants*, which represent some
  particular proposition;
* $P, Q, R$ will be used as *propositional variables*, which range over the set
  of all atomic propositions;
* $\phi, \psi$ will be used as *schemata*, which range over all propositions.

## Propositional interpretation

A *propositional interpretation* is a function
$I: \mathcal{PROP} \rightarrow \{\top, \bot\}$.

Atomic formulas by their own don't carry any truth value, we need a interpretation
function that assigns truth value to each of them.

Given a set of atomic formula $\mathcal{PROP}$ there are $2^{|\mathcal{PROP}|}$
distinct interpretation function.

E.g.

Given $\{A, B\}$, there are four different interpretation functions.

|         | A      | B      |
|---------|--------|--------|
| $I_{1}$ | $\bot$ | $\bot$ |
| $I_{2}$ | $\top$ | $\bot$ |
| $I_{3}$ | $\bot$ | $\top$ |
| $I_{4}$ | $\top$ | $\top$ |


## Lazy evaluation algorithm

##

	\item What is a propositional interpretation (a.k.a. truth assignment)?  What else can you say about it?

		A function that maps atomic formulas to either true or false.

		$ I: \mathcal{P} \rightarrow \{T, F\} $,

		where $\mathcal{P}$ is the set of all atomic formulas in a
		propositional language.

		Obviously, given a $\mathcal{P}$, there are $2^{\mid\mathcal{P}\mid}$ 
		possible interpretations.

		A propositional interpretation can also be seen as
		a subset $S \subseteq \mathcal{P}$ of all the atomic formulas
		that are true.

	\item What does the following expression mean? $ I \models \varphi $, where
		$I$ is an interpretation function and $\varphi$ represents any formula
		in the PL language.

		That $\varphi$ is satisfied by $I$ or that $I$ satisfies/models $\varphi$.

	\item How do you define that a propositional interpretation satisfies/models a PL formula?

		\begin{itemize}
			\item $I \models P 
				\quad\iff\quad
				I(P) = T$, where $P \in \mathcal{P}$
			\item $I \models \neg\varphi 
				\quad\iff\quad
				\neg I \models \varphi$
			\item $I \models \varphi \wedge \psi 
				\quad\iff\quad
				I \models \varphi \wedge I \models \psi$
			\item $I \models \varphi \vee \psi 
				\quad\iff\quad
				I \models \varphi \vee I \models \psi$
			\item $I \models \varphi \rightarrow \psi 
				\quad\iff\quad
				I \models \varphi \implies I \models \psi$
			\item $I \models \varphi \equiv \psi 
				\quad\iff\quad
				I \models \varphi \iff I \models \psi$
		\end{itemize}

	\item When a PL formula $\varphi$ is said to be respectively \emph{valid}, \emph{satisfiable} and \emph{unsatisfiable}?
		\begin{itemize}
			\item Valid: $ \forall I, I \models \varphi $
			\item Satisfiable: $ \exists I: I \models \varphi $
			\item Unsatisfiable: $ \nexists I: I \models \varphi $
		\end{itemize}

	\item 
		A handful of propositions:
		\begin{itemize}
			\item $\varphi$ valid $\implies \varphi$ satisfiable $\iff \varphi$
				not unsatisfiable
			\item $\varphi$ unsatisfiable $\iff \varphi$ not satisfiable
				$\implies \varphi$ not valid
			\item $\varphi$ valid $\implies \neg \varphi $ unsatisfiable
			\item $\varphi$ unsatisfiable $\implies \neg \varphi $ valid
			\item $\varphi$ satisfiable $\implies \neg \varphi $ neg valid
			\item $\varphi$ neg valid $\implies \neg \varphi $ satisfiable
		\end{itemize}


	\item When a set of PL formula $\Gamma$ is said to be respectively \emph{valid}, \emph{satisfiable} and \emph{unsatisfiable}?

		\begin{itemize}
			\item Valid: $\forall I, I \models \varphi, \forall \varphi \in \Gamma$
			\item Satisfiable: $\exists I: I \models \varphi, \forall \varphi \in \Gamma$
			\item Unsatisfiable: $\nexists I: I \models \varphi, \forall \varphi \in \Gamma$
		\end{itemize}
	
	\item Definition of logical consequence in PL

		A formula $\varphi$ is said to be a logical consequence of a set of
		formulas $\Gamma$, if for any interpretation $I$ that satisfies
		all the formulas in $\Gamma$, $I$ satisfies $\varphi$.

		$ \Gamma \models \varphi \iff \forall I: I \models \psi, \forall \psi \in
		\Gamma, I \models \varphi$

	\item Definition of logical equivalence in PL

		Two formulas $\varphi$ and $\psi$ are logical equivalent if and only
		if for any interpretation $I$ they have the same truth value.

		$ \varphi \equiv \psi \iff \forall I, I(\varphi) = I(\psi) $

	\item 
		Properties of logical consequence:
		if $\Gamma$ and $\Sigma$ are two set of PL formulas and $\varphi$ and
		$\psi$ to PL formulas, then the following properties hold:
		\begin{itemize}
			\item \emph{Reflexivity}: $ \{ \varphi \} \models \varphi $
			\item \emph{Monotonicity}: $ \Gamma \models \varphi \implies \Gamma
				\cup \Sigma \models \varphi $
			\item \emph{Cut}: $ \Gamma \models \varphi
				\wedge
				\Sigma \cup \{ \varphi \} \models \psi
				\implies
				\Gamma \cup \Sigma \models \psi
				$
			\item \emph{Compactness}:
				$ \Gamma \models \varphi \implies \exists \Gamma_0 \subseteq
				\Gamma: \Gamma_0 \models \varphi $, where $ \Gamma_0 $ is a 
				finite subset of $\Gamma$
			\item \emph{Deduction theorem}:
				$ \Gamma, \varphi \models \psi \implies \Gamma \models \varphi \rightarrow \psi $
			\item \emph{Refutation principle}
				$ \Gamma \models \varphi \iff \Gamma \cup \{ \neg\varphi \} $
				is unsatisfiable
		\end{itemize}

	\item Definition of theory in PL

		A theory is a set of logical formulas closed under logical consequence.

		$ T $ is a theory $ \iff T \models \varphi \implies \varphi \in T $.

		Every formula in $T$ is called \emph{theorem}.

	\item Definition of axioms in PL

		A set of formulas $\Omega$ is a set of axioms of a theory $T$ if
		$\forall \varphi \in T, \Omega \models \varphi$.

	\item Definition of finitely axiomatizable theory

		A set is finitely axiomatizable if it has a finite set of axioms.

	\item What does $ \models \phi $ mean in PL?
		$\phi$ is a valid formula.

	\item Decision problems in PL
		\begin{itemize}
			\item Model checking: $(I, \varphi): I \overset{?}{\models} \varphi$
			\item Satisfiability: $(\varphi): \overset{?}{\exists} I: I \models \varphi $
			\item Validity: $(\varphi): \overset{?}{\exists} I: \neg I \models \varphi$ or $\overset{?}{\models}\varphi$
			\item Logical consequence: $(\Gamma, \varphi): \Gamma \overset{?}{\models} \varphi$
		\end{itemize}

# Bibliography

* [UniTN slides](https://drive.google.com/file/d/1Y3CyVk0pmLb51JGBa3pJAlqPfFKvjgQx/view)
* https://www.iep.utm.edu/prop-log/#H3
* https://www.inf.unibz.it/~franconi/dl/course/slides/logic/propositional/prop-logic-1.pdf
* http://discrete.openmathbooks.org/dmoi2/sec_propositional.html
* http://infolab.stanford.edu/~ullman/focs/ch12.pdf
* http://disi.unitn.it/~bernardi/Courses/Logic06/oct_13_pl.pdf
* https://en.wikipedia.org/wiki/Propositional_calculus#Explanation
