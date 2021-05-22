//Exemplo 2
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese"); // permite o uso de acentos
	
	int i,j; //declara os inteiros
	char v[10][20]; //declara a matriz
	char val[20]; //declara o vetor
	
	for(i=0; i<10; i++)	{  //começa o primeiro loop
		printf("Informe o nome: "); //imprime menssagem que indica ao usuario a escrever.
		fflush(stdin); //limpa o buffer
		scanf("%s", &v[i]); // lê o que o usuário escreveu
	}
	for (i=0; i<=10; i++) { //inicia outro loop
		for(j=i; j<10; j++){ //inicia um loop dentro de outro loop
			if(strcmp(v[i], v[j]) >0){ //compara as strings presentes em cada elemento
				strcpy(val, v[i]); //salva a stringa a ser trocada, em um vetor auxiliar
				strcpy(v[i], v[j]); //começa a troca de strings
				strcpy(v[j], val); //termina a troca de strings
			}
		}
	}
	
	for(i=0; i<10; i++)	{  //começa o último loop
		printf("\n %s", v[i]); //imprime resultado ordenado
	}
}

