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

void main(){
	int i;
	array_dinamico v = array_init(); /*  v = [] */
	v = array_append( v, 3.14 );       /* v.append(3.14) */
	for (i = 1; i < 160; i++){
		array_print(v);
		v = array_append( v, i*10+i );
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
    float *b;
    int i;
    if ( ad.n == ad.c ) {
        ad.c = 1 + 2*ad.c;
        b = malloc(sizeof(float)*ad.c); /* O(1) */
        for(i = 0; i < ad.n; i++){ /* O(n) */ 
            b[i] = ad.a[i];
        }
        free(ad.a); /* O(1) */
        ad.a = b;
    }
    ad.a[ad.n] = e;
    ad.n++;
    
    return ad;
}

void array_print( array_dinamico ad ){
	int i;
	printf("c = %d; n = %d\n", ad.c, ad.n);
	/*for ( i = 0; i < ad.n; i++){
		printf("\t%d ----- %f\n", i, ad.a[i]);
	}*/
}
