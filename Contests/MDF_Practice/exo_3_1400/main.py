#!/usr/bin/env python3

import sys

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))

N = int(lines.pop(0))
dp = [1.0]

for l in lines:
    l = [float(x) for x in l.split()]
    dp = [(dp[i]*(1 - l[i]) if i != len(l) else 0) +
          (dp[i - 1]*l[i - 1] if i != 0 else 0) for i in range(len(l) + 1)]

print(max(range(N), key=lambda x: dp[x]))

if __name__ == "__main__":
    print("Hello World!")
