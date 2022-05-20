#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* la dimensione dell'array di liste, valore fittizio
* sopo per test
*/
#define M 10

struct dict_item {
    char *k;  /* chiave */
    float v;  /* valore */
};
typedef struct dict_item dict_item;

struct lista_item {
    dict_item val;
    struct lista_item *next;
    struct lista_item *prev;
};
typedef struct lista_item lista_item;

typedef lista_item* lista; /* = NULL per lista vuota*/

struct dizionario {
    lista *a;/* array delle liste */
    int m;   /* numero di liste, lunghezza di a */
    int n;   /* numero di item del dizionario */
};
typedef struct dizionario dizionario;

dizionario dizionario_new();
int h(dizionario, char*);
dict_item *dizionario_search(dizionario, char*);


lista lista_in0(lista, char*);
lista lista_in1(lista, char*);
lista lista_in(lista, int, char*);
lista lista_append(lista, char*);
lista lista_out0(lista);
lista lista_out1(lista);
lista lista_out(lista, int);
void lista_print(lista);
lista_item *lista_search(lista, int);

void main( int n_args, char *args[]  ){
    dizionario d = dizionario_new();
    int i;
    
    for( i = 1; i < n_args; i++){
        printf("%s ---> %d\n", args[i], h(d, args[i]) );
    }
}

/*
* Restituisce un dizionario vuoto.
* Alloca un array di liste di dimensione M costante. Soluzione
* valida solo a fini didattici, in una implementazione reale
* l'array delle liste dovrebbe essere dinamico allo scopo di
* mantenere costante il rapporto tra d.n e d.m
*/
dizionario dizionario_new(){
    int i;
    dizionario d;
    d.m = M; 
    d.n = 0;
    d.a = malloc(sizeof(lista)*d.m);
    for(i = 0; i < d.m; i++){
       d.a[i] = NULL;
    }
    return d;
}

/*
* Funzione hash
* Restituisce l'indice per la chiave k nell'array d
*/
int h(dizionario d, char *k){
    int i, pos = 0; /* l'indice di output*/
    for(i = 0; k[i] != '\0'; i++){
        pos = pos^k[i];
    }
    return pos%d.m;
}

/*
* Ritorna l'item del dizionario con chiave k, NULL se
* k non e' presente nel dizionario
*/
dict_item *dizionario_search(dizionario d, char* k){
    int list_index = h(d, k);
    dict_item *p;
    
    p = lista_search_val(d[list_index], k);
    
    return p;
}


/********************************************/

/*
* Ricerca per valore su una lista, restituisce il
* puntatore all'item o NULL in caso questo non
* esista
*/
lista_item *lista_search_val(lista a, char *s){
    lista_item *p = a;
        
    while ( p != NULL ){
        if ( strcmp(p->val.k, s) == 0) /*le stringhe sono uguali*/ 
            return p;
        p = p->next;
    }
    
    return p; /* la chiave s non e' in d*/
}
