#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov  4 14:22:31 2021

@author: gianluca
"""

a = input('La stringa di base: ')
b = input('La stringa da cercare: ')

n_a, n_b, p = len(a), len(b), -1

i, trovato = 0, False, 
while i <= n_a - n_b and not trovato :
    if b == a[i:i+n_b]:
        p = i
        trovato = True
    i += 1

print(p)

if trovato:
    c = a[:p] + a[p+n_b:]
    print(c)
else:
    print('non trovata')