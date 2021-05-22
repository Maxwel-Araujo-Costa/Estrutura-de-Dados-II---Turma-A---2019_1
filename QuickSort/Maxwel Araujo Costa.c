#include <stdio.h>

void QuickSort( int X[],int IniVet,int FimVet){

	int i, j, pivo, aux;
	
	i = IniVet;
	j = FimVet;
	
	pivo = X[(IniVet + FimVet) / 2];
	
	while(i < j){
		while (X[i] < pivo && i < FimVet) {
			i = i + 1;
		};
		while (X[j] > pivo && j > IniVet) {
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
int v[] = {33, 5, 14, 8, 42, 73, 11, 81, 54, 2, 23, 83, 63, 29, 7, 6};
int ta = sizeof(v) / sizeof(v[0]);
int i;

QuickSort(v, 0, 15);       //Dar o número da posição (na parte do IniVet e FimVet), não o valor inserido nela.

for(i=0; i<ta; i++)	{ 
		printf("%d  ", v[i]); 
	}
}
