# Cut Ribbon

Time limit per test: 1 second
Memory limit per test: 256 megabytes

Polycarpus has a ribbon of length $n$. He wants to cut the ribbon so that:

1. Every piece has length exactly $a$, $b$, or $c$.
2. The total number of pieces is as large as possible.

Find the maximum number of pieces he can obtain.

## Input

The first line contains four integers $n$, $a$, $b$, and $c$ ($1 \le n, a, b, c \le 4000$):

- $n$: original ribbon length
- $a, b, c$: allowed piece lengths

The values $a$, $b$, and $c$ may be equal.

## Output

Print one integer: the maximum possible number of ribbon pieces.

It is guaranteed that at least one valid cutting exists.

## Examples

InputCopy

```text
5 5 3 2
```

OutputCopy

```text
2
```

InputCopy

```text
7 5 5 2
```

OutputCopy

```text
2
```

## Note

In the first example, one optimal cut is $2 + 3$, giving $2$ pieces.

In the second example, one optimal cut is $5 + 2$, giving $2$ pieces.