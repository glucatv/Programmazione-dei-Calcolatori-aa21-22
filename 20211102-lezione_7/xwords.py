a = input('Immetti una stringa: ')
b = input('Immetti una stringa: ')

i = 0
trovato = False
while i < len(a) and not trovato:
	j = 0
	while j < len(b) and not trovato:
		if a[i] == b[j]:
			trovato = True
			p_a, p_b = i, j
		j += 1
	i += 1
	
if trovato:
	for i in range(len(a)):
		# mostro riga i
		if i != p_a:
			print(' '*p_b+a[i])
		else:
			print(b)