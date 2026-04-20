# Practice
- [chocolate](../Week06/chocolate.md)
- [right_triangle](../Week06/right_triangle.md)

# Basics of Counting

## Binomial Coefficient Pattern: Choose Positions

When you need to place $k$ identical special markers into $n$ distinct slots (or choose which $k$ items are special), the count is:

$$
\binom{n}{k}
$$

Classic example: the number of binary strings of length $n$ with exactly $k$ ones is $\binom{n}{k}$ (choose the $k$ positions of the ones).

### Practice

- [Dreamoon and WiFi (CF)](https://codeforces.com/problemset/problem/476/B)
- [Knight (AtCoder)](https://atcoder.jp/contests/abc145/tasks/abc145_d)
- [Bouquet (AtCoder)](https://atcoder.jp/contests/abc156/tasks/abc156_d)

## Computing $\binom{n}{k}$ with Factorials and Inverse Factorials (mod prime)

Many problems require many queries of $\binom{n}{k} \bmod p$ for a fixed prime $p$ (commonly $10^9 + 7$).

Use:

$$
\binom{n}{k} \equiv \frac{n!}{k!(n-k)!} \pmod{p}
$$

and modular inverses for division modulo $p$.

## Fermat Inverse (Prime Modulus)

If $p$ is prime and $a \not\equiv 0 \pmod p$, then:

$$
a^{-1} \equiv a^{p-2} \pmod p
$$

## Precomputation Plan

Let $N$ be the maximum $n$ needed.

- Precompute $\text{fact}[i] = i! \bmod p$ for $0 \le i \le N$.
- Precompute $\text{invfact}[i] = (i!)^{-1} \bmod p$ for $0 \le i \le N$ using binary exponentiation.
- Then each query is $O(1)$:

$$
\binom{n}{k} = \text{fact}[n] \cdot \text{invfact}[k] \cdot \text{invfact}[n-k] \bmod p
$$

### Practice

- [Binomial Coefficients (CSES)](https://cses.fi/problemset/task/1079)
- [Creating Strings II (CSES)](https://cses.fi/problemset/task/1715)

## Stars and Bars

### Core Statement

The number of nonnegative integer solutions to

$$
x_1 + x_2 + \cdots + x_n = m, \quad x_i \ge 0
$$

is

$$
\binom{m+n-1}{n-1}.
$$

### Common Variations

- If $x_i \ge 1$, substitute $y_i = x_i - 1$:

$$
x_1 + \cdots + x_n = m, \ x_i \ge 1
\Longleftrightarrow
y_1 + \cdots + y_n = m-n, \ y_i \ge 0
$$

So the count is $\binom{m-1}{n-1}$ (when $m \ge n$).

- If $x_i \ge L_i$, substitute $y_i = x_i - L_i$ and reduce the sum.

### Practice

- [Distributing Apples (CSES)](https://cses.fi/problemset/task/1716)
- [Two Arrays (CF)](https://codeforces.com/problemset/problem/1288/C)

## Principle of Inclusion-Exclusion (PIE)

PIE is the standard way to count objects that avoid all bad properties when overlaps exist.

### Formula (Union Size)

For sets $A_1, \dots, A_k$:

$$
\left|\bigcup_{i=1}^{k} A_i\right|
= \sum_{\varnothing \ne S \subseteq [k]} (-1)^{|S|+1}
\left|\bigcap_{i \in S} A_i\right|.
$$

When $k$ is up to about $20$-$25$, iterating all $2^k$ subsets is feasible.

For many PIE counting tasks:

- Define the intersection size for each subset $S$.
- Add/subtract based on the parity of $|S|$.

### Practice

- [Prime Multiples (CSES)](https://cses.fi/problemset/task/2185)
- [Counting Sequences (CSES)](https://cses.fi/problemset/task/2228)
- [Devu and Flowers (CF)](https://codeforces.com/problemset/problem/451/E)

### General Problems

- [Max-Min Sums (AtCoder)](https://atcoder.jp/contests/abc151/tasks/abc151_e)
- [Colorful Blocks (AtCoder)](https://atcoder.jp/contests/abc167/tasks/abc167_e)
- [Strivore (AtCoder)](https://atcoder.jp/contests/abc171/tasks/abc171_f)