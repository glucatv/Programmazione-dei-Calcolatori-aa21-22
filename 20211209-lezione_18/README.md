# Argomenti

* Soluzione degli esercizi della lezione precedente (ordinamento bi-criterio con *bubble_sort* ed opportuna funzione di confronto)

* Implementazione della funzione bubble-sort con *key*-function definire il criterio di ordinamento.

* Confronto tra sequenza (negli esempi sono tuple)

* [Video della lezione](https://www.dropbox.com/s/lfheptv98m8qra3/20211209-lezione_18.mp4?dl=1)

# Esercizio 1

**Ordinamento multi-criterio 2** La lista *a* è composta da numeri e stringhe, si vogliono ordinare gli elementi di *a* in modo che: 

1. i numeri precedano le stringhe
2. i numeri siano ordinati dal più piccolo al più grande
3. le stringhe siano ordinate da quella più corta a quella più lunga

Progettare ed implementare una opportuna *key*-function da utilizzare con la lunzione *bubble_sort*

# Esercizio 2

**Ordinamento invertito** Dopo aver risolto il precedente esercizio, modificare la funzione in modo che sia compreso un terzo parametro, chiamato *reverse*, di tipo **bool** che di default deve essere **False**. In caso questo sia **True** l'ordinamento deve essere invertito rispetto al criterio indotto alla **key**-function.

Ad esempio dopo

	a = ['zero', 'uno', 'due', 'tre', 'quattro']
	bubble_sort(a, k = len, reverse = True) 
	
la lista diventa

	['quattro', 'zero', 'uno', 'due', 'tre']
