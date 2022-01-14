# Day 5: Single Source Shortest Paths

- Algorithm to solve this problem: BFS

## BFS 
- Start with vertex $s$. All of its neighborss have distance $1$
```
d = [infinity] // distance array
bfs(v)
    queue add v
    d[v] = 0
    while queue is not empty
        u = front of the queue
        queue.pop()
        for w in neighbors of u
            if d[w] = infinity
                d[w] = d[u] + 1
                insert w into the queue
```
- Time complexity: $O(n+m)$
  - For adjacency matrix: $O(n^2)$
  - For adjacency list: $O(n+m)$

---

- Suppose an undirected graph $G$ with weight $0$ or $1$ on its edges
- We want to solve the problem in $O(n+m)$ time
- For each neighbor of node $u$
  - Either edge weight is $0$: distance is the same as $u$
  - Or $1$: distance is $d[u]+1$
- For this, we should use a ```deque``` data structure instead of a ```queue``` in order to insert vertices with weight $0$ to the left of the curr. node and vertices with weight $1$ to the right
```
d = [infinity] // distance array
bfs(v)
    queue add v // NOW USING A DEQUE
    d[v] = 0
    while queue is not empty
        u = queue.pop_front() // left 
        for w in neighbors of u
            if d[w] > d[u] + weight of edge uw
                d[w] = d[u] + weight of edge uw
                if weight of edge uw = 0
                    add w to the front of the queue
                else 
                    add w to the back of the queue
```
- Each node can appear at the front or the back
- Time complexity: $O(2n+m)$
- **0-1BFS algorithm**:
```
d = [infinity] // distance array
visited = [false] // visited array
bfs(v)
    queue add v // NOW USING A DEQUE
    d[v] = 0
    while queue is not empty
        u = queue.pop_front() // left
        if visited[u] continue
        visited[u] = true
        for w in neighbors of u
            if d[w] > d[u] + weight of edge uw
                d[w] = d[u] + weight of edge uw
                if weight of edge uw = 0
                    add w to the front of the queue
                else 
                    add w to the back of the queue
```

---
- Now suppose we can have any weight
- queue: $d[u] = i$
- queue: $d[u] = i+1$
- $\vdots$
- queue: $d[u] = i+k$
- Put node $w$ in the corresponding queue
```
d = [infinity] // distance array
visited = [false] // visited array
bfs(v)
    queue add v // NOW USING A DEQUE
    d[v] = 0
    while queue is not empty
        u = queue.pop_front() // left
        if visited[u] continue
        visited[u] = true
        for w in neighbors of u
            if d[w] > d[u] + weight of edge uw
                d[w] = d[u] + weight of edge uw
                queue[d[w]].add(w)
```
- Time complexity: $O(nk + m)$

---

## Dijkstra's algorithm
- Suppose each weight is non-negative -> **Dijkstra**
- We want to find the next node which will have the smallest distance to S (subgraph of G) using only one edge
```
d = [infinity] // distance array
visited = [false]
d[v] = 0
for i in 1..n 
    u = argmin of d[w] with visited[w] = false
    visited[u] = true
    for w in neighbors of u
        if d[w] > d[u] + edge weight of uw
            update edge uw to d[u] + edge weight of uw
```
- ```argmin```
```
min v = -1
for i in 1..n
    if visited[i] = false && (min v == -1 || d[min v] > d[i])
        min v = i
```
- ```update```
```
d[w] = d[u] + uw.weight
```

- Time complexity: $O(n^2 + m) = O(n^2)$
- If we use a better DS to perform ```argmin``` then: $O(m \log n)$

---

## Bellman-Ford's algorithm

- Now, we can have edges with negative weight
- ```dp[k][v]``` is the shortest path to vertex ```v``` with number of edges less than or equal to ```k```
```
dp[0] = {infinity,..., infinity}
dp[0][S] = 0
for it in 1..n-1
    dp[it] = dp[it-1]
    for v in V
        for uv in E
            dp[it][u] = min(dp[it][u], dp[it-1][v]+uv.weight)
```
- Relaxed way:
```
dp[0] = {infinity,..., infinity}
dp[0][S] = 0
for k in 1..n-1
    for v in V
        for uv in E
            dp[u] = min(dp[u], dp[v]+uv.weight)
```

---

## All Pairs Shortest Paths: Floyd Warshall algorithm
