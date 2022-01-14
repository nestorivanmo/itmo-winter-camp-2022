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