#!/bin/python

import sys


n = int(raw_input().strip())
aux = []
for x in range(n):
    aux.append(" ")
for x in range(n):
    aux[n-x-1] = "#"
    print ''.join(aux)