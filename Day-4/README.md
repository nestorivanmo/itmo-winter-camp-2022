# Day 4: Graph Theory

- Graph: structure with vertices and edges: $V$, $E$
  - Directed
  - Undirected
- Connected Component
  - Subgraph from which you can go from one vertex to any other vertex
- Tree
  - Connected graph with $n$ vertices and $n-1$ edges

## Graph Storage 

- **Adjacency matrix**
  - $M_{n\times n}$ matrix where $M_{ij}=1$ if there is an edge between node $i$ and node $j$, otherwise, $M_{ij}=0$
  - Check if $i$ and $j$ have an edge: $O(1)$
  - Check for all neighbors of $v$: $O(n)$
  - Memory space: $O(n^2)$
- **Adjacency list**
  - List of size $n$ where each element is a list that contains the neighbors of node $i$
  - Check if $i$ and $j$ have an edge: $O(n)$
  - Check for all neighbors of $v$: $O(1)$
  - Memory space: $O(n+m)$

## Depth First Search (DFS)
- Generates a spanning tree of the graph $G$
- Time complexity: $O(n+m)$
```
dfs(v)
    if was[v]
        return
    was[v] = true
    for u in neigbors of v
        dfs(u)
```
- Count number of connected components:
  ```
  was = bool[n]
  cc = 0
  for i in 1..n
    if !was[i]
        dfs(i)
        cc++
  ```

## Finding cycles
- Color:
  - 0: haven't visited yet
  - 1: visited
  - 2: exited
```
color = int [n]
dfs(v, p):
    if color[v] = 1
        found a cycle
    if color[v] = 2
        return
    color[v] = 1
    for u in neighbors of v
        if u != p
            dfs(u, v)
    color[v] = 2
```

## Topological Sort
- Applied on a DAG
```
ans = []
was = bool[n]
topsort(v)
    was[v] = true
    for u in neighbors of v
        if !was[u]
            topsort(u)
    ans.add(u)
for i in 1..n
    if !was[i]
        topsort(i)
reverse(ans)
```
## Eulerian cycle/path

- Condition for eulerian cycle: all vertices with even degree

