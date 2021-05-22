#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main (){
	setlocale (LC_ALL, "Portuguese");
	
			   //A,B,C,D,E,F,G,H,I,J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
	int A[26] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
	int aux;
	int alfa;
	int x= 18; //'R'
	int T= 26;
	
	aux = PesquisaBinaria_int (A, x, T);
	
    printf("\n\nA letra 'R' está na %dº posição.", aux+1);
}

int PesquisaBinaria_int ( int vet[], int chave, int Tam) {
	
	int  limInferior = 0; //Limite inferior
	int  limSuperior = Tam-1; //Limite superior
	int meio;
	int i = 0;
	while (limInferior <= limSuperior){
		meio = (limInferior + limSuperior)/2; //Automaticamente truncado, pois as variáveis são do tipo int.
		printf("\n\nIteração %d, Limite inferior: %d, Meio: %d, Limite Superior: %d", i, limInferior, meio, limSuperior);
		i++;
		if(chave == vet[meio])
			return meio;
		if(chave < vet[meio])
			limSuperior = meio-1;
		else
			limInferior = meio + 1;
	}
	return -1; //Não encontrado
}
