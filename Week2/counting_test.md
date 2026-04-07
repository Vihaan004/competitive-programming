# Counting Test

Time limit per test: 4 s
Memory limit per test: 256 megabytes

Yousef has a string s that is used to build a magical string w by repeating the string s infinitely many times. For example, if s = aabbb , then w = aabbbaabbbaabbbaabbb....

Mohammad always claims that his memory is strong, and that his ability to count is very high, so Yousef decided to hold a test for Mohammad, in order to know the truth of his claims.

Yousef will give Mohammad q queries, such that each query consisting of two integers l and r, and a lowercase English letter c. The answer of each query is how many times the letter c appears between the lth and rth letters in string w.

Mohammad must answer all the queries correctly, in order to proof his claims, but currently he is busy finishing his meal. Can you help Mohammad by answering all queries?

## Input

The first line contains an integer T, where T is the number of test cases.

The first line of each test case contains two integers n and q (1 ≤ n ≤ 104) (1 ≤ q ≤ 105), where n is the length of string s, and q is the number of queries.

The second line of each test case contains the string s of length n consisting only of lowercase English letters.

Then q lines follow, each line contains two integers l and r and a lowercase English letter c (1 ≤ l ≤ r ≤ 109), giving the queries.

## Output

For each query, print a single line containing how many times the letter c appears between the lth and rth letters in string w.

## Example

InputCopy

```text
1
8 5
abcabdca
1 8 c
1 15 b
4 9 a
5 25 d
2 7 c
```

OutputCopy

```text
2
4
3
3
2
```

## Note

As input/output can reach huge size it is recommended to use fast input/output methods: for example, prefer to use scanf/printf instead of cin/cout in C++, prefer to use BufferedReader/PrintWriter instead of Scanner/System.out in Java.


