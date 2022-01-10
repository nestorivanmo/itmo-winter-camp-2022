# Day 1 - Introduction

## Judging system

- For each test, you have a time and memory limit
- Time limit is the CPU clock, not clock time
- Multi thread programs does not give any advantage since Codeforces add up all the time in each thread
- In real life, real time matters and not CPU time
- Competitive programming is about more squeezing time limit rather than time limit
- Time in computer $\neq$ Time in judge system

---

## Verdicts

- Time Limit Exceeded: on some test cases, the program consumed more time than it was given
- Runtime Error: sth. that happens when the program runs and does not finish well ('crash')
  - Memory that is not accessible, Null pointer exception, Divide by zero exception, etc ...
- Compilation Error: happens before running on any test case
- Wrong Answer: program runs smoothly but did not output the correct answer. This is the most common verdict

---

## How to measure algorithm complexity ?

- O notation
- Time complexity is a function where given the size of input, it will give the maximum number of operations the program does
- $T(n)$ where n is the size of the input
- The idea is to measure program's complexity without depending the architecture the program is being run on
- We only consider how $T(n)$ grows depending on $n$

### Problem F-ABC First Day Contest

- For problem **F**: $T(n) \approx 15 * n * n * n + n + 3 \leq 16 * n * n * n = O(n^3)$ (we get rid of constant factors since the program does not run faster than $n^3$
- $T(n) \geq$ ($n$ choose $3$) $\geq n * (n-1) * (n-2) / 6 = \frac{1}{6} * (n^3 - 3*n^2 + 2n) \geq n^3 * \frac{1}{7}$
- $\frac{1}{7}(n^2 -3n + 2) \geq 0$
- $T(n)$ grows at least what $n^3$ grows, $T(n) = \Omega(n^3)$
- Problem statement: $n = 10^{5}$

- Measure time in terminal: ```time ./A < A.in``` or ```cerr << ((double) clock() - start) / CLOCKS_PER_SEC << endl;```
s

--- 
## Recursive algorithms
- C++ optimizer will optimize this code:

```
mul(recursiveFunction(a,b,c), recursiveFunction(a,b,c))
```

so that it only calls ```recursiveFunction(a,b,c)``` once instead of twice.

- Think of recursive calls as a stack. Everytime a recursive function is called, it is stored in the stack

---

## Debugging

1. Using debuggers included in IDE's
   - Disadvantage: takes a lot of time
2. Debug output: simulate IDE's debugging using ```cerr```
   - Advantage: all the information is on screen
3. Make assertions
   - ```assert(s[pa] == 'a' && s[pb] == 'b' && s[pc] == 'c')```

- Debug output is the preferred option
- If we don't know the test cases:
  - We can run our algorithm with created test cases and compare answers
  
  ```
    while (true) {
        int a = rand() % 10 + 1;
        int b = rand() % 10 + 2;
        int c = rand() % 10 + 3;
        int ans1 = f(a,b,c);
        int ans2 = g(a,b,c);
        if (ans1 != ans2) {
            cout << "Bad\n" << ans1 << ' ' << ans2 << endl;
            cout << a << ' ' << b << ' ' << m << endl;
            return 0;
        }
    }
  ```
  - If the answer is not equal, identify where the mistake is an run debug output in the incorrect function
  