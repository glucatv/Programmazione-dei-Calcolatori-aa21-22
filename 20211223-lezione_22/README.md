# Argomenti

* La struttura dati dizonario: definizione, operatori, metodi e costi computazionali

* [Video della lezione](https://www.dropbox.com/s/z7blwdunqo01nte/20211223-lezione_22.mp4?dl=1)

# Esercizi

## 1
Sia `a` una lista lunga `n`, scrivere un programma che chiede all'utente di digitare `m` stringhe e per ognuna di queste il programma deve stampaew quante volte compare in `a` ed in che posizione si trova l'ultima occorrenza (se il numero di occorrenze è >0). Il costo della soluzione deve essere `O(n+m)`.

## 2
Scrivere una funzione denominata *inverti_dizionario* che prende in input un dizionario `d` e restituisce un dizionario `d_inv` che ha per chiavi i valori in `d` e `d_inv[v]` è la lista di chiavi che `d` mappa in `v`. Esempio se

	d = { 'k0': 'v0', 'k1': 'v1', 'k2': 'v0' }

allora

	d_inv = { 'v0': ['k0', 'k2'], 'v1': ['k1'] }

Calcolare il costo computazionale della soluzione prodotta.

## 3
Scrivere una funzione che prende due dizionari in input `a` e `b` e restituisce un terzo dizionario `c` che ha per chiavi tutte quelle in `a` che non sono in `b` e tutte quelle in `b` che non sono in `a`. I valori associati a queste chiavi devono essere quelli del dizionario di partenza. La funzione deve chiamarsi *differenza_simmetrica*. Esempio se

	a = {'k0': 'v0', 'k1': 'v1', 'k2': 'v0'}
	b = {'k1': 'v7', 'k2': 'v1', 'k3': 'v3'}

allora `differenza_simmetrica(a, b)` deve restituire

	{'k0': 'v0', 'k3': 'v3'}

Calcolare il costo computazionale della soluzione prodotta.

