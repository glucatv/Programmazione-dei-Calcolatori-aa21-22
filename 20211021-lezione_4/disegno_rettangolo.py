#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 21 15:18:32 2021

@author: gianluca
"""
righe, colonne = 3, 13


r = 0
while r < righe:
    c = 0
    while c < colonne:
        print('*', end='')
        c += 1
    print('')
    r += 1
    
    
'''
per esercizio: modificare il codice in modo da
mostrare solo il perimetro del rettangolo
'''