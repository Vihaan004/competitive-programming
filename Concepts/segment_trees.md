# Segment Tree

The segment tree is one of the most versatile tools in competitive programming. It helps answer range queries efficiently while supporting updates.

Canonical problem:

- [Dynamic Range Sum Queries (CSES)](https://cses.fi/problemset/task/1648)

Suppose we are given an array $a_1, a_2, \dots, a_n$ and must process two types of operations:

- **Point update**: change one element $a_i$.
- **Range query**: compute an aggregate (such as sum or minimum) over a subarray $[l, r]$.

A naive range query takes $O(n)$ time, since we may scan every element between $l$ and $r$. With $q$ queries, this can become $O(nq)$, which is too slow for large inputs.

The key idea is that **range queries can be decomposed into smaller precomputed segments**. We build a binary tree over the array:

- Leaves represent individual array elements.
- Each internal node represents a contiguous interval.
- Each node stores the aggregate value of its interval.

This gives overall complexity:

$$
O(n + q \log n)
$$

with each query/update taking $O(\log n)$.

---

This method works for any associative operation, not just sum.

- [Dynamic Range Minimum Queries (CSES)](https://cses.fi/problemset/task/1649)

Segment trees are also useful in some static-query settings (even when updates are not required), though for specific operations there may be better specialized structures. For static range sums, prefix sums are usually simpler.

Below is a standard C++ implementation used by the current ASU team (adapted from <https://github.com/bqi343>). The iterative `query` is typically faster than the recursive `queryR`, but both are included.

## Segment Tree Code

```cpp
#include <bits/stdc++.h>
using namespace std;

// Credit to Benjamin Qi for implementation.
template <class T> struct SegTree {
    // cmb(ID, b) = b
    const T ID{0};

    T cmb(T a, T b) { return a + b; }

    int n;
    vector<T> seg;

    void init(int _n) { // upd/query work for original size _n
        for (n = 1; n < _n;) n *= 2;
        seg.assign(2 * n, ID);
    }

    void pull(int p) {
        seg[p] = cmb(seg[2 * p], seg[2 * p + 1]);
    }

    void upd(int p, T val) { // set val at position p
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(int l, int r) { // zero-indexed, inclusive
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = cmb(ra, seg[l++]);
            if (r & 1) rb = cmb(seg[--r], rb);
        }
        return cmb(ra, rb);
    }

    T queryR(int l, int r) {
        return queryRec(l, r, 1, 0, n - 1);
    }

    // v: current node index, [nl, nr]: segment covered by node v
    T queryRec(int l, int r, int v, int nl, int nr) {
        if (r < nl || l > nr) return ID;
        if (l <= nl && nr <= r) return seg[v];
        int mid = (nl + nr) / 2;
        return cmb(
            queryRec(l, r, 2 * v, nl, mid),
            queryRec(l, r, 2 * v + 1, mid + 1, nr)
        );
    }
};

int main() {
    int n;
    cin >> n;

    SegTree<int> seg;
    seg.init(n); // initializes segment tree of n integers, 0-indexed
}
```

---

In many problems, you can treat the segment tree as a black box and only change the combine operation.

### Practice Problems

- [Ant Colony (CF)](https://codeforces.com/contest/474/problem/F)
- [Enemy is Weak (CF)](https://codeforces.com/problemset/problem/61/E) (it may help to solve inversion counting first)
- [Forklift Certified (USACO) - Mode 2](https://usaco.org/index.php?page=viewproblem2&cpid=1524)

### DP Optimized with Segment Tree

- [Domino Principle (CF)](https://codeforces.com/problemset/problem/56/E)
- [Smooth Subsequence (AtCoder)](https://atcoder.jp/contests/abc339/tasks/abc339_e)

### Offline Tricks

- [Distinct Values Queries (CSES)](https://cses.fi/problemset/task/1734)
- [KQUERY (SPOJ)](https://www.spoj.com/problems/KQUERY/)

Node data does not have to be a single number. You can store multiple values as long as the combine function remains associative. For example, to answer range minimum queries and also count how many times the minimum appears, each node can store `(min_value, frequency)`.

This idea also helps with updateable versions of classic DP-style problems:

- [Subarray Sum Queries (CSES)](https://cses.fi/problemset/task/1190/)
- [Sereja and Brackets (CF)](https://codeforces.com/problemset/problem/380/C)