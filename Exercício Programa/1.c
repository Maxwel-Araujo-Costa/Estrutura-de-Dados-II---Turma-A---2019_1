#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main () {
	setlocale (LC_ALL, "Portuguese");
	
	int V[100];
	int aux;
	int alfa;
	int x;
	int T= 100;
	
	srand(time(NULL));
	
	V[0] = 1 + rand() % 4;
	
	for(aux=1;aux<100; aux++){
		alfa = 1 + rand() % 4;
		V[aux]=alfa + V[aux-1];
		
	}
	
	for(aux=0; aux<100; aux++){
		printf("%d, ", V[aux]);
	}
	
	printf("\n\nEntre com um valor, entre 1 e %d para ser procurado: ", V[99]);
	scanf("%d", &x);
	
	aux = PesquisaBinaria_int (V, x, T);
	
	if (aux==-1){ printf("\n\nValor inválido!");}
    else {printf("\n\n Posição do Vetor: %d", aux);}
}


int PesquisaBinaria_int ( int vet[], int chave, int Tam) {
	
	int inf = 0; //Limite inferior
	int sup = Tam-1; //Limite superior
	int meio;
	int i = 0;
	while (inf <= sup){
		meio = (inf + sup)/2; //Automaticamente truncado, pois as variáveis são do tipo int.
		printf("\n\nIteração %d, Limite inferior: %d, Meio: %d, Limite Superior: %d", i, inf, meio, sup);
		i++;
		if(chave == vet[meio])
			return meio;
		if(chave < vet[meio])
			sup = meio-1;
		else
			inf = meio + 1;
	}
	return -1; //Não encontrado
}

