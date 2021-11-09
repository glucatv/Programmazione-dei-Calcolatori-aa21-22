#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 14 15:21:17 2021
@author: gianluca
"""

'''
Restituisce la radice quadrata di a
'''
def radice( a, err = 0.0000001 ):
    g = a/2
    while abs( g*g - a ) > err: 
        g = 0.5 * ( g + a/g )
    return g

x = float(input('Inserisci il valore di x: '))
y = float(input('Inserisci il valore di y: '))

r_x, r_y = radice( x, 1**(-9) ), radice( y )

print(r_x, r_y)

print(r_x + r_y)

