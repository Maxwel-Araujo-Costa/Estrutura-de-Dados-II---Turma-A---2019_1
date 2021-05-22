#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Fun��o que ir� criar a �rvore HeapSort */

void heapsort(int a[], int n){
	int i = n/2, pai, filho, x, j, cont=0;
		setlocale(LC_ALL, "Portuguese");
		
	for (;;){
		
		printf("\n\n%d� - ", cont+1); //Exibe as intera��es
		for(j=0; j<n; j++){
			printf("%d  ", a[j]);
		}
		if (i>0) { //Se I for maior do que zero
			i--; //Acrescenta I + 1
			x = a[i]; // A vari�vel X recebe o valor de A[i]
		}
		else //Se I fo menor ou igual a zero
		{
			n--;
			if (n == 0)
				return;
			x = a[n];
			a[n] = a[0];
		}
		
		pai = i;
		
		//Compara com o filho da esquerda
		filho = i*2;
		
		while (filho < n ){
			//Se o filho da esquerda for menor do que o da direita, troca o filho que ser� comparado.
			if ((filho + 1 < n) && (a[filho + 1] > a[filho]))
				filho++;
			if (a[filho] > x)
			{
				a[pai] = a[filho];
				pai = filho;
				filho = pai*2 + 1;
			}
			else
				break;
		}
		a[pai] = x;
		cont++;
	}
}



int main(int argc, char** argv){
	
	int i = 0;
	int n = 0;
	int b = 0;
	setlocale(LC_ALL, "Portuguese");
	
	printf("--------------------Ordenar N�meros-----------------------\n\n");
	printf("informe a quantidade de n�meros que deseja inserir: ");
	scanf("%i", &n);
	b = n;
	int vetor[n];
	
	printf("\n");
	
	for(i=0; i < n; i++){
		printf("\nInforme o  %i� n�mero: ", i+1);
		scanf("%i", &vetor[i]);
	}
	
	printf("\n\n");
	printf("------------------Sequ�ncia Inserida-----------------------\n\n");
	for(i=0;i<n;i++){
		printf(" %d ", vetor[i]);
	}
	
	printf("\n\n\n--------- Intera��es da Ordena��o ---------------\n\n");
	
	heapsort(vetor,b);
	
	printf("------------------ Valores Ordenados ---------------------\n\n");
	
	for(i=0;i<n;i++){
		printf(" %d ", vetor[i]);
	}
	
	getch();
	return 0;
}
