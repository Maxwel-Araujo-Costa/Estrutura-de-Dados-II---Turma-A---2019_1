#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main () {
	setlocale (LC_ALL, "Portuguese");
	
	int V[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int x;
	int T= 10;
	int aux=0;
	int Q=0;
	int i;
	
	printf("\nEntre com o valor a ser procurado: ");
	scanf("%d", &x);
	
	for(i=0; i<1;){
		printf("\nQual tipo de busca deseja executar? \nDigite 1 para bin�ria e 2 para recursiva: ");
		scanf("%d", &Q);
		if(Q==1){printf("\nBusca Bin�ria -->"); aux = PesquisaBinaria_int (V, x, T); i++;}
		if(Q==2){printf("\nBusca Recursiva -->"); aux = PesquisaBinaria_rec (x, V, 0, 9); i++;}
		if((Q != 1) && (Q != 2) ) {printf("\nComando n�o encontrado, tente novamente\n"); i--;}
	}
	
    if (aux==-1){ printf("\n\nValor nao encontrado");}
    else {printf("\n\nO n�mero a ser procurado est� na %d� posi��o.", aux+1);}
}

int PesquisaBinaria_int ( int vet[], int chave, int Tam) {
	
	int inf = 0; //Limite inferior
	int sup = Tam-1; //Limite superior
	int meio;
	while (inf <= sup){
		meio = (inf + sup)/2; //Automaticamente truncado, pois as vari�veis s�o do tipo int.
		if(chave == vet[meio])
			return meio;
		if(chave < vet[meio])
			sup = meio-1;
		else
			inf = meio + 1;
	}
	return -1; //N�o encontrado
}

int PesquisaBinaria_rec (int x, int v[], int esq, int dir) {
	
	// x => chave | v[] => vetor ordenado
	// esq => Limite inferior | dir => Limite superior
	
	int i=(esq + dir)/2; //automaticamente truncado, pois as variaveis s�o do tipo int
	if(v[i] == x)
		return i;
	if(esq >= dir)
		return -1;//N�o foi encontrado
	else
		if(v[i] < x)
			return PesquisaBinaria_rec (x, v, i+1, dir);
		else
			return PesquisaBinaria_rec (x, v, esq, i-1);
}
