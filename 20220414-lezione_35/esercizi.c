#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap_cases(char *a);
char *slice(char *a, int i, int j);



void main(){
	char a[] = "ProGrammAZi0Ne C e pYTHon";
	char *b;
	
	printf("%s\n", a);
	swap_cases( a );
	printf("%s\n", a);
	
	b = slice(a, 3, 9);
	printf("%s\n", b);
	
	free(b)
	b = slice(a, 9, 9);
	if( b != NULL ) {
		printf("%s\n", b);
		free(b);
	} else{
		printf("NULL\n");
	}
	
	b = slice(a, 0, strlen(a) );
	if( b != NULL ) {
		printf("%s\n", b);
	} else{
		printf("NULL\n");
	}
}

/*
 * Scrivere una funzione denominata swap_cases che prende in input una
 * stringa e rende maiuscole le lettere minuscole e viceversa.
 * */
void swap_cases(char *a){
	int i = 0;
	
	while ( a[i] != '\0' ){
		if ( a[i] >= 'A' && a[i] <= 'Z' ){
			a[i] = 'a' + (a[i] - 'A');
		} else if ( a[i] >= 'a' && a[i] <= 'z' ){
			a[i] = 'A' + (a[i] - 'a');
		} 
		i++;
	}
}

/*
 * Scrivere una funzione denominata slice che prende una stringa a e
 * due interi positivi i e j (si può assumere che i<j) e restituisce
 * una stringa composta dai caratteri a[i], a[i+1],...a[j-1].
 * Si tratti il caso in cui i e j non definiscano indici validi di a,
 * in tale evenienza la funzione deve restituire NULL.
 */
char *slice(char *a, int i, int j){
	int h, n = strlen(a);
	char *b; /* stringa di output */
	
	if ( i < 0 || j < 0 || i > n || j > n || i >= j ) {
		return NULL;
	}
	
	b = malloc( (j-i+1)*sizeof(char) );
	if (b == NULL) {
		return NULL;
	}

	for ( h = i; h < j; h++){
		b[h-i] = a[h];
	}
	b[h-i] = '\0';
	
	return b;
}
