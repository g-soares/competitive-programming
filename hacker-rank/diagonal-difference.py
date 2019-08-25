#!/bin/python

import sys

def result(matriz,length):
    d1 = d2 = 0
    for x in range(length):
        d1 += matriz[x][x]
        d2 += matriz[x][length-x-1]
    return abs(d1-d2)

n = int(raw_input().strip())
a = []
for a_i in xrange(n):
    a_temp = map(int,raw_input().strip().split(' '))
    a.append(a_temp)
    
print "%d" %(result(a,n))
