# Practice
- [consecutive_subsequence](../Week04/consecutive_subsequence.md)
- [long_jumps](../Week04/long_jumps.md)
- [six_seven](../Week04/six_seven.md)
- [yarik_and_array](../Week04/yarik_and_array.md)
- [cut_ribbon](../Week12/cut_ribbon.md)
- [the_sports_festival](../Week12/the_sports_festival.md)

Dynamic Programming (DP) is about turning a brute force ("try all choices") into a polynomial solution by **reusing overlapping subproblems** and storing intermediate calculations.

# 0. Starter Problems

Before diving into definitions, here are two “toy” problems that show what DP feels like.

## 0.1 Staircase Ways

You are at step $0$ and want to reach step $n$. Each move you can climb **1**, **2**, or **3** steps. How many distinct ways are there to climb up the staircase?

State idea:

- `dp[i]` = number of ways to reach step `i`.

Transition:

- To reach `i`, your last jump was `+1`, `+2`, or `+3`.

```cpp
dp[0] = 1
dp[1] = dp[0] = 1
dp[2] = dp[1] + dp[0] = 2
dp[i] = dp[i-1] + dp[i-2] + dp[i-3]   (for i >= 3)
```

Answer:

- `dp[n]`

---

## 0.2 Minimum Cost to Climb Stairs (1, 2, or 3 steps)

Same staircase rules (move **1**, **2**, or **3** steps), but each step `i` has a positive cost `c[i]` paid when you land on it. Find the minimum total cost to reach the top.

State idea:

- `dp[i]` = minimum total cost to land on step `i`.

Transition:

- To land on `i`, you came from `i-1`, `i-2`, or `i-3`, then pay `c[i]`.

```
dp[0] = c[0]
dp[1] = c[1]
dp[2] = c[2]
dp[i] = min(dp[i-1], dp[i-2], dp[i-3]) + c[i]   (for i >= 3)
```

Answer:

- If reaching the “top” means you can finish from step `n-1`, `n-2`, or `n-3` without paying extra:

```
answer = min(dp[n-1], dp[n-2], dp[n-3])
```

---

### Similar examples

