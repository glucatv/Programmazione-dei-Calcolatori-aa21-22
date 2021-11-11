#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov 11 14:10:54 2021

@author: gianluca
"""

'''
return True se e solo se la stringa a è
palindroma 
'''
def palindromo( a ):
    if a == a[::-1]: # l'inverso di a
        return True
    else:
        return False
    
a = input('Inserisci una stringa: ')

if palindromo( a ):
    print('La stringa', a, 'è palindroma')
else:
    print('La stringa', a, 'non è palindroma')