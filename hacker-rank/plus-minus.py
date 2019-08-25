#!/bin/python

import sys

def result(ar):
    pos = neg = zer = 0.0
    for x in range(len(ar)):
        if ar[x] > 0:
            pos += 1
        elif ar[x] < 0:
            neg += 1
        else:
            zer += 1
    return pos/len(ar),neg/len(ar),zer/len(ar)

n = int(raw_input().strip())
arr = map(int,raw_input().strip().split(' '))
res = result(arr)
for x in range(3):
    print res[x]
