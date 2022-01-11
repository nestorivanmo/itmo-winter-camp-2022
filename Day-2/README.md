# Day 2: Sorting and binary search

## Insertion sort
- On $k$-th iteration, first $k$ elements are already sorted
- Find place for $k+1$ element
- After $n$ iterations, array is sorted

```
for i = 1 to n-1
    j = 1
    while j > 0 and a[j-1] > a[j]
        swap(a[j-1], a[j])
        j--
```

- Time complexity: $O(n^2)$

---

## Merge sort
- "You don't have to sort an array if it has length one" meme
- If we ccan merge two sorted arrays in one for linear time
- Divide and conquer
  - Split array on two equal parts
  - Use recursion to sort them
  - Merge into one
```
merge(a,b)
    n = |a|
    m = |b|
    i = 0
    j = 0
    while i + j < n + m
        if j == m or (i < n and a[i] < b[j])
            c[i+j] = a[i]
            i++
        else
            c[i+j] = b[j]
            j++
    return c

merge_sort(a)
    n = |a|
    if n == 1
        return a
    l = a[0..n/2-1]
    r = a[n/2..n-1]
    merge_sort(l)
    merge_sort(r)
    return merge(l, r)
```
- Time complexity: $O(n \log n)$ guaranteed for any array
- Takes additional space
- Stable sort: order of values in input remains the same, after sorting, in the output
 
### Count number of inversions using Merge sort
- Inversion: $(i,j) : a[i] > a[j]$ and $i<j$
  - $[1,3,2,4,3,1]$
  - Inversions: $3,2$ | $4,3$ | $1,3$ | $3,1$ | $2,1$ | 
- Naive approach: $O(n^2)$
- Merge sort approach

  - All elements in the left part of the array that are greater than any element of the right array will be counted as inversions
  - $[1,3,2]$ ---- $[4,3,1]$
  - $[1,2,3]$ ---- $[1,3,4]$: merge these two arrays
  - ```ans += n-i```

---

## Counting sort
- Given integer array with size $n$
- Count number of ocurrences of each integer
- Write that integer the number of ocurrences it appear
```
for i = 0 to n-1
    cnt[a[i]]++
i = 0
for j = 0 to m-1
    while cnt[j] > 0
        a[i++] = j
        cnt[j]--
```

- Time complexity: $O(n+m)$
  - $n$: size of integer array
  - $m$: size of counter array
  - If $n\approx m$ then $O(n)$
- Stable sort

### Anagrams using counting sort
- Check if one word is anagram of another
- ```cnt[a[i]-'a']++```
- Two ```cnt``` arrays: one for each word
- If both ```cnt``` arrays are equal, then words are anagram of each other

### Sorting negative numbers with counting sort
- Add ```m``` for each element in the original array
  - $0 \leq a_i \leq 2m$
- $O(n+2m) = O(n+m)$

### Sorting big numbers $10^{12}$ using counting sort
- Substract $m$ for each element in the original array
- ```cnt[a[i]-m]```

### Sorting tuples by small key using counting sort
- Find ranges for each key
```
for i = 0 to n-1
    cnt[a[i].first]++
p[0] = 0
for i = 1 to m-1
    p[i] = p[i-1] + cnt[i-1]

for i = 0 to n-1
    a[p[a[i].first]++] = a[i]
```
- $[(1,1), (1,2), (2,1), (3,1), (2,2), (1,3)]$
- ```cnt = [0|3|2|1]```
- ```p = [0|0|3|5]```

---

## Search problems
- Given an array:
  - Is there an element equal to $x$?
  - Minimal element not less than $x$
  - How many entries of $x$?
- How can we answer this questions in less than linear time?
  - If the array isn't sorted, **faster is impossible**
  - If the array is sorted: **Binary search**

## Binary Search
- Given a sorted array (we can sorted it first)
- Check if it contains number $x$:
  - Look at the middle:
    - Middle = x
    - Middle < x
    - Middle > x
- Complexity: $O(\log n)$
  - Because in order to divide an array of length $n$ until $1$, it takes logarithm base 2 steps
- Why binary search sometimes isn't better than linear search?
  1. Unsorted array I: find $x$ one time
     1. Linear: $O(n)$
     2. Binary search: $O(n\log n + \log n)$ = $O(\log n)$ which is worse than linear

  2. Unsorted array II: find $x$, $m$ times
     1. Linear: $O(m+n)$
     2. Binary search: $O(n\log n + m \log n)$

```
bin_search(l, r, x)
    if l == r-1
        return (a[l] == x)
    m = (l+r) / 2
    if x == a[m]
        return True
    if x < a[m]
        return bin_search(l, m, x)
    else
        return bin_search(m, r, x)
```

### Lower bound and upper bound
- Want more information?
- Lower bound: minimal $i$ such that $a[i] \geq x$
  - Invariant: $a[l] \leq x < a[r]$
  ```
  lower_bound(l,r,x)
    if l == r-1
        return l
    m = (l+r) / 2
    if x <= a[m]
        return lower_bound(l, m+1, x)
    else
        return lower_bound(m+1, r, x)
    else
  ```
- Upper bound: minimal $i$ such that $a[i] > x$
- ```upper_bound(x) = lower_bound(x+1)```
  ```
  upper_bound(l,r,x)
    if l == r-1
        return l
    m = (l+r) / 2
    if x < a[m]
        return lower_bound(l, m+1, x)
    else
        return lower_bound(m+1, r, x)
    else
  ```

- Other lower bound with better invariant
- Invariant: $a[l] < x \leq a[r]$
  - Default true
  - Never use $a[-1]$ or $a[n]$
  - Call as ```lower_bound(-1, n, x)```

### Number of entries
- $\forall i \in[\text{lower\_bound(x)}, \text{upper\_bound(x))}$
- Missing info

### Binary search on real values
- B.S. on functions
- Find some $x$ such that $f(x)=0$ or any value $y$: $f(x) = y$
- Constrains for function?
  - Function should be monotonic (may not strictly)
  - $f(l) \leq 0$ and $f(r) \geq 0$
```
bin_search(l ,r)
    while r-l > EPS // for real numbers, eps = 10-5 approx
        m = (l+r)/2
        if f(m) < 0
            l = m
        else
            r = m
    return r
```
- Using ```while``` in a computer program, it's a bad idea, use ```for``` because we can be sure that it will end, but the ```while``` we can't be sure it will end or how many iterations in will take

### Binary search by answer

- Advanced use of BS
- Example:
  - Have n points on line
  - Need to choose k such that minimal distance between them would be maximal
  - Answer: find function
  - ```is_it_possible_to_choosse_k_points_with_at_least__d_distance(d)```
  - if $d$ is very big: impossible
  - Use BS to find parameter $d$
