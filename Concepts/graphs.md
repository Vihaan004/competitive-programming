# Practice
- [two_buttons](../Week03/two_buttons.md)
- [checkposts](../Week11/checkposts.md)
- [news_distribution](../Week11/news_distribution.md)

Graph problems are mostly about (1) modeling correctly and (2) picking the right tool for the constraints.

A good workflow:

1. **Model** the problem as a graph.
    - What are the nodes?
    - What are the edges?
    - Directed or undirected?
    - Weighted or unweighted?
2. **Estimate constraints**.
    - Let `n` be the number of nodes and `m` the number of edges.
    - Use an adjacency list unless the graph is very dense.
    - Typical targets: $O(n+m)$, $O(m \log n)$, or $O(n^2)$ depending on constraints.

---

# 1. Modeling Patterns

Before algorithms, make sure you’re building the *right* graph.

Common modeling patterns:

- **Grid → graph**: each cell is a node; edges go to neighbors (4-dir / 8-dir); walls block edges.
- **State graph (BFS / shortest path on states)**: node = `(position, extra_state)` such as `(v, mask)` or `(v, parity)`.
- **Constraints → directed edges**: “A must come before B” becomes an edge `A -> B`.
- **Equivalence / grouping**: “in the same component” often points to DSU / BFS / DFS.

Sanity checks:

- Directed vs undirected?
- Weighted vs unweighted?
- Is `m` large (up to `2e5`)? Avoid `O(n^2)` methods.
- Are there negative weights? Dijkstra may not apply.

---

# 2. Depth-First Search (DFS)

Depth-First Search explores “as deep as possible” before backtracking.

