#include <stdio.h>
#include <stdlib.h>

struct list_item {
    float val;
    struct list_item *next;
    struct list_item *prev;
};
typedef struct list_item list_item;

typedef list_item* lista; /* = NULL per lista vuota*/

lista list_in0(lista, float);
void list_print(lista);
list_item *list_search(lista, int);

void main(){
    lista a = NULL;
    int i, n = 12;
    list_item *p;
    
    for(i = 0; i < n; i++){
        a = list_in0(a, i);
    }
    
    list_print(a);
    
    p = list_search(a, 41);
    if ( p != NULL){
     printf("%f\n", p->val);
    }
}

lista list_in0(lista a, float v) {
    list_item *p = malloc(sizeof(list_item));
    
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

void list_print(lista a){
    list_item  *p = a;
    
    for( p = a; p !=NULL; p = p->next){
        printf("%f\n", p->val);
    }
  
}

list_item *list_search(lista a, int pos){
    list_item *p = a;
    
    if (pos < 0){
        return NULL;
    }
    
    while ( pos > 0 && p != NULL){
        p = p->next;
        pos--;
    }
    
    return p;
}