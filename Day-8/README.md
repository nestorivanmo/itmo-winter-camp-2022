# Day 8: Dynamic Programming 2

## Optimal Matrix Multiplication

- Find out the order of multiplications so taht it takes minimum number of operations
- Multipliying matrix $A\times B$ with matrix $C$ takes $A\cdot B \cdot C$ operations
- $f(L,R)$ is the minimum number of operations to calculate $A_L\cdot A_{L+1} \cdots A_R$

## Independent set on a tree

- Given a tree $T = <V,E>$, find an independent set of vertices whose sum of weights is maximal and these vertices should not be neighbors
- $f(v)$ is the max weight of the independent set in $v$-rooted subtree if $v$ is taken
- $g(v)$ is the max weight independent set in $v$-rooted subtree if $v$ isn't taken
- Answer: $\max (f(v), g(v))$

## Traveling Salesman Problem

- Find minimum length of roads used (order of the cities visited)
