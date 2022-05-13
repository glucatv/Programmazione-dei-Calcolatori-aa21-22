#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista_item {
    char *val;
    struct lista_item *next;
    struct lista_item *prev;
};
typedef struct lista_item lista_item;

typedef lista_item* lista; /* = NULL per lista vuota*/

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
    lista a = NULL;
    int i;
    
    for( i = 0; i < n_args; i++){
        a = lista_in0(a, args[i]);
    }
    
    lista_print(a);
}

/*
* Aggiunge in posizione 0 un nuovo elemento contenente la striga v.
*/
lista lista_in0(lista a, char *v) {
    lista_item *p = malloc(sizeof(lista_item));    
    int n;
    if (p == NULL){
        return a;
    }
    
    n = strlen(v);
    
    /* nella lista viene inserita una copia di v,
    * l'alternativa e' utilizzare creare un alias copiando il
    * puntatore v... pro e contro
    */
    p->val = malloc(sizeof(char)*(n+1));
    if (p->val != NULL)
        strcpy(p->val, v);
    p->val[n] = '\0';
    p->prev = NULL;
    p->next = a;
    if (a != NULL){
        a->prev = p;
    }
    
    return p;
}

/*
* Stampa i valori della lista in input. Il costo computazionale e' lineare
* nella lunghezza della lista.
*/
void lista_print(lista a){
    lista_item  *p = a;

    printf("===============\n");
    
    for( p = a; p !=NULL; p = p->next){
        printf("%s\n", p->val);
    }
  
}

/*
* Viene eliminato il primo elemento dalla lista... cosa manca?
*/
lista lista_out0(lista a) {
    lista p = a;
    
    if ( a == NULL ) {
        return NULL;
    }
    
    a = a->next;
    
    if ( a != NULL){
        a->prev = NULL;
    }
    
    free(p);
    return a;
}

