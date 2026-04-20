# Six-Seven

Time limit per test: 1 second
Memory limit per test: 256 megabytes

Little Johnny is eating his rice, but as he is a five year old, he is brainrotted to the max. He only agrees to eat his rice in bites of 67 or 76 grains at a time. Help Johnny figure out the number of distinct ways can Little Johnny eat his rice and finish his plate. Two ways are different if the sequences of bites he takes differ at any point in time.

## Input

You are given an integer 1≤n≤10^4, the number of test cases.

Each of the next n lines contains a single integer 1≤x≤10^6, the number of grains of rice on Johnny's plate.

## Output

For each test case, output the number of distinct ways Johnny can eat his rice. As this number may be large, print the answer modulo 10^9+7.

## Example

InputCopy

```text
6
2
67
76
143
5092
67676
```

OutputCopy

```text
0
1
1
2
2
441771755
```

## Note

Note that there are two ways to make 143: 67+76, and 76+67.


