#include <stdio.h>
#include <stdlib.h>

void print_array2d_bad(int a[][3], int nr){
    /* stampa matrici di 3 colonne, troppo specifica!*/
    /* il parametro nr indica il numero di righe*/
}

void print_array2d(int *a, int nc, int nr){
    int i, j;
    
    printf("==================\n");
    for(i = 0; i < nr; i++){
        for(j = 0; j < nc; j++){
            printf("%d, ", a[i*nc + j] );
        }
        printf("\n");
    }
}

void main(){
    int a[2][3] = {1, 9 };
    int b[] = {10,11,12,13};
    int c2[][2] = {20,21,22,23,24,25}; /* 2 colonne (e 3 righe)*/
    int c3[][3] = {20,21,22,23,24,25}; /* 3 colonne (e 2 righe)*/
    int d[] = {30, 31, 32, 33, 34, 35};
    int nr = 2, nc =  3;
    int nr_d = 3, nc_d = 2;
    int i, j, k;
    for(i = 0; i < nr; i++){
        for(j = 0; j < nc; j++ ){
            printf("%d, ", a[i][j]);
        }
        printf("\n");
    }
    k = 2;
    printf("%d\n", b[k]);
    
    
    for(i = 0; i < nr_d; i++){
        for(j = 0; j < nc_d; j++){
            printf("%d, ", d[i*nc_d + j] );
        }
        printf("\n");
    }
    
    print_array2d(d, 2, 3);
    print_array2d(d, 3, 2);
}