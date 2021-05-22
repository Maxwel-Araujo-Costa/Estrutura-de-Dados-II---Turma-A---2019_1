#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void main () {
	int i, ta, j, y, aux, x[10];
	ta = 10;
	
	for (y=0; y<10; y++) {
		printf("Por favor, o elemento %d do vetor: ", y);
		scanf("%d", &x[y]);
	}
	
	printf("Como ficou o vetor: ");
		for (y=0; y<10; y++) { printf(" %d,", x[y]);}
	
	for(i=1; i<ta; i++){
		aux = x[i];
		j=i-1;
		while ((j>=0) && (aux<x[j])) {
			x[j+1] = x[j];
			j=j-1;
		}
		x[j+1] = aux;
		printf("\n\nIteracao %d: ", i+1);
		for (y=0; y<10; y++) { printf(" %d,", x[y]);}
	}
}
