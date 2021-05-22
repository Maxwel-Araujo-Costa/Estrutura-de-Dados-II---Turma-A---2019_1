#include <stdio.h>

void QuickSort( int X[],int IniVet,int FimVet){

	int i, j, pivo, aux;
	
	i = IniVet;
	j = FimVet;
	
	pivo = X[(IniVet + FimVet) / 2];
	
	while(i < j){
		while (X[i] > pivo && i < FimVet) {
			i = i + 1;
		};
		while (X[j] < pivo && j > IniVet) {
		j = j - 1;
		}
		if (i <= j) {
		aux = X[i];
		X[i] = X[j];
		X[j] = aux;
		i = i + 1;
		j = j - 1;
		};
	};
	if (j > IniVet) {
		QuickSort(X, IniVet, j);
	};
	if (i < FimVet) {
		QuickSort(X, i, FimVet);
	};
}

void main () {
int v[10];
int ta = sizeof(v) / sizeof(v[0]);
int i;

for(i=0; i<ta; i++)	{ 
		printf("\nInsira o numero para a posicao %d do vetor:  ", i);
		scanf("%d", &v[i]); 
	}

QuickSort(v, 0, 9);       //Dar o n�mero da posi��o (na parte do IniVet e FimVet), n�o o valor inserido nela.

printf("\nQuick Sort Decrescente: \n\n");

for(i=0; i<ta; i++)	{ 
		printf("%d  ", v[i]); 
	}
}
