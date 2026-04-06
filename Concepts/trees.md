# Tree Definitions and Terminology

## What is a Tree?

A **tree** is an undirected graph that is:

- **Connected** (every node can reach every other node)
- **Acyclic** (contains no cycle)

Equivalent definitions often used in problems:

- A graph with $n$ nodes is a tree iff it is connected and has $n-1$ edges.
- A graph with $n$ nodes is a tree iff it is acyclic and has $n-1$ edges.
- A graph is a tree iff between any two nodes there is exactly one simple path.

A **forest** is a collection of trees.

When a problem explicitly gives a tree, input is usually an edge list or a parent array (implies rooted).

---

## Rooted vs Unrooted Trees

The definition above is for unrooted trees. In many problems, it is useful to root the tree at a chosen node and reason with parent/child structure.

A standard contest move is to root an unrooted tree to simplify reasoning.

---

## More Tree Terminology

- **Degree**: number of incident edges to a node
- **Leaf**:
  - Unrooted tree: node with degree $1$
  - Rooted tree: node with no children
- **Parent**: unique node directly above on the path to the root (root has no parent)
- **Child**: `a` is a child of `b` if `b` is `a`'s parent
- **Ancestor/Descendant**: `a` is an ancestor of `b` iff `a` lies on the path from `b` to the root; descendant is the reverse relation
- **Depth** (rooted): distance from root in edges
- **Height** (rooted): maximum depth in the tree
- **Subtree of v** (rooted): `v` plus all descendants of `v`
- **Diameter**: longest distance between any two nodes

In most tree problems, DFS from the root is a standard traversal.

Starter problems:

- [Subordinates (CSES)](https://cses.fi/problemset/task/1674)
- [Cowntagion (USACO)](https://usaco.org/index.php?page=viewproblem2&cpid=1062)

---

# Tree DP (Dynamic Programming on Trees)

## General Pattern

Most simple tree DPs follow this flow:

- Pick a root (or use the given root)
- Solve each subtree
- Combine child answers at the parent
- Often store multiple DP values per node and combine efficiently for parent transitions

Why it works:

- Subtrees do not overlap, so child-to-parent transitions are clean.

Problems:

- [Independent Set (AtCoder)](https://atcoder.jp/contests/dp/tasks/dp_p)
- [Appleman and Tree (CF)](https://codeforces.com/problemset/problem/461/B)
- [Tree Diameter (CSES)](https://cses.fi/problemset/task/1131)
- [Tree Distances 1 (CSES)](https://cses.fi/problemset/task/1132)

Rerooting DP:

- [Tree Distances 2 (CSES)](https://cses.fi/problemset/task/1133)
- [V-Subtree (AtCoder)](https://atcoder.jp/contests/dp/tasks/dp_v)

---

# Binary Jumping / Sparse Table

## Binary Jumping

Start with:

- [Company Queries I (CSES)](https://cses.fi/problemset/task/1687)

Precompute jump pointers to move up by powers of two:

- $2^0 = 1$ step
- $2^1 = 2$ steps
- $2^2 = 4$ steps
- $2^3 = 8$ steps
- and so on

Then any jump of $k$ steps can be decomposed by binary representation.

This idea also applies beyond trees whenever each state has a single next pointer.

- [Tree Queries (CF)](https://codeforces.com/problemset/problem/1328/E)
- [Tractor Paths (USACO)](https://usaco.org/index.php?page=viewproblem2&cpid=1284)

---

## LCA

In a rooted tree, the **Lowest Common Ancestor (LCA)** of nodes `u` and `v` is the deepest node that is an ancestor of both.

Try applying binary-jumping ideas to:

- [Company Queries II (CSES)](https://cses.fi/problemset/task/1688)
- [Distance Queries (CSES)](https://cses.fi/problemset/task/1135)

---

## Sparse Table

Suppose we need static range minimum queries on an array (no updates). Segment tree gives $O(\log n)$ per query, but sparse table can do better.

For each position `x` and each $k = 0, 1, \dots, \lfloor \log_2 n \rfloor$, precompute minimum on interval:

$$
[x, x + 2^k - 1].
$$

To query RMQ on $[a, b]$ in $O(1)$, let $2^m$ be the largest power of two with $2^m \le b-a+1$.
Then:

$$
\min[a,b] = \min\big(\min[a, a+2^m-1],\ \min[b-2^m+1, b]\big).
$$

This works because taking minimum over overlapping blocks is valid.

Question: can this structure be used to answer LCA in $O(1)$ instead of $O(\log n)$ (via Euler tour + RMQ)?

---

# More Tree Queries

## Tree Flattening

We can flatten a tree with DFS and record timing/visit information (for example, in-times and out-times).

Problems:

- [Subtree Queries (CSES)](https://cses.fi/problemset/task/1137)
- [Path Queries (CSES)](https://cses.fi/problemset/task/1138)
- [Distinct Colors (CSES)](https://cses.fi/problemset/task/1139)

Useful flattening variants include:

- Record in-time only
- Record both in-time and out-time
- Record every DFS visit (Euler tour)

Question: which variation is useful for making LCA work in $O(1)$?

- [Tree Requests (CF)](https://codeforces.com/problemset/problem/570/D)
