# -*- coding: utf-8 -*-
"""
Created on Tue Oct 19 14:30:27 2021

@author: Gianluca
"""

x = 2
y = x+1.0
print('il tipo di x è ', type(x))
print('il tipo di y è ', type(y))

c = 1

# eseguire il corpo del while fintanto che y non è divisibile 9
# al più 100 volte
while y%9 != 0 and c <= 100:
    y = y + 3
    c += 1  # equivalente a c = c + 1
    print(y)

# so che c == 101 oppure y divisibile per 9

if y%9 != 0:
    print('non ho trovato y divisibile per 9')
else:
    print('il valore di y divisibile per 9 è ', y)

print('fine programma')

