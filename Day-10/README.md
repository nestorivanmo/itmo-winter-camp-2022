# Day 10 - Suffix Array

- Given string $S$, find all of its suffixes and sort them
- a b a b b a c b <- string S
- 0 1 2 3 4 5 6 7

| Suffix | Index |
| ------ | ----- |
| ababbacb | 0 | 
| abbacb | 2 |
| acb | 5 |
| b | 7 |
| babbacb | 1 |
| bacb | 4 |
| bbacb | 3 |
| cb | 6 |

## First approach: hashes for string S

- Time complexity: 
  - Sorting: $O(n \log n)$
  - Suffixex: $O(n^2)$

- How to optimize it?
  - Cyclic shifts
    - Read string S: ababc
    - Start from some character $i$, go to the end and continue in the beginning until reaching $i$ again
      - starting from $3$: bcaba

    - There are $n$ cyclic shifts of $S$

  - Add one additional character $ to $S$ so that the order of cyclic shifts will be the same as the lexicographical order
  - Sort cyclic shifts
    - Assign a number to each character
    - Build pairs of numbers and store its position
    - Sort pairs