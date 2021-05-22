#include <stdio.h>
#include <stdlib.h>


void merge(int vec[], int vecSize) {  //recebe vetor e tamanho do vetor
	int mid, i, j, k;
	int* tmp;
	
	tmp = (int*) malloc(vecSize * sizeof(int));   //verifica se conseguiu alocar a memória
	if (tmp == NULL) {
		exit(1);
	}
	
	mid = vecSize / 2;    //mid = metade do tamanho do vetor vecSize
	
	i=0;
	j=mid;
	k=0;
	
	while (i < mid && j < vecSize){    //enquanto i<mid e j(que recebeu mid) < tamanho final do vetor
		if(vec[i] >= vec[j]){			// se vec[i] >= vec[j]
			tmp[k] = vec[i++];			
		}								//Senão
		else{							//		tmp[k] recebe vec[j] e j = j+1
			tmp[k] = vec[j++];
		}								
		++k;							//   k=k+1
	}
	
	if (i == mid){						// Se i = metade do vetor
		while (j < vecSize){			//		enquanto ( j < vecSize
			tmp[k++] = vec[j++];		//		tmp[k] = vec[j]
		}								// 		k=k+1
	}									// 		j=j+1
	else{								// Senão
		while (i < mid){				// Enquanto i < metade do vetor
			tmp[k++] = vec[i++];		// 		tmp[k] = vec[i]
		}								// 		k = k+1
	}									//		i = i+1
	
	for(i=0; i < vecSize; ++i){			// Para i=0 até i=vecSize faça
		vec[i] = tmp[i];				// 		vec[i] =tmp[i]
	}
	free(tmp);							// Libera tmp
}

void mergeSort (int vec[], int vecSize) {
	int mid, i;
	
	if (vecSize > 1){   				// Se o vetor tiver mais que uma posição
		mid = vecSize / 2;				//  mid = Metade do tamanho do vetor
		mergeSort(vec, mid);			//  faça o mergeSort com a 1ª metade do vetor
		mergeSort(vec + mid, vecSize - mid);	//  faça o mergeSort com a 2ª metade do vetor
		merge(vec, vecSize);			//  aplica a função merge
		
	}
}

void main () {
int v[10];
int ta = sizeof(v) / sizeof(v[0]);  // Determina o tamanho do Vetor
int i;

for(i=0; i<ta; i++)	{ 				// Grava os números do usuário em um vetor
		printf("\nInsira o numero para a posicao %d do vetor:  ", i);
		scanf("%d", &v[i]); 
	}

printf("\nVetor Original: \n\n\n");   //Imprime o vetor não organizdo

for(i=0; i<ta; i++)	{ 
		printf("%d  ", v[i]); 
	}

mergeSort(v, ta);             // Invoca a função

printf("\nMerge Sort (Resultado Final): \n\n");

for(i=0; i<ta; i++)	{    // Imprime o resultado final
		printf("%d  ", v[i]); 
	}
}
