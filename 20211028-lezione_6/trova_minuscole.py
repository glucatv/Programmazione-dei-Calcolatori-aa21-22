a = input('Inserisci una stringa: ')

soluzione = ''

for x in a:
	if x >= 'a' and x <= 'z':
		soluzione += '*' 
	else:
		soluzione += ' '
		
print(a)
print(soluzione)	