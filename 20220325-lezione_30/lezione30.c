#include <stdio.h>

/* Prototipi */
int len( char a[] );
float pi();
float nep();

void main(){
    char x[] = "questo e' un programma";
    
    printf("La lunghezza della stringa e' %d\n", len(x) );
    printf("Il valore di pi-greco e' %f\n", pi() );
    printf("Il valore di e e' %f\n", nep() );
}


int len( char a[] ){
    int len = 0;
    
    while( a[len] != '\0'){
        len++; /* len += 1 */
    }
    
    return len;
}

float pi(){
    return 3.14;
}
