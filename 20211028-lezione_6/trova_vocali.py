a = input('Inserisci una stringa: ')

vocali = 'aeiouAEIOU'

soluzione = ''

for x in a:
	if x in vocali:
		soluzione += '*' 
	else:
		soluzione += ' '
		
print(a)
print(soluzione)	