#include <stdio.h>

void QuickSortD( int X[],int IniVet,int FimVet){

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
		QuickSortD(X, IniVet, j);
	};
	if (i < FimVet) {
		QuickSortD(X, i, FimVet);
	};
}

void QuickSortC( int X[],int IniVet,int FimVet){

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
		QuickSortC(X, IniVet, j);
	};
	if (i < FimVet) {
		QuickSortC(X, i, FimVet);
	};
}

void main () {
int v[10];
int ta = sizeof(v) / sizeof(v[0]);
int i, r;

for(i=0; i<ta; i++)	{ 
		printf("\nInsira o numero para a posicao %d do vetor:  ", i);
		scanf("%d", &v[i]); 
	}
	
printf("\nDigite '1' para ordenacao crescente, e '2' para decrescente: ");
scanf("%d", &r);

if (r == 1) {
	QuickSortC(v, 0, 9);  
	printf("\nQuick Sort Crescente: \n\n");
}
else {
	QuickSortD(v, 0, 9);  
	printf("\nQuick Sort Decrescente: \n\n");
} 

for(i=0; i<ta; i++)	{ 
		printf("%d  ", v[i]); 
	}
}
