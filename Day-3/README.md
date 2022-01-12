# Day 3: Dynamic Programming

- **Idea**: define a pure function where we must find the states of dp (arguments) and the transitions
- We must FIND A FUNCTION, STATES and TRANSITIONS

## 1. Fibonacci sequence

- $F_n = F_{n-1} + F_{n-2} \geq 2F_{n-2}$
- Naive approach: not good -> $\sqrt{2}^n$ calls
- Better approach: memoization -> $2n-1$ calls
  ```
  f <- -1 // array initially filled with -1
  FibMemo(n)
    if n <= 1
        return 1
    if f[n] < 0
        f[n] = FibMemo(n-1) + FibMemo(n-2)
    return f[n]
  ```
- Second approach: array filling
  ```
  f <- array
  FibArray(n)
    f[0] = 1
    f[1] = 1
    for i = 2 to n 
        f[i] = f[i-1] + f[i-2] // formula
    return f[n]
  ```

## 2. Grasshopper

-  Most of DP we start with the definition of the function and try to imagine that function as recursive (although implementationwise not always is recursive)
-  $f(i)$ is the max profit among all paths from $0$ to $i$
-  $f(n)$ is the answer
   -  $\forall i | i \geq 2: f(i) = \max(f(i-1) + a_i - b, f(i-2) + a_i - c)$
   -  $f(0) = a_0$
   -  $f(1) = a_1 - b$
- This just gives the profit, but not the path of the best jumps

```
BestPathBack(a, b, c, n) // backward calculation
    f[0] = 0
    f[1] = a[1] - b
    for i = 1 to n do
        f[i] = max(f[i-1] + a[i] - b, f[i-2] + a[i] - c)
    return f[n]
```

```
BestPathForward(a,b,c,n) // forward calculation
    f <- -infinity
    f[0] = 0
    for i = 0 to n-1 do
        f[i+1] = max(f[i+1], f[i]+a[i+1]-b) // 2nd term: relaxation
        if i+2 <= n then
            f[i+2] = max(f[i+2], f[i]+a[i+2]-c)
    return f[n]
```

## 3. Longest Increasing Subsequence

- Remaining numbers form an increasing sequence
- $2^n$ subsequences -> need for DP
- $f(i)$ - maximum length of increasing subsequence that ends at $i$-th element
  - $f(5)=3$
  - $f(6)=1$
- $f(i) = \max(1, f(j)+1)\quad j<i,a_j<a_i$
- Answer: $\max(f(i))$ where $i:1\rightarrow n$

```
LIS(a,n)
    for i = 1 to n do
        f[i] = 1
        for j = 1 to i-1 do
            if a[j] < a[i] then
                f[i] = max(f[i], f[j]+1)
    return max f[i] from i=1 to i=n
```
- $O(n^2)$

- How to restore the sequence? (Previous analysis only gets the length). Three methods:
  1. **Store the answer**
     - Add $g(i)$ which will store the sequence
        ```
        LIS(a,n)
        for i = 1 to n do
            f[i] = 1
            f[i] = <a[i]> // <>: list
            for j = 1 to i-1 do
                if a[j] < a[i] and f[i] < f[j] + 1 then
                    f[i] = f[j] + 1
                    g[i] = g[j] + <a[i]>
        return g[argmax f[i] from i = 1 to n]
        ```
    - $O(n^3)$
  2. **Store the transition**
     - Store the optimus previous element
     - $O(n)$ (just for the restoration)
  3. **Calculate the transition**
     - $O(n^2)$
  4. **Non-universal way**
     - $O(n)$
     - Find the previous element for which the lenght is less than 1
     - Start at the element where you found the max length and go back to the elements whose length is less than 1

---

2D problems:

## 4. Edit Distance Problem

- $f(i,j)$ : convert $s_1s_2\ldots s_i \rightarrow t_1t_2\ldots t_j$ at minimum cost
- Question: how to calculate the table?
  - $s_i = t_j \rightarrow f(i-1,j-1)$
  - $s_i \neq t_j \rightarrow f(i-1,j-1)+r$

```
EditDistance(s,t)
for i = 0 to |s| do
    for j = 0 to |t| do
        if i = 0 and j = 0 then
            f[i][j] = 0
        else
            f[i][j] = infinity
            if i > 0 then // remove
                f[i][j] = min(f[i][j], f[i-1][j] + d)
            if j > 0 then // insert
                f[i][j] = min(f[i][j], f[i][j-1] + a)
            if i > 0 and j > 0 then // replace
                z = 0
                if si != tj then
                    z = r
                f[i][j] = min(f[i][j], f[i-1][j-1] + r)
```
- Go left: insert
- Go left diagonal up: nothing changes if cost remainss equal, if cost decrements, in means we replace
- Go up: remove

## 5. Knapsack Problem

- $f(i,k)$ : max total price if only items 1 to $i$ are considered and the total weight is $k$
  - $i\in[0,n]$
  - $k\in[0,W]$
- Remember the table
- Answer is the greatest element in the last row of the table
- Either we take the current element or we don`t and take all the previous elements with same current weight $k$
- $f(0,0) = 0$, $f(0,k) = -\infty$
- $f(i,k) = \max(f(i-1, k), f(i, k))$