//1. Complete o programa Exemplo 1 e execute usando seu nome completo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//necess�rio para strlen

int main(int argc, char *argv[]) {
	char aux, vetor [50];
	int i, j, n, y, min;
	
	printf("Digite seu nome completo: ");
	scanf("%[^\n]s", vetor);//L� o nome incluindo os espa�os
	setbuf(stdin, NULL);	//limpa buffer
	n= strlen(vetor);		//retorna o n�mero de caracteres
	
	for (i = 0; i < n; i++){
     min = i;
     for (j = (i+1); j < n; j++){
       if(vetor[j] < vetor[min])
         min = j;
     }
     if (vetor[i] != vetor[min]){
       aux = vetor[i];
       vetor[i] = vetor[min];
       vetor[min] = aux;
     }
 	}

	printf("\n %s", vetor);
	return 0;
}
