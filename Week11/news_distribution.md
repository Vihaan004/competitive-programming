# News Distribution

Time limit per test: 2 seconds
Memory limit per test: 256 megabytes

In some social network, there are $n$ users communicating with each other in $m$ groups of friends.

Initially, some user $x$ receives the news from some source. Then they send the news to their friends.

Two users are **friends** if there exists at least one group such that both of them belong to this group.
Friends continue sending the news to their friends, and so on. The process ends when there is no pair of friends such that one of them knows the news and the other one doesn't.

For each user $x$, determine how many users will know the news if initially only user $x$ starts distributing it.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n, m \le 5 \cdot 10^5$) — the number of users and the number of groups of friends.

Then $m$ lines follow, each describing a group of friends.

The $i$-th line begins with an integer $k_i$ ($0 \le k_i \le n$) — the number of users in the $i$-th group.
Then $k_i$ distinct integers follow, denoting the users belonging to the $i$-th group.

It is guaranteed that $\sum_{i=1}^{m} k_i \le 5 \cdot 10^5$.

## Output

Print $n$ integers. The $i$-th integer should be equal to the number of users that will know the news if user $i$ starts distributing it.

## Example

InputCopy

```text
7 5
3 2 5 4
0
2 1 2
1 1
2 6 7
```

OutputCopy

```text
4 4 1 4 4 2 2
```

