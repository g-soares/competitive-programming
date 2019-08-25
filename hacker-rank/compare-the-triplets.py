#!/bin/python

import sys

def solve(a0, a1, a2, b0, b1, b2):
    # Complete this function
    alice = [a0,a1,a2]
    bob = [b0,b1,b2]
    alice_count = bob_count = 0
    for x in range(3):
        if alice[x] > bob[x]:
            alice_count += 1
        elif alice[x] < bob[x]:
            bob_count += 1
    return alice_count,bob_count

a0, a1, a2 = raw_input().strip().split(' ')
a0, a1, a2 = [int(a0), int(a1), int(a2)]
b0, b1, b2 = raw_input().strip().split(' ')
b0, b1, b2 = [int(b0), int(b1), int(b2)]
result = solve(a0, a1, a2, b0, b1, b2)
print " ".join(map(str, result))