#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 21 15:18:32 2021

@author: gianluca
"""

try:
    righe = int(input('Numero di righe: '))
except ValueError:
    righe = 3

input_corretto = False
while not input_corretto:
    try:
        colonne = int(input('Numero di colonne: '))
        input_corretto = True
    except ValueError:
        '''
        '''

r = 0
while r < righe:
    c = 0
    while c < colonne:
        if c == 0 or c == colonne-1 or\
                        r == 0 or r == righe-1:
            print('*', end='')
        else:
            print(' ', end='')
        c += 1
    print('')
    r += 1
