# The Sports Festival

Time limit per test: 1 second
Memory limit per test: 256 megabytes

The student council is preparing for the relay race at the sports festival.

There are $n$ members. They run one after another, and member $i$ has speed $s_i$.

Define the discrepancy of stage $i$ as:

$$
d_i = \max(a_1, a_2, \dots, a_i) - \min(a_1, a_2, \dots, a_i),
$$

where $a_i$ is the speed of the $i$-th runner in your chosen order.

You may reorder the members. Find the minimum possible value of:

$$
d_1 + d_2 + \cdots + d_n.
$$

## Input

The first line contains one integer $n$ ($1 \le n \le 2000$): number of members.

The second line contains $n$ integers $s_1, s_2, \dots, s_n$ ($1 \le s_i \le 10^9$): running speeds.

## Output

Print one integer: the minimum possible value of $d_1 + d_2 + \cdots + d_n$.

## Examples

InputCopy

```text
3
3 1 2
```

OutputCopy

```text
3
```

InputCopy

```text
1
5
```

OutputCopy

```text
0
```

InputCopy

```text
6
1 6 3 3 6 3
```

OutputCopy

```text
11
```

InputCopy

```text
6
104 943872923 6589 889921234 1000000000 69
```

OutputCopy

```text
2833800505
```

## Note

In the first test case, choose order $[2, 3, 1]$:

- $d_1 = 0$
- $d_2 = 1$
- $d_3 = 2$

Total is $0 + 1 + 2 = 3$, which is optimal.

In the second test case, the only order gives $d_1 = 0$, so the answer is $0$.


