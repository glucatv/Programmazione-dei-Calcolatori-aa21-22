# -*- coding: utf-8 -*-
"""
Created on Tue Oct 19 14:30:27 2021

@author: Gianluca
"""

x = 1
y = x+1.0
print('il tipo di x è ', type(x))
print('il tipo di y è ', type(y))

c = 1
while c <= 10:
	y = y + 1
	c += 1  # equivalente a c = c + 1

print('il valore di y è ', y)
print('fine programma')
