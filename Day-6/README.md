# Day 6: String Algorithms

- Most common problem: **search**
  - Text $s$ of length $n$
  - Pattern $t$ of length $k$

## Naive algorithm (slow)

- $n=8, k=3$
- Starting places for pattern: $5 \rightarrow (n-k+1)$

```
for st = 0..n-k
    ok = true
    for i=0..k-1
        if s[st+i] != t[i]
            ok = false
    if ok
        print(st)
```

- $O(n-k+1)$
- If $k$ is small, then $n-k+1$ is small and we can use this naive implementation
- The worst case is when $k\approx \frac{n}{2}$

## Algorithms to solve Search problem in linear time

- **Prefix function, Knuth-Morris-Pratt algorithm (KMP)**
- **Z-Function**
- **Hashing (polynomial)**

### Prefix Function

- Given a text and a pattern:
  - $\pi[i]$ is the longest prefix of pattern that ends at $i$ and is not equal to the entire prefix from $0\ldots i$

1. Build $\pi$ array for pattern
2. Do something with $\pi$

- Examples:
  - ```p = "abac"```
  - $\pi = [0,0,1,0]$

  - ```p = "abacaba"```
  - $\pi = [0,0,1,0,0,1,2,3]$
  - $\pi[i] = x$ means that there are $x$ values with prefix and suffix that are the same
  
**Important observations**
1. $\pi[i+1] \leq \pi[i]+1$
2. $\pi[i]$ equals the max length $x$ such that $p[0\ldots x-1] = p[i-x+1\ldots i]$
3. Set of all prefixes that match the suffixes:
   1. Largest: $\pi[i]$
   2. 2nd largest: $\pi[\pi[i]-1]$
   3. 3rd largest: $\pi[\pi[\pi[i]-1]-1]$
   4. $\vdots$

```
x = pi[i-1]
if match
    x++
else
    try smaller prefix
```

```
while not match
    x = pi[x-1]
    if match
        x++
    pi[i] = x
```

#### How do we apply it for searching?

- Calculate the prefix function between pattern $p$ and large text $s$ by inserting one character such that $p\#s$. We concatenate a special character between both strings
- If $\pi[i] = k$ it means we have an ocurrence that ends at $i$ where $k$ is the length of the pattern $p$

- Time complexity: $O(n)$

---

### Z-function

- $z[i]$: longest string that starts at $i$ and equals prefix

**Example**:
  - ```"abaabaa"```
  - $z[0]=0$
  - $z = [0,0,1,4,0,1,1]$
  - $z[3]=4$ because the starting string at $3$ is ```"abaa"``` and the prefix before position $3$ is also ```"abaa"```

- We also concatenate a special character: $p\#s$
- Everytime we find $k$ in the concatenated string, we have found an occurrence
- $O(n)$

#### How to calculate the Z-function?

- We need to know the entire string in advance - **offline algorithm**
- We also need a $Z-$block: some substring that starts at index $l$ and goes to $l+z[l]$ -> $[l,l+z[l])$. $l$ such that $l+z[l]$ is the maximum
  
1. Consider $z[i-l]$
2. Two cases
   1. Inside big block $[l,l+z[l])$
   2. Outside big block, so we need to extend

---

### Hashing (Polynomial)

- Way to map strings to numbers
- $s=t \rightarrow h(s) = h(t)$
- If $h(s) = h(t)$ does not mean $s=t$
- Polynomial Hashing $h(s)$:
  - $s_0,s_1, \ldots, s_{n-1}$
  - $p$ which is a base
  - $h(s)=\sum_{i=0}^{n-1}s_i*p^{n-1-i}$

- Hashing helps us to compare strings quickly
