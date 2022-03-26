#include <stdio.h>

void somma_uno(int x[], int n){
    int i = 0;
    
    while (i < n){
        x[i] += 1;
        i ++;
    }
    
    n = 0;
}


void main(){
    int i, a[10];
    int n = 10;
    
    i = 0;
    while (i < 10){
        a[i] = i*100;
        i ++;
    }
    
    somma_uno(a, n);
    
    i = 0;
    while (i < 10){
        printf("%d, ", a[i]);
        i ++;
    }
    printf("\n");
    
}