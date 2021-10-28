#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 26 15:27:21 2021

@author: gianluca
"""

a = input('Scrivi qualcosa: ')

n = len(a)


i = 0
while a[i] == a[n-1-i] and i < n/2:
    i += 1
    
if a[i] != a[n-1-i]:
	print(False)
else:
	print(True)