#include <stdio.h>
#include <stdlib.h>

struct array_item {
    char type; /* 'd' per int; 'f' per float; 'c' per char*/
    void *p;
};
typedef struct array_item array_item;

/*
q punta ad un elemento dell'array
*/
void array_set_int( array_item *q, int v ){
    q->type = 'd';
    if (q->p != NULL)
        free(q->p);
    q->p = malloc(sizeof(int));
    *((int*)(q->p)) = v;
}
void array_set_char( array_item *q, char v ){
    q->type = 'c';
    if (q->p != NULL)
        free(q->p);
    q->p = malloc(sizeof(char));
    *((char*)(q->p)) = v;
}
void array_set_float( array_item *q, float v ){
    q->type = 'f';
    if (q->p != NULL)
        free(q->p);
    q->p = malloc(sizeof(float));
    *((float*)(q->p)) = v;
}

void array_print( array_item a[], int n  ){
    int i;
    printf("======================\n");
    for(i = 0; i < n; i++){
        if ( a[i].type == 'c')
            printf("%c\n", *((char*)(a[i].p)) );
        else if ( a[i].type == 'd')
            printf("%d\n", *((int*)(a[i].p)) );
        else if ( a[i].type == 'f')
            printf("%f\n", *((float*)(a[i].p)) );
    }
}

void *array_assign_var(array_item *q, void *x){
    if (x != NULL)
        free(x);
    if (q->type == 'd'){
        x = malloc(sizeof(int));
        *((int*)x) = *((int*)q->p);
    } else if (q->type == 'f'){
        x = malloc(sizeof(float));
        *((float*)x) = *((float*)q->p);
    } else if (q->type == 'c'){
        x = malloc(sizeof(char));
        *((char*)x) = *((char*)q->p);
    } 
    return x;
}

void main(){
    int i;
    array_item a[3];
    int n = sizeof(a)/sizeof(void*);
    void *x = NULL;
    
    for( i = 0; i < n; i++){
        a[i].p = NULL;
    }
    
    /*  assegnare un valore*/
    array_set_int( a+0, 4);
    array_set_float( a+1, 3.14);
    array_set_char( a+2, 'x');
    
    array_print(a, n);
    
    array_set_float( a+2, 2.71);
    
    array_print(a, n);
    
    x = array_assign_var(a+0, x);
    printf("x = %d\n", *((int*)x));
    x = array_assign_var(a+1, x);
    printf("x = %f\n", *((float*)x));
    x = array_assign_var(a+2, x);
    printf("x = %f\n", *((float*)x));
}