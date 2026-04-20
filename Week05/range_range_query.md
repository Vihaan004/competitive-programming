# Range Range Query

Time limit per test: 2 s.
Memory limit per test: 256 MB

You are given an array of n integers a1,a2,…,an. The range of a subarray [l,r] of a is defined as the largest possible value of ai−aj for l≤i,j≤r. You are given q queries which come in one of two forms:

1 x y: set a[x] to y
2 p q: output the range of subarray [p,q] for array a

## Input

The first line contains an integer t (1≤t≤104) — the number of test cases.

For each test case, the first line contains two integers n and q (2≤n≤2⋅105, 1≤q≤2⋅105).

The next line contains n integers a1,a2,…,an (−109≤ai≤109).

The next q lines each describe one operation in one of the following forms:

1 x y — set a[x]=y (1≤x≤n, −109≤y≤109)

2 p q — query the range of subarray [p,q] (1≤p≤q≤n)

It is guaranteed that ∑n≤2⋅105 and ∑q≤2⋅105 over all test cases.

## Output

Output a line for each query of type 2 containing one integer, the range of the requested subarray.

## Example

InputCopy

```text
1
6 10
-7 6 7 5 -3 -3
2 1 4
1 5 -7
2 4 6
2 3 6
1 2 -8
1 1 8
2 5 5
1 1 -9
1 3 -4
2 3 4
```

OutputCopy

```text
14
12
14
0
9
```