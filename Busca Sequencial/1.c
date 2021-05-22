#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main () {
	setlocale (LC_ALL, "Portuguese");
	
	int V[10];
	int aux;
	int alfa;
	
	srand(time(NULL));
	
	V[0] = rand() % 100;
	
	for(aux=1;aux<10; aux++){
		alfa = rand() % 200;
		if(alfa > V[aux-1]){
			V[aux]=alfa;
		}
		else{
			V[aux]= alfa + V[aux-1] + 1;
		}
	}
	
	for(aux=0; aux<10; aux++){
		printf("%d\n", V[aux]);
	}
}
