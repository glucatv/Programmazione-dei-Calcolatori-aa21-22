#include <stdio.h>
#include <stdlib.h>

int *append(int *a, int *c, int *n, int e){
    int *b, i;
    if (*n == *c) {
        *c = (*c)*2;
        b = malloc((*c)*sizeof(int));
        for(i = 0; i < *n; i++){
            b[i] = a[i];
        }
        free(a);
        a = b;
    }
    a[*n] = e;
    (*n)++;
    
    return a;
}

void print_array_dinamico(int *a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d, ", a[i]);
    }
    printf("\n");
}

void main(){
    int *a;
    int c = 2;
    int n = 0;
    int i;
    a = malloc(c*sizeof(int));
    
    for(i = 0; i < 7; i++){
        a = append(a, &c, &n, i*10);
        print_array_dinamico(a, n);
        printf("%d, %d\n", n, c);
    }
    
    
}
