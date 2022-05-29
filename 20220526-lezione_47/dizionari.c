#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* la dimensione dell'array di liste, valore fittizio
* scopo per test
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
lista_item *dizionario_search(dizionario, char*);
dizionario dizionario_in(dizionario, dict_item);
dizionario dizionario_out(dizionario, char*); /* implementare per casa */
void dizionario_mostra(dizionario);


lista lista_in0(lista, dict_item);
lista lista_out0(lista);
lista_item *lista_search_val(lista, char*);

void main( int n_args, char *args[]  ){
    dizionario d = dizionario_new();
    int i;
    dict_item e;
    lista_item *p;

    for( i = 1; i < n_args-1; i++){
        e.k = args[i];
        e.v = 1.0*strlen(args[i])/n_args;
        d = dizionario_in(d, e);
    }

    p = dizionario_search(d, args[n_args-1]);

    if ( p == NULL ){
        printf("%s  non appartiene al dizionario\n", args[n_args-1]);
    } else {
        printf("Il valore associanto a %s e' %f\n", args[n_args-1], p->val.v );
    }

    dizionario_mostra(d);
    
    d = dizionario_out(d, args[n_args-1]);
    
    dizionario_mostra(d);
}

/*
 * Se la chiave e.k e' gia' presente nel dizionario, viene eseguito un
 * aggiornamento del suo valore con e.v; altrimenti e viene
 * aggiunto al dizionario 
 * */
dizionario dizionario_in(dizionario d, dict_item e) {
    int list_index = h(d, e.k);
    lista_item *p;

    /* _eventualmente_ l'elemento va inserito nella lista
     * d.a[list_index] */

    p = dizionario_search( d, e.k );

    if ( p == NULL ){
        /* e.k non e' una chiave, aggiungiamo e in d.a[list_index] */
        d.a[list_index] = lista_in0( d.a[list_index], e );
    } else {
        /* aggiorno il valore associato alla chiave e.k gia' in d*/
        p->val.v = e.v;
    }

    return d;
}

dizionario dizionario_out(dizionario d, char *k){
    int list_index = h(d, k);
    lista_item *p, *q;

    /* _eventualmente_ l'elemento va cancellato dalla lista
     * d.a[list_index] */

    p = dizionario_search( d, k );

    if ( p == NULL ){
        /* k non e' una chiave, niente da fare*/
        return d;
    }        
    /* cancellare il list_item puntato da p */
        
    if ( p == d.a[list_index] ){ 
        /* elimino il primo elemento della lista d.a[list_index]*/
        d.a[list_index] = lista_out0(d.a[list_index]);
    } else {
        q = p->prev;
        p = lista_out0(p);
        q->next = p;
        if(p != NULL){
            p->prev = q;
        }
    }
        
    return d;
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
    /*d.a = b[M];  perche non questo? */
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
* Ritorna il puntatore all'item del dizionario con chiave k, NULL se
* k non e' presente nel dizionario
*/
lista_item *dizionario_search(dizionario d, char* k){
    int list_index = h(d, k);
    lista_item *p;
    
    p = lista_search_val(d.a[list_index], k);
    
    return p;
}

/*
 * Molstra il contenuto delle liste del dizionario in input
 * */
void dizionario_mostra(dizionario d){
    int i;
    lista_item *p;

    printf("============================\n");
    for( i = 0; i < d.m; i++){
        /* stampare gli elementi di d.a[i] */
        printf("d[%d] = ", i);
        for( p = d.a[i]; p != NULL; p = p->next){
            printf("( %s, %f ), ", p->val.k, p->val.v);
        }
        printf("\n");
    }
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


lista lista_in0(lista a, dict_item e ) {
    lista_item *p = malloc(sizeof(lista_item));    
    int n;
    if (p == NULL){
        return a;
    }
    
    p->val = e;

    p->prev = NULL;
    p->next = a;
    if (a != NULL){
        a->prev = p;
    }

    return p;
}

lista lista_out0(lista a) {
    lista p = a;
    
    if ( a == NULL ) {
        return NULL;
    }
    
    a = a->next;
    
    if ( a != NULL){
        a->prev = NULL;
    }

    /*
     * Deallocazione di p->val possibile solo se questa
     * e' stata allocata dinamicamente.
     * Soluzione OK nel nostro caso perche' compatibile
     * con funzione lista_in0 
     * */
    free(p);
    return a;
}