![](https://ocw.zilin.one/assets/images/dfs_backtracking_bw_descend_nogap-6d3572deb8b5cc69c96c8b770c97751c.gif)

When to use / common patterns:

- Finding **connected components** (undirected)
- Reachability / flood fill (including grids)
- Detecting cycles (undirected): look for a back-edge to a visited node that isn’t the parent
- Building DFS orderings (e.g., SCC, or topo via DFS finish times)

Implementation notes:

- **Visited array** prevents revisits.
- **Parent tracking** helps reconstruct paths / build a DFS tree.
- **DFS tree fact (undirected graphs):** DFS defines a rooted **DFS tree** (or forest). Every edge is either a **tree edge** or a **back edge** that connects a node to one of its **ancestors**. In particular, there are no "cross edges" between different DFS subtrees in an undirected DFS.
- Watch out for **recursion depth** (especially in Python). Use an explicit stack if needed.
- If you just need reachability (either DFS or BFS works), DFS is often the quickest to code.

Complexity:

- $O(n+m)$ time, $O(n)$ memory

Example problems:

- [Counting Rooms (CSES)](https://cses.fi/problemset/task/1192)
- [Building Roads (CSES)](https://cses.fi/problemset/task/1666)

---

# 3. Breadth-First Search (BFS)

Breadth-First Search explores in increasing distance from a start node (by “levels”).

![image](https://ocw.zilin.one/assets/images/bfs_bw_samegraph-ff459b8420a67cc7900fbf9a570b5514.gif)

When to use:

- Shortest path in **unweighted graphs** (each edge cost = 1)
- Finding minimum number of moves on grids
- Multi-source shortest distances (start from many sources at once)
- Layering / level-by-level processing

Implementation notes:

- **Queue + dist array**: in an unweighted graph, the first time you visit a node means you found its shortest distance.
- **Parent array**: reconstruct the shortest path.

Complexity:

- $O(n+m)$ time, $O(n)$ memory

Example problems:

- [Message Route (CSES)](https://cses.fi/problemset/task/1667)

More practice for DFS and BFS:

- [Building Teams (CSES)](https://cses.fi/problemset/task/1668)
- [Subarray Sum Constraints (CSES)](https://cses.fi/problemset/task/3294)
- [Palindromic Paths (CF)](https://codeforces.com/group/KIrM1Owd8u/contest/632003/problem/E)
- [Third Avenue (AC)](https://atcoder.jp/contests/abc184/tasks/abc184_e)
- [Olya and Energy Drinks (CF)](https://codeforces.com/contest/877/problem/D)

---

# 4. Shortest Paths

“Shortest path” depends heavily on edge weights.

Choosing the right tool:

- **Unweighted**: BFS
- **Non-negative weights**: Dijkstra (min-heap / `priority_queue`)
- **Negative weights (no negative cycles)**: Bellman–Ford
- **All-pairs, small `n` (~500)**: Floyd–Warshall

Dijkstra (most common): works when **all edge weights are >= 0**.

- Maintain `dist[v]` = best known distance
- Use a min-heap priority queue on `(dist, node)`.
- Ignore stale heap entries (classic CP trick)

Complexity:

- Dijkstra: $O(m \log n)$ (often written as $O(m \log m)$ in push-heavy heap implementations)
- Bellman–Ford: $O(nm)$
- Floyd–Warshall: $O(n^3)$

Example problems:

- [Shortest Routes I (CSES)](https://cses.fi/problemset/task/1671) (check your Dijkstra implementation)
- [Shortest Routes II (CSES)](https://cses.fi/problemset/task/1672) (check your Floyd–Warshall implementation)
- [Shortest Routes III (CSES)](https://cses.fi/problemset/task/1673) (check your Bellman–Ford implementation)

Practice:

- [Flight Discount (CSES)](https://cses.fi/problemset/task/1195)
- [Fine Dining (USACO)](https://usaco.org/index.php?cpid=861&page=viewproblem2)

---

# 5. Topological Sort

Topological sort orders vertices of a directed acyclic graph (DAG) such that for every edge `u -> v`, `u` appears before `v`.

When to use:

- Dependencies / prerequisites
- Scheduling with ordering constraints
- Any problem that forms a DAG and asks for an order or DP over dependencies

Key properties:

- Only possible for DAGs (no directed cycles)
- Multiple valid orderings may exist
- Two standard methods:
    - **Kahn's algorithm (BFS-based):** indegree + queue
    - **DFS finish times:** reverse postorder

Cycle detection:

- Kahn: if you can’t process all nodes, there is a cycle.
- DFS: recursion-stack technique.

Complexity:

- $O(n+m)$

Example problems:

- [Course Schedule (CSES)](https://cses.fi/problemset/task/1679)
- [Commuter Pass (JOI)](https://oj.uz/problem/view/JOI18_commuter_pass) solution may be found on USACO Guide.

---

# 6. Strongly Connected Components

In a directed graph, an SCC is a maximal set of vertices where every vertex can reach every other.

When to use:

- “Mutual reachability” in directed graphs
- Compressing a directed graph into a DAG of components (condensation graph)
- 2-SAT (classic application)

Key CP patterns:

- SCC compression turns messy directed graphs into a **DAG**, enabling DP/topo solutions.
- The SCC condensation graph (SCCs as nodes, edges between SCCs) is always a DAG.
- Typical algorithms:
    - **Kosaraju:** two DFS passes (on graph and reversed graph)
    - **Tarjan:** one DFS pass with low-link values

Reference implementation:

- KACTL SCC: https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/SCC.h

Complexity:

- $O(n+m)$

Practice:

- [Planets and Kingdoms (CSES)](https://cses.fi/problemset/task/1683)
- [Coin Collector (CSES)](https://cses.fi/problemset/task/1686)
- [Grass Cownoisseur (USACO)](https://usaco.org/index.php?page=viewproblem2&cpid=516)

## 2-SAT (via SCC)

A 2-SAT instance is a CNF formula where each clause has two literals, for example:

$$(x \lor y) \land (x \lor \lnot z) \land (\lnot y \lor \lnot z)$$

Build an **implication graph**:

- For each variable $x$, create two nodes: $x$ and $\lnot x$.
- Each clause $(a \lor b)$ is equivalent to:
    - $(\lnot a \rightarrow b)$
    - $(\lnot b \rightarrow a)$

Satisfiability criterion:

- The formula is satisfiable **iff** for every variable $x$, nodes $x$ and $\lnot x$ are not in the same SCC.

Recovering an assignment (common CP rule):

- Compute SCCs and consider the SCC DAG in topological order.
- Set $x = \text{true}$ if the SCC of $x$ comes after the SCC of $\lnot x$ in the SCC DAG order.

Problems:

- [Giant Pizza (CSES)](https://cses.fi/problemset/task/1684)
- [Corporate Retreat (Rocky Mountain Regional 2025)](https://rmc25.kattis.com/contests/rmc25/problems/corporateretreat)
- [Coprime Solitaire (AtCoder ABC210 F)](https://atcoder.jp/contests/abc210/tasks/abc210_f)
- [Babysitting (Codeforces 1903F)](https://codeforces.com/contest/1903/problem/F)

---

# 7. Union-Find (Disjoint Set Union, DSU)

DSU maintains a partition of nodes into connected components under merges.

When to use:

- Connectivity under union operations
- Common use case: “How many components?” after each edge addition
- Can maintain aggregate properties per component (size, min/max, etc.)

Implementation details:

- Use **path compression** + **union by size/rank** for near-constant time.

Notes:

- Union by rank/size alone gives $O(\log n)$ per operation.
- With both union by rank/size and path compression, the amortized cost is $O(\alpha(n))$ per operation.

Reference implementation:

- KACTL DSU: https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/UnionFind.h

Complexity:

- Amortized $O(\alpha(n))$ per operation (effectively constant)

Practice:

- [Road Construction (CSES)](https://cses.fi/problemset/task/1676)
- [Graph Destruction (AtCoder ABC229 E)](https://atcoder.jp/contests/abc229/tasks/abc229_e)
- [Ada and Branches (SPOJ)](https://www.spoj.com/problems/ADABRANC/)

---

# 8. Minimum Spanning Trees (MST)

Given a connected weighted undirected graph, an MST connects all nodes with minimum total edge weight.

When to use:

- “Connect everything as cheaply as possible”
- Network design / wiring / roads problems
- Often paired with DSU or a priority queue

Two standard algorithms:

- **Kruskal:** sort edges by weight, add if it connects two different components (DSU)
    - Great when you already have an edge list and `m` is manageable.
- **Prim:** grow from a start node using a min-heap over frontier edges
    - Great for dense graphs or adjacency-based input.

Why greedy works (intuition): MST uses the **cut property**: for any cut, the lightest edge crossing it is safe to take.

Useful properties:

- **Cut property:** for any cut, one of the lightest edges crossing it belongs to an MST.
- **Cycle property:** for any cycle, an edge that is the unique maximum on that cycle is not in any MST.
- **Edge removal:** removing an edge from an MST splits it into two trees; each is an MST of its induced subgraph.

Complexity:

- Kruskal: $O(m \log m)$ (sorting dominates)
- Prim: $O(m \log n)$ with a heap

Practice:

- [Road Reparation (CSES)](https://cses.fi/problemset/task/1675)
- [Moo Network (USACO)](https://usaco.org/index.php?page=viewproblem2&cpid=1211)
- [MST Edge Cost (CSES)](https://cses.fi/problemset/task/3409)