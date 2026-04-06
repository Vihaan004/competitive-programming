# 1. Bitmask DP

Bitmask DP typically appears when one dimension of the problem is a small set of size at most about $20$.
The general pattern is that the DP state includes a bitmask encoding which items are present/taken so far.

Typical complexities:

- $O(n \cdot 2^n)$ when the DP state is just the mask and each transition removes/adds one element.
- $O(3^n)$ when enumerating all submasks over all masks.

Problems:

- Matching (AtCoder)
- Elevator Rides (CSES)
- Grouping (AtCoder)
- Pokemon Go Go (Kattis)
- Little Pony and Harmony Chest (CF)
- Friendship Editing (USACO)

# 2. Range DP

Range DP (interval DP) is used when the natural subproblem is a contiguous interval $[l, r]$.
The state is usually something like `dp[l][r]`.

Common transitions:

- Split the interval at some point.
- Choose the first/last operation that happens inside the interval.

Typical complexity:

- Often $O(n^3)$ from trying all split points.
- Can be $O(n^2)$ if each transition is fast.

Practice:

- Removal Game (CSES)
- Mixtures (SPOJ)
- Zuma (CF)
- Greedy Pie Eaters (USACO)
