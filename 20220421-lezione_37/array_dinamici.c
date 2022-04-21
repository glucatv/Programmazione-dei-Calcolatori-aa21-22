#include <stdio.h>
#include <stdlib.h>

struct array_dinamico {
	float *a;
	int c;  /* capacita'  */
	int n;  /* dimensione */
};
typedef struct array_dinamico array_dinamico;

array_dinamico array_init();
array_dinamico array_append( array_dinamico ad, float e );
void array_print( array_dinamico ad );
array_dinamico array_insert( array_dinamico v, int p, float e); 
array_dinamico array_pop( array_dinamico v);
int array_empty( array_dinamico v );
    
void main(){
	int i;
	array_dinamico v = array_init(); /*  v = [] */
	v = array_insert(v, 0, -80);
    v = array_append( v, 3.14 );       /* v.append(3.14) */
	for (i = 1; i < 1000; i++){
		/*array_print(v);*/
		v = array_append( v, i*10+i );
	}
	v = array_insert(v, v.n, -8);
    v = array_insert(v, 90, -800);
	array_print( v );
    
    while( array_empty( v ) == 0 ){
        v = array_pop( v );
    }
    array_print( v );
}

/*
 * Ritorna un array_dinamico vuoto
 * */
array_dinamico array_init(){
	array_dinamico ad = { NULL, 0, 0 };
	return ad;
}

/*
 * Aggiunge un nuovo elemento in fondo all'array dinamico
 * */
array_dinamico array_append( array_dinamico ad, float e ){
    int i;
    float *b;
    if ( ad.n == ad.c ) {
        ad.c = 1 + 2*ad.c;
        b = realloc(ad.a, sizeof(float)*ad.c); /* O(n) */
        if (b == NULL){
            return ad;
        }
        ad.a = b;
    }
    ad.a[ad.n] = e;
    ad.n++;
    
    return ad;
}

void array_print( array_dinamico ad ){
	int i;
	printf("c = %d; n = %d\n", ad.c, ad.n);
	for ( i = 0; i < ad.n; i++){
		printf("\t%d ----- %f\n", i, ad.a[i]);
	}
}

/*
Inserisce e in posizione p dell'array dinamico v.
Precondizione: p >= 0 p <= v.n
*/
array_dinamico array_insert( array_dinamico v, int p, float e) {
    int cur_pos;
    v = array_append( v, e ); /* viene creato il posto per e */
    cur_pos = v.n-1; /* ultima posizione (la nuova) */
    /* tutti gli elementi dalla posizione p in poi vengono spostati a destra di una posizione*/
    while ( cur_pos > p ){
        v.a[cur_pos] =  v.a[cur_pos-1]; 
        cur_pos--;
    }
    /* esce quando cur_pos diventa p, l'ultimo elemento spostato a destra e'
    quello in posizione p*/
    v.a[p] = e;
    return v;
    /*
    Il costo della funzione e' lineare in n-p (gli elementi da spostare), nel caso peggiore O(n)
    */
}

/*
Elimina un elemento dalla coda dell'array dinamico
*/
array_dinamico array_pop( array_dinamico v ){
    if (v.n == 0){
        return v; /* nulla da eliminare */
    }
    if ( 4*v.n < v.c ){ /* Fa in modo che l'array utilizzi almeno 1/4 della sua capacita'*/
        /* dimezziamo la capacita' di v */
        v.a = realloc(v.a, (v.c/2 + 1)*sizeof(float)); /*O(n) nel caso peggiore*/
        v.c = v.c/2 + 1;
    }
    v.n--; /* riducendo il campo n l'ultimo elemento risultera' virtualmente eliminato*/
    return v;
    
    /*
        Costi: prima di una realloc devono essere eseguite almeno n/2 pop a costo costante.
        Il costo complessivo delle n/2+1 operazioni e' n/2+n/2 quindi in media il costo di una
        operazione e' costante.
        
        Memoria: La quantita' di memoria non utilizzata non e' mai superiore a 3n.
    */
}

/*
Restituisce 1 se l'array dinamico e' vuoto, 0 altrimenti
*/
int array_empty( array_dinamico v ){
    if (v.n == 0){
        return 1;
    } else {
        return 0;
    }
}
