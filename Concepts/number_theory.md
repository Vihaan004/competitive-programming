# Divisors

A huge number of problems boil down to looping over divisor pairs.

## Enumerating All Divisors (Divisor Pairs)

Key idea:

- If $i \mid n$, then both $i$ and $\frac{n}{i}$ are divisors.
- In every divisor pair, one number is at most $\sqrt{n}$.
- Therefore, check only $i \le \sqrt{n}$.
- Avoid double-counting when $i^2 = n$.

Practice:

- [Counting Divisors (CSES)](https://cses.fi/problemset/task/1713) (may need to be careful with implementation to avoid TLE)
- [Common Divisors (CSES)](https://cses.fi/problemset/task/1081)
- [kth divisor (CF)](https://codeforces.com/problemset/problem/762/A)
- [Secret Message (recent CF div 2)](https://codeforces.com/contest/2194/problem/C)
- [Division or Subtraction (AtCoder)](https://atcoder.jp/contests/abc161/tasks/abc161_f)
- [Tonya and Burenka-179 (CF)](https://codeforces.com/contest/1718/problem/C)

---

## Some Useful Divisor Formulas

For smaller values of $n$, these can often be done naively, but the formulas are still useful.

If

$$
n = \prod p_i^{e_i},
$$

then:

- $\tau(n)$ = number of divisors,
- $\sigma(n)$ = sum of divisors,
- $P(n)$ = product of divisors.

Formulas:

$$
\tau(n) = \prod (e_i + 1)
$$

$$
\sigma(n) = \prod \frac{p_i^{e_i+1} - 1}{p_i - 1}
$$

$$
P(n) = n^{\tau(n)/2}
$$

---

# Sieve of Eratosthenes

When constraints involve many queries or large ranges, factoring in $O(\sqrt{n})$ per query is too slow. Sieve methods precompute prime/primality/smallest-prime-factor information efficiently.

## Classic Sieve (Primality)

```text
is_prime[0] = is_prime[1] = false
is_prime[2..N] = true
for p in 2..floor(sqrt(N)):
  if is_prime[p]:
    for x in p*p, p*p+p, ..., <= N:
      is_prime[x] = false
```

Time complexity: $O(n \log \log n)$.

Notes:

- Start marking at $p^2$ (smaller multiples were marked earlier).
- In some variations, starting from $2p$ is fine asymptotically.
- Use this when you need primality for all numbers up to $N$.

Practice:

- [T-primes (CF)](https://codeforces.com/problemset/problem/230/B)
- [Sherlock and his girlfriend (CF)](https://codeforces.com/problemset/problem/776/B)

---

## SPF Sieve (Smallest Prime Factor) for Fast Factorization

Goal: precompute `spf[x]` = smallest prime dividing `x`. Then each factorization is $O(\log x)$ by repeated division.

```text
spf[1] = 1
for i in 2..N:
  if spf[i] == 0:      // i is prime
    spf[i] = i
    for j in i*i, i*i+i, ..., <= N:
      if spf[j] == 0:
        spf[j] = i
```

From prime factorization, you can generate all divisors in $O(\#\text{divisors})$ instead of scanning to $n$.

Use cases:

- Many factorizations
- Counting prime exponents / computing divisor counts for many numbers
- Computing totients for all numbers with sieve-style methods

Practice:

- [Enlarge GCD (CF)](https://codeforces.com/problemset/problem/1034/A)

---

## Sieve over Values (Iterate Multiples)

This pattern is not about primality; it is about counting multiples efficiently.

For each value $d$, look at all multiples $k = d, 2d, 3d, \dots$:

```text
for d in 1..N:
  for k in d, 2d, 3d, ..., <= N:
    // do something with (d divides k)
```

If inner work is $O(1)$, total time is $O(n \log n)$.

Reference problem:

- [Counting Divisors (CSES)](https://cses.fi/problemset/task/1713)

Practice:

- [Not Divisible (AtCoder ABC170 D)](https://atcoder.jp/contests/abc170/tasks/abc170_d)
- [Common Divisors (CSES)](https://cses.fi/problemset/task/1081) (can we find better complexity than before?)
- [Turn on the Light 3](https://qoj.ac/contest/2021/problem/10724)

Other problem:

- [Prime Generator (SPOJ)](https://www.spoj.com/problems/PRIME1/)

---

# GCD / LCM

## Core Identities

- Euclidean algorithm:

$$
\gcd(a, b) = \gcd(b, a \bmod b)
$$

- LCM via GCD:

$$
\operatorname{lcm}(a, b) = \frac{a}{\gcd(a, b)} \cdot b
$$

Implementation note: compute as `(a / gcd(a,b)) * b` to reduce overflow risk.

---

## LCM/GCD via Prime Exponents

To compute $\operatorname{lcm}(a_1, \dots, a_n)$ (especially under a modulus), you often:

1. Factor all numbers.
2. Keep the maximum exponent of each prime.
3. Rebuild the LCM as $\prod p^{\max e_p}$ (optionally modulo $M$).

Similarly, for $\gcd$, take minimum exponents.

Practice:

- [Flatten (AtCoder ABC152 E)](https://atcoder.jp/contests/abc152/tasks/abc152_e)

Problems:

- [GCD on Blackboard (AtCoder ABC125 C)](https://atcoder.jp/contests/abc125/tasks/abc125_c)
- [CGCDSSQ (CF 475D)](https://codeforces.com/problemset/problem/475/D)
