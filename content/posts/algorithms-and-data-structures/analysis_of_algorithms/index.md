---
name: "Analysis of Algorithms"
date: 2019-10-22
---

# Introduction

* What is RAM (Random Access Machine) and why we need to resort to it?
    * Peculiarities of RAM
    * RAM vs Turing machine
* Definition of a cost function
* 

# Asymptotic notation - Landau symbols [@smith04; @doe99]

Let $g(n)$ be a cost function, we denote with $O(g(n))$ the set of
functions $f(n)$ such that:

$$
\exists c > 0, \exists m > 0: f(n) \leq cg(n), \forall n > m
$$

Let $g(n)$ be a cost function, we denote with $\Omega(g(n))$ the set of
functions $f(n)$ such that:

$$
\exists c > 0, \exists m > 0: f(n) \geq cg(n), \forall n > m
$$

Let $g(n)$ be a cost function, we denote with $\Theta(g(n))$ the set of
functions $f(n)$ such that:

$$
\exists c_1 > 0, \exists c_2 > 0, \exists m > 0: c_1g(n) \leq f(n) \leq c_2g(n), \forall n > m
$$
