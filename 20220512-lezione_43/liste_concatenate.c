#include <stdio.h>
#include <stdlib.h>

struct lista_item {
    float val;
    struct lista_item *next;
    struct lista_item *prev;
};
typedef struct lista_item lista_item;

typedef lista_item* lista; /* = NULL per lista vuota*/

lista lista_in0(lista, float);
lista lista_in1(lista, float);
lista lista_in(lista, int, float);
lista lista_append(lista, float);
lista lista_out0(lista);
lista lista_out1(lista);
lista lista_out(lista, int);
void lista_print(lista);
lista_item *lista_search(lista, int);

void main(){
    lista a = NULL, b = NULL, c, d;
    int i, n = 12;
    lista_item *p, *u;
    
    /* n inserimenti in testa
    * Costo: O(n)
    */
    for(i = 0; i < n; i++){
        a = lista_in0(a, i);
    }
    
    lista_print(a);
    
    p = lista_search(a, 41);
    if ( p != NULL){
     printf("%f\n", p->val);
    }
    
    a = lista_in1(a, 100);
    lista_print(a);
    
    b = lista_in0(b, 200);
    b = lista_in1(b, 210);
    b = lista_in(b, 2, 250);
    b = lista_in(b, 1, 300);
    b = lista_in(b, 0, 0);
    lista_print(b);
    
    /*
    * n inserimenti n coda,
    * costo n*n
    */
    c = NULL;
    for(i = 0; i < n; i++){
        c = lista_append(c, 100+i);
    }
    lista_print(c);
    
    /*
    * Ottimizzazione della procedura che insierisce n elementi incoda.
    * Mantenendo un puntatore all'ultimo elemento aggiungere un nuovo
    * in coda richiede tempo costante quindi la procedura
    * ha costo lineare.
    */
    d = NULL;
    for(i = 0; i <n; i++){
        if (i == 0){
            d = lista_in0(d, 200+i);
            u = d;
        } else {
            u = lista_in1(u, 200+i);
            u = u->next;
        }
    }
    lista_print(d);
    
    d = lista_out( d, 6 );
    
    while( n >= 0 ){
        d = lista_out( d, n );
        lista_print( d );
        n--;
    }
}

/*
* Data una lista `a` ed un valore `v`, aggiunge un nuovo elemento con valore `v` in testa
* (in posizione 0) della lista `a`; restituisce la lista modificata
* Costo computazionale costante
*/
lista lista_in0(lista a, float v) {
    lista_item *p = malloc(sizeof(lista_item));
    
    if (p == NULL){
        return a;
    }
    
    p->val = v;
    p->prev = NULL;
    p->next = a;
    if (a != NULL){
        a->prev = p;
    }
    
    return p;
}

/*
* Data una lista `a` ed un valore `v`, aggiunge un nuovo elemento con valore `v` in posizione 1
* (seconda posizione) della lista.
* Restituisce la lista modificata.
* Precondizione: la lista non e' vuota (contiene almeno un elemento)
*/
lista lista_in1(lista a, float v){
    lista_item *p = malloc(sizeof(lista_item));
    
    if (p == NULL){
        return a;
    }
    
    p->val = v;
    p->prev = a;
    p->next = a->next;

    if ( a->next != NULL ){
        a->next->prev = p;
    }
    a->next = p;
    
    return a;
}

/*
* Data una lista `a` ed una posizione `pos`, ritorna il puntatore all'elemento in
* posizione `pos` della lista `a`.
* Ritorna NULL se `pos` non identifica una posizione valida nella lista.
* Costo computazionale O(n) nel caso peggiore, dove `n` e' la lunghezza della lista.
*/
lista_item *lista_search(lista a, int pos){
    lista_item *p = a;
    
    if (pos < 0){
        return NULL;
    }
    
    while ( pos > 0 && p != NULL){
        p = p->next;
        pos--;
    }
    
    return p;
}

/*
* Data una lista `a`, una posizione `pos` ed un valore `v`, aggiunge un nuovo elemento con valore
* `v` in posizione `pos`  della lista.
* Restituisce la lista modificata.
* Ritorna NULL se `pos` non identifica una posizione valida nella lista.
* Costo computazionale O(n) nel caso peggiore, dove `n` e' la lunghezza della lista.
*/
lista lista_in(lista a, int pos, float v){
    lista p;
    
    if ( pos == 0 ){
        return lista_in0(a, v);
    }
    
    p = lista_search(a, pos-1);
    
    if (p == NULL){
        return a;
    }
    
    p = lista_in1(p, v);
    
    return a;
        
}

/*
* Stampa i valori della lista in input. Il costo computazionale e' lineare
* nella lunghezza della lista.
*/
void lista_print(lista a){
    lista_item  *p = a;

    printf("===============\n");
    
    for( p = a; p !=NULL; p = p->next){
        printf("%f\n", p->val);
    }
  
}

/*
* Data una lista `a` ed un valore `v`, aggiunge un nuovo elemento con valore
* `v` in posizione in fondo alla lista.
* Restituisce la lista modificata.
* Costo computazionale O(n), dove `n` e' la lunghezza della lista.
*/
lista lista_append(lista a, float v){
    lista p = a;
    
    if ( p == NULL ){ /*lista vuota*/
        return lista_in0(a, v);
    }
    
    while ( p->next != NULL ){
        p = p->next;
    }
    
    p = lista_in1(p, v);
    
    return a;
}

/*
* Elimina il primo elemento dalla lista concatenata in input
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


/*
* Elimina il secondo elemento dalla lista concatenata in input
*/
lista lista_out1(lista a) {
    lista p;
    
    if ( a == NULL || a->next == NULL )
        return a;
    
    p = a->next; /* != NULL */
    a->next = p->next;
    if ( p->next != NULL ){
        p->next->prev = a;
    }
    free(p);
    return a;
}


/*
* Elimina l'elemento in posizione pos dalla lista concatenata in input
*/
lista lista_out(lista a, int pos){
    lista p;
    
    if ( pos == 0 ){
        return lista_out0(a);
    }
    
    p = lista_search(a, pos-1);
    
    if (p == NULL){
        return a;
    }
    
    p = lista_out1(p);
    
    return a;
}