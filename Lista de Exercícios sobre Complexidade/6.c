#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main () {
	setlocale (LC_ALL, "Portuguese");
	
	int V[30] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};;
	int aux;
	int x=0;
	
	printf("\nEntre com o valor a ser procurado: ");
	scanf("%d", &x);
	
	for (aux=0; aux<30; aux++){
		if(V[aux]==x) {
			printf("\nO número esta na %dº posição.", aux+1);
			break;
		}
	}
	
	if (aux==30) { printf("Valor nao encontrado"); }
}
