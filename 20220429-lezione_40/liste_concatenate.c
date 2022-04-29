#include <stdio.h>
#include <stdlib.h>

struct list_item {
    float val;
    struct list_item *next;
    struct list_item *prev;
};
typedef struct list_item list_item;


void main(){
    list_item e0 = {7, NULL, NULL};
    list_item e1 = {5, NULL, NULL};
    list_item e2 = {6, NULL, NULL};
    list_item *p;
    
    e0.next = &e1;
    e1.prev = &e0;
    e1.next = &e2;
    e2.prev = &e1;
    
    p = &e0;
    
    while ( p != NULL ) {
        printf("%f\n", p->val);  /* equivalente a (*p).val   */
        p = p->next;
    }
    
    
}
