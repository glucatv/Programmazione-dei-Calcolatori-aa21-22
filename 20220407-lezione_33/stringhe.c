#include <stdio.h>
#include <stdlib.h>

char *str_cat(char *a, char *b);
int str_len( char *a );
int conta_minuscole(char *a);

void main(){
    int n = 10;
    char a[] = "01234567";
    char b[] = "1abc*d3efg0";

    char *c = str_cat(a, b);
    
    printf("%s, %d\n", c, str_len(c));
    
    /*
     * il tipo char e la codifica ASCII
     * */
    printf("%c -> %d\n%c -> %d\n%c -> %d\n", b[0], b[0], b[1], b[1], b[2], b[2]);
    printf("A -> %d\n", 'A');
    printf("0 -> %d\n", '0');
    
    printf("%c\n", b[0] + 1); 

}

/*
 * Restituisce una nuova stringa ottenuta concatenando le due stringhe di input
 * */
char *str_cat(char *a, char *b){
    char *c = NULL;
    int na = str_len(a), nb = str_len(b);
    int i = 0, j;
    
    c = malloc( (na+nb+1)*sizeof(char) );
    
    for(i = 0; i < na; i++){
        c[i] = a[i];
    }
    
    j = 0;
    while( b[j] != '\0' ){
        c[i] = b[j];
        i++;
        j++;
    }
    
    c[i] = '\0';
    
    return c;
}

/*
 * Resituisce la lunghezza della stringa in input
 * */
int str_len( char *a ){
    int len = 0;
    
    while( a[len] != '\0'){
        len++;
    }
    
    return len;
}
