# 1. Strongly Connected Components

In a directed graph, an SCC is a maximal set of vertices where every vertex can reach every other.
If you compress each SCC into one node, the resulting graph is a DAG.

Turning directed graphs into DAGs enables techniques like DP and topological sorting.

Algorithms for SCC decomposition:

- Kosaraju: two DFS passes (on graph and reversed graph)
- Tarjan: one DFS pass with low-link values

For SCC and 2-SAT, you can check KACTL implementations.

Complexity:

- $O(n + m)$

Practice:

- Planets and Kingdoms (CSES)
- Coin Collector (CSES)
- Grass Cownoisseur (USACO)

# 2. 2-SAT

A 2-SAT instance in CNF is a conjunction of clauses, each clause being an OR of two literals.

Example:

Determine whether there is an assignment of truth values to $x$, $y$, and $z$ such that:

$$
(x \lor y) \land (x \lor \neg z) \land (\neg y \lor \neg z)
$$

is true.

Transformation idea:

- Build an implication graph.
- For each variable, create two nodes: variable and its negation.
- For variables $x,y,z$, nodes are: $x, \neg x, y, \neg y, z, \neg z$.

Clause conversion:

- Clause $(x \lor y)$ is equivalent to $(\neg x \to y)$ and $(\neg y \to x)$.
- Add both directed implications for each clause.

Unsatisfiability condition:

- If for some variable $x$, both $x \to \neg x$ and $\neg x \to x$ are implied (via paths), then the instance is unsatisfiable.
- Equivalently in SCC terms: a variable and its negation cannot be in the same SCC.

Problems:

- Giant Pizza (CSES)
- Corporate Retreat (Rocky Mountain Regional 2025)
- Coprime Solitaire (AtCoder)
- Babysitting (CF)

# 3. Union-Find (Disjoint Set Union, DSU)

DSU maintains a partition of nodes into connected components under merge operations.

- KACTL implementation is a good reference.
- Union by rank/size alone gives $O(\log n)$.
- With path compression too, operations are near-constant amortized time: $O(\alpha(n))$.

Practice:

- Road Construction (CSES)
- Graph Destruction (AtCoder)
- Ada and Branches (SPOJ)

# 4. Minimum Spanning Trees (MST)

Given a connected weighted undirected graph, an MST connects all nodes with minimum total edge weight.

Cut property:

- For any cut, one of the lightest crossing edges must be in an MST.
- Taking any of the lightest crossing edges is safe.

Other properties:

- Cycle property: if an edge is the unique maximum on a cycle, it is in no MST.
- Edge removal: removing an edge from an MST yields two trees that are MSTs of their respective induced subgraphs.

Standard algorithms:

- Kruskal: process edges in increasing weight; add if endpoints are in different components (use DSU).
- Prim: start from one node and repeatedly add the lightest edge from current tree to an outside vertex (use heap).

Question to prove:

- Can you use the cut property to prove correctness of both algorithms?

Complexity:

- Kruskal: $O(m \log m)$ (sorting dominates)
- Prim: $O(m \log n)$ with heap

Practice:

- Road Reparation (CSES)
- Moo Network (USACO)
- MST Edge Cost
