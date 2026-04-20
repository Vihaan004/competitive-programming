# Checkposts

Time limit per test: 2 s.
Memory limit per test: 256 MB

Your city has $n$ junctions and $m$ one-way roads between them. You want to ensure the security of all junctions by building police checkposts.

A checkpost can only be built at a junction. A checkpost at junction $i$ can protect junction $j$ if either:

- $i = j$, or
- the police patrol car can go from $i$ to $j$ and then come back from $j$ to $i$.

Building checkposts costs money: building at junction $i$ costs $c_i$.

You must determine:

1. The minimum total cost needed to protect all junctions.
2. The number of different ways to achieve this minimum cost, modulo $1000000007$.

Two ways are different if there exists a junction that has a checkpost in one way and does not have a checkpost in the other.

## Input

The first line contains an integer $n$ ($1 \le n \le 10^5$) — the number of junctions.

The second line contains $n$ space-separated integers $c_1, c_2, \dots, c_n$ — the cost of building a checkpost at each junction ($0 \le c_i \le 10^9$).

The next line contains an integer $m$ ($0 \le m \le 3 \cdot 10^5$) — the number of roads.

Each of the next $m$ lines contains two integers $u_i$ and $v_i$ ($1 \le u_i, v_i \le n$, $u_i \ne v_i$) meaning there is a directed road from $u_i$ to $v_i$.
There is at most one road in the same direction between any two junctions.

## Output

Print two integers separated by spaces:

- the minimum possible total cost,
- the number of ways to achieve it modulo $1000000007$.

## Examples

InputCopy

```text
3
1 2 3
3
1 2
2 3
3 2
```

OutputCopy

```text
3 1
```

InputCopy

```text
5
2 8 0 6 0
6
1 4
1 3
2 4
3 4
4 5
5 1
```

OutputCopy

```text
8 2
```

InputCopy

```text
10
1 3 2 2 1 3 1 4 10 10
12
1 2
2 3
3 1
3 4
4 5
5 6
5 7
6 4
7 3
8 9
9 10
10 9
```

OutputCopy

```text
15 6
```

InputCopy

```text
2
7 91
2
1 2
2 1
```

OutputCopy

```text
7 1
```