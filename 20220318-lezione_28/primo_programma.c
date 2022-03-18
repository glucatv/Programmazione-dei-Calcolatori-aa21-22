#include <stdio.h>

void main(){
    int x = 2; /* dichiarazione e inizializzazione della variabile x */
    float y;   /* dichiarazione */
    char c = 'd';
    char s[] = "questa stringa finisce qua";
    int i;
    
    
    x = x+1;
    printf("\tQuesto e'\n un programma\n scritto in C\n");
    
    printf("Il valore corrente di x e' %d\n", x);

    y = x + 6;
    
    printf("Il valore corrente di y e' %f\n", y);
    
    x = y + 0.5;
    
    printf("Il valore corrente di x e' %d\n", x);
    
    printf("Il valore corrente di c e' %c\n", c);

    printf("Il valore corrente di s e' %s\n", s);
    
    printf("Il valore corrente di s[%d] e' %c\n", 3, s[3]);
    
    i = 0;
    while ( i < 7 ) {
        printf("\t%c\n", s[i]);
        i += 1;
    }
    
    i = 0;
    while ( s[i] != '\0' ) {
        printf("\t%c\n", s[i]);
        i += 1;
    }
    printf("La lunghezza di s e' %d\n", i);

}
