#include <stdio.h>
#include <stdlib.h>

void print_array_int(int *x, int n){
    int i;
    
    for( i = 0; i < n; i++ ){
        printf("%d, ", *(x+i));
    }
    printf("\n");
}

int *crea_array_int(int n) {
    int size = n*sizeof(int);
    int *p = malloc(size);
    int i;
    
    if ( p != NULL ){ /* ho l'array */
        for(i = 0; i < n; i++ ) {
            p[i] = 0;
        }
    }
        
    return p;
}

void main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = a;
    int i;
    int n = sizeof(a)/sizeof(int);
    
    float e = 2.71;
        
    print_array_int(p, n); /* oppure print_array_int(a, n) */
    
    printf("%p\n", p);
    
    /*
    p = &e; ATTENZIONE!!!! 
    
    printf("%f\n", *p); ATTENZIONE!!!! 
    */
        
    p = crea_array_int(10);
    print_array_int(p, 10);
    free(p); /* deallocazione della memoria puntata da p*/
 }