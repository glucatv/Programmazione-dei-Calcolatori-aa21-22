#include <stdio.h>

int len( char a[] ){
    int len = 0;
    
    while( a[len] != '\0'){
        len++; /* len += 1 */
    }
    
    return len;
}

void main(){
    int x = 2;
    float y = x + 6.1;
    x =  y + 0.5;
    /* x =  (int)(y + 0.5); casting */
    printf("%d\n", x);
    
    if ( x < 10 ) {
        printf("x e' minore di 10\n");
    } else {
        printf("x non e' minore di 10\n");
    }
    
    if ( x < 10 && y >= 8){ /* and */
        /* TODO */
    }

    if ( x < 10 || y >= 8){ /* or */
        /* TODO */
    }
    
    if ( !(x < 10) ){ /* not */
        /* TODO */
    }

    int a = 21, b = 2, c;
    float d;
    
    c = a/b;
    /*d = (float)a/b;*/
    /* d = a/b + 0.0;   non va bene, int+float*/
    d = 1.0*a/b; /* d = a/(b + 0.0) OK */
    
    
    printf("Il valore di c %d\n", c);
    printf("Il valore di d %f\n", d);

    char s[] = "programma in C";
    
    int i = 4;
    
    s[i] = 'R';
    s[i+1] = '\n';
    s[i+3] = '\0';
    
    printf("%s\n", s);
    
    
    printf("%c%c\n", s[8], s[9]);
    
    int ln = 0;
    
    while( s[ln] != '\0'){
        ln++; /* len += 1 */
    }
    
    printf("la lunghezza della stringa e' %d\n", ln);
    
    printf("la lunghezza della stringa e' %d\n", len(s));
}