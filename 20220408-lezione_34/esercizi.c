#include <stdio.h>

int conta_minuscole(char *a);

void scambia(int *p, int *q);

void main(){
    int a = 1, b =  11;
    int *pa = &a;
    *pa = 99;
    char w[] = "pr0graMMaZ1oNe PyThon";
    
    /* ESERCIZIO 1:
     * 
     * Scrivere una funzione che scambia i valori di due variabili intere*/
    scambia( &a, &b);

    printf("%d, %d\n", a, b);
    
    printf("Numero di minuscole in %s : %d\n", w, conta_minuscole( w ) );
}

int conta_minuscole(char *x){
    int i = 0, num_minuscole = 0;
    
    while( x[i] != '\0') {
        if ( x[i] >= 'a' && x[i] <= 'z' ){ /* x[i] codifica una minuscola*/
            num_minuscole ++;
        }
        i++;
    }
    
    return num_minuscole;
}

void scambia(int *p, int *q){
    int t = *p;
    *p = *q;
    *q = t;
}