- [Dice Combinations (CSES)](https://cses.fi/problemset/task/1633)
- [Minimizing Coins (CSES)](https://cses.fi/problemset/task/1634)
- [Grid 1 (AC)](https://atcoder.jp/contests/dp/tasks/dp_h)

# 1. DP Mindset and Key Definitions

Dynamic programming is fundamentally about recurrence: we express the solution to a problem in terms of solutions to smaller instances of the same problem. In many problems, the same smaller instances arise repeatedly across different branches of the recursion, creating overlapping subproblems. Memoization (or bottom-up tabulation) avoids recomputing these repeated subproblems by storing their answers the first time they are computed and reusing them whenever needed.

Core pieces:

- **State**: `dp[state]` stores the answer for that subproblem.
- **Base cases**: smallest states you already know.
- **Transition**: compute `dp[state]` from previously computed states.
- **Answer**: usually `dp[final_state]` (or max/min over a set of states).

Two common implementation styles:

- **Top-down (memoized DFS)**: easy to write, must avoid recursion depth issues in Python, can TLE due to recursion being slower in general.
- **Bottom-up**: explicit order, often faster/safe, more common approach.

Sanity checks:

- Does your dp have a valid ordering? Does each case only reference smaller cases?
- Are you initializing your base cases?

# 2. DP Type: Counting vs Optimality

A quick (and useful) mental split for most dynamic programming related problems:

- **Optimality DP**: each state stores a **best** value (max/min).
    - Think: “What’s the best I can do from here?”
    - Transitions usually use `max(...)` / `min(...)`.
    - Common extras: reconstruction via parent pointers, handling `inf/+inf`, tie-breaking.
- **Counting DP**: each state stores a **number of ways**.
    - Think: “How many ways can I get here / finish from here?”
    - Transitions usually **sum** contributions from previous states.
    - Common extras: modulo arithmetic, avoiding double-counting (ordered vs unordered), base cases are often "1 way" not "0 cost".

Sanity checks by type:

- **Optimality**: Are you initializing unreachable states to `inf/+inf` correctly?
- **Counting**: Are you counting each object exactly once? Are you applying `mod` consistently?

---

A good workflow:

1. **Define the state**.
    - What information do you need to uniquely describe a subproblem?
2. **Write the transition**.
    - Which states do you need to transition to in order to ensure you have solved your current state?
    - Ensure every transition is correct and covers all cases.
3. **Decide the order**.
    - Increasing length, increasing index, topological order, etc.
4. **Check complexity**.
    - State count × transitions per state.

---

# 3. Classical DP Examples

## 3.1 Maximum Subarray Sum (Kadane)

Goal: maximum sum over all contiguous subarrays.

State idea:

- `best_end[i]` = max subarray sum that **must end at** `i`.

Transition:

- Either extend the previous subarray or start fresh at `i`.

```python
best_end[i] = max(a[i], best_end[i-1] + a[i])
answer = max over i of best_end[i]
```

- [Maximum Subarray Sum (CSES)](https://cses.fi/problemset/task/1643)
- [Reverse Subarray Sum (Hacker Devils X Soda Code Challenge XI)]
    - Given an array of 105 integers on the range [−109,109], first you may pick some subarray of the given array and reverse it. Then, you pick any subarray and sum its elements. Find the maximum possible value of this sum.

---

## 3.2 Knapsack

You have `n` items. Item `i` has weight `w[i]` and value `v[i]`. You have capacity `W`. Choose a subset of items with total weight $\le W$ that maximizes total value.

Constraints:

- `n < 10^3`
- `W, w[i] < 10^4`

---

### Solution

Define:

- `dp[i][j]` = maximum total value using the first `i` items with total weight exactly `j`.

Transition (for item `i`, 1-indexed in this definition):

- Do not take item `i`:
    - `dp[i][j] = dp[i-1][j]`
- Take item `i` (only if `j >= w[i]`):
    - `dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i])`

Base cases:

- `dp[0][0] = 0`
- `dp[0][j] = -inf` for `j > 0`

---

While the formal phrasing uses 2D DP, knapsack is often implemented with 1D DP.

Define:

- `dp[j]` = maximum value achievable with total weight exactly `j`.

Update for each item `i` (iterate `j` in **reverse**):

```
for j = W down to w[i]:
	dp[j] = max(dp[j], dp[j - w[i]] + v[i])
```

This reverse iteration prevents using the same item multiple times.

---

### Related Problems

- [Book Shop (CSES)](https://cses.fi/problemset/task/1158)
- [Two Sets II (CSES)](https://cses.fi/problemset/task/1093)

---

## 3.3 Longest Increasing Subsequence

**Problem:** Given an array `a[0..n-1]`, find the maximum length of a **strictly increasing** subsequence (not necessarily contiguous).

---

### Approach 1: Classic $O(n^2)$ DP

**State:**

- `dp[i]` = length of the longest increasing subsequence that **ends at** index `i`.

**Transition:**

- For each `i`, look at all `j < i` with `a[j] < a[i]`:
    - `dp[i] = max(dp[i], dp[j] + 1)`
- If no such `j` exists, then `dp[i] = 1`.

**Base case:**

- Initialize all `dp[i] = 1`.

**Answer:**

- `max(dp[i])`

**Complexity:**

- Time: `O(n^2)`
- Memory: `O(n)`

**Reconstruction (optional):**

- Store `parent[i]` and backtrack from the index with the maximum `dp[i]`.

---

### Approach 2: $O(n \log n)$ tails method

This method computes the **length** of the LIS efficiently (and can be extended to reconstruct the sequence).

**Key idea:**

- Maintain an array `tails` where `tails[k]` is the **smallest possible ending value** of an increasing subsequence of length `k+1` seen so far.

**Update rule for each value `x`:**

- Find the smallest index `p` such that `tails[p] >= x` (lower bound).
- If such `p` exists, set `tails[p] = x`.
- Otherwise, append `x` to `tails`.

**Answer:**

- `len(tails)`

**Complexity:**

- Time: `O(n log n)`
- Memory: `O(n)`

**Strict vs nondecreasing detail:**

- Strictly increasing: use first `>= x`.
- Nondecreasing: use first `> x`.

**Reconstruction (optional):**

- Track indices and `parent[i]` pointers for backtracking.

---

### Related problems

- [Increasing Subsequence (CSES)](https://cses.fi/problemset/task/1145)
- [Mysterious Present (CF)](https://codeforces.com/problemset/problem/4/D)
- [Candy Machine (Baltic IOI)](https://dmoj.ca/problem/btoi09p2)

---

### More DP problems

- [Leaping Tak (AC)](https://atcoder.jp/contests/abc179/tasks/abc179_d)
- [Jump Game (LC)](https://leetcode.com/problems/jump-game-vi/description/)
- [Antimatter (CF)](https://codeforces.com/problemset/problem/383/D)

A good source of DP problems to begin with can be found on [USACO Guide](https://usaco.guide/gold/intro-dp?lang=cpp).

They also link to this beginner friendly [contest](https://codeforces.com/gym/100135).


# Advanced Dynamic Programming Techniques

## 1. Bitmask DP

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

## 2. Range DP

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