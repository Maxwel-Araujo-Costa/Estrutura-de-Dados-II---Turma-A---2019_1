//com base no Algoritmo MergeSort, crie um
//programa de ordenação que leia 20 números
//inseridos pelo usuários.
#include <stdio.h>
#include <stdlib.h>

void shellSort(int *vet, int size){
	int i, j, value;
	int h = 1;
	while (h<size){
		h = 3*h+1;
	}
	while (h > 1){
		h /= 3;
		for(i = h; i < size; i++){
			value = vet[i];
			j = i - h;
			while (j >= 0 && value < vet[j]){
				vet [j + h] = vet[j];
				j -= h;
			}
			vet[j + h] = value;
		}
	}
}

void main () {
int v[20];
int ta = sizeof(v) / sizeof(v[0]);  
int i;

for(i=0; i<ta; i++)	{ 				
		printf("\nInsira o numero para a posicao %d do vetor:  ", i);
		scanf("%d", &v[i]); 
	}

printf("\nVetor Original: \n\n\n");   

for(i=0; i<ta; i++)	{ 
		printf("%d  ", v[i]); 
	}

shellSort(v, ta);             

printf("\nShell Sort (Resultado Final): \n\n");

for(i=0; i<ta; i++)	{    
		printf("%d  ", v[i]); 
	}
}
