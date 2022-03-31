#include <stdio.h>

#define C 100000

void print_array_int(int *x, int n){
    int i;
    
    printf("Numero di byte di x: %ld\n", sizeof(x));
    
    for( i = 0; i < n; i++ ){
        printf("%d, ", x[i]);
    }
    printf("\n");
}

void main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = NULL; /* puntatore a int*/
    int n;
    int b[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int c[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    printf("Numero di byte di a: %ld\n", sizeof(a));
    printf("Numero di byte di int: %ld\n", sizeof(int));
    
    n = sizeof(a)/sizeof(int);
    print_array_int(a, n);
    
    p = a;
    print_array_int(p, n);
    
    p = b;
    print_array_int(p, n);    
    
    /*a = b;  vietato, non posso 'modificare l'indirizzo' di un array */

    printf("Il valore della costante C %d\n", C);
    
    p = a;
    if (p == a ){  /* il confronto e' tra gli indirizzi*/
        printf("a == p\n");
    } else {
        printf("a != p\n");
    }

    if (c == a ){ /* il confronto e' tra gli indirizzi*/
        printf("a == c\n");
    } else {
        printf("a != c\n");
    }
    
    /* Operatore * e aritmetica dei putatori */

    printf("%d\n", *p); /* l'intero puntato da p */
    printf("%d\n", *(p+1) ); /* il valore dell'intero successivo a quello puntato da p */    
}