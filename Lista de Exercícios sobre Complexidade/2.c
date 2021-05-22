#include <stdio.h>
#include <stdlib.h>

void main () { 
	int V[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int x=0;
	int aux=0;
	int j=0;
	int i;
	
	printf("\nInsira um numero: ");
	scanf("%d", &x);
	
	
	do {
		for (i=0; i<=10; i++) {
			aux = V[i] + V[j];
			if (aux == x) {
				printf("\nO numero escolhido eh ighual a: V[%d] + V[%d]\n", i, j);
			//	return 1;   <--- encerra o for com apenas 1 resultado
			};
		};
		j++;
	}while (j <= 10);
};
