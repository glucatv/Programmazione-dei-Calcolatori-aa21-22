#include <stdio.h>
#include <stdlib.h>

struct matrice { 
    float *a; 
    int nr, 
    nc; 
}; 
typedef struct matrice matrice; 

matrice matrice_init(int nr, int nc);
void matrice_print(matrice m);

matrice matrice_init(int nr, int nc){ 
    matrice m; 
    m.a = malloc(sizeof(float)*nr*nc); 
    m.nr = nr;
    m.nc = nc; 
    for(int i = 0; i < m.nr*m.nc; i++) { 
        m.a[i] = 0; 
    } 
    return m; 
}

void matrice_print(matrice m) { 
    int i, j; 
    for(i = 0; i < m.nr; i++) { 
        for(j = 0; j < m.nc; j++) { 
            printf("%f, ", m.a[i*m.nc + j]);
        } 
        printf("\n"); }
} 

void main() { 
    matrice m = matrice_init(3, 2);
    matrice_print(m);
    
    int k = 5;
    int i = k/m.nc; /*indice riga in m dell'elemento in pos. k di m.a*/
    int j = k%m.nc; /*indice colonna in m dell'elemento in pos. k di m.a*/
}