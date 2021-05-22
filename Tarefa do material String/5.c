//1. Complete o programa Exemplo 1 e execute usando seu nome completo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//necessário para strlen

void Bubble_sort_D (char vetor[], int n){
    int k, j, aux;
    for (k = 1; k < n; k++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (vetor[j] < vetor[j + 1])
            {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void Bubble_sort_C (char vetor[], int n){
    int k, j, aux;
    for (k = 1; k < n; k++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}


int main(int argc, char *argv[]) {
	char aux, vetor [50];
	int i, j, n, y;
	
	printf("Digite seu nome completo: ");
	scanf("%[^\n]s", vetor);//Lê o nome incluindo os espaços
	setbuf(stdin, NULL);	//limpa buffer
	n= strlen(vetor);		//retorna o número de caracteres
	
	printf("\nVoce gostaria de uma ordenacao\n crescente(1) ou decrescente(2)?\n (responda com 1 ou 2):   ");
	scanf ("%d", &y);
	
	if(y == 1){Bubble_sort_C(vetor, n);}
	else {Bubble_sort_D(vetor, n);}
	
	printf("\n %s", vetor);
	return 0;
}
