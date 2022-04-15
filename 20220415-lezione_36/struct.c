#include <stdio.h>

struct punto {
		/* elenco dei campi*/
		char nome;
		float x, y;
		float z;
};
typedef struct punto punto; 


void print_punto(punto p){
	printf("%c: (%f, %f, %f)\n", p.nome, p.x, p.y, p.z);
}


void main(){
	struct punto p0, p2 = {'O', 0, 0, 0};
	punto p1;
	punto *pp = &p0;
	
	p0.nome = 'A';
	p0.x = 3.14;
	p0.y = 2.71;
	p0.z = 0;
	
	p1 = p0;
	p1.nome = 'B';
	p1.z = 1;
	
	printf("%c: (%f, %f, %f)\n", p0.nome, p0.x, p0.y, p0.z);
	printf("%c: (%f, %f, %f)\n", p1.nome, p1.x, p1.y, p1.z);
	print_punto( p2 );
	/* Accesso a campi utilizzando puntatore a struct */
	printf("pp campo x: %f;  pp campo y: %f\n", (*pp).x,  pp->y); 
	
}
