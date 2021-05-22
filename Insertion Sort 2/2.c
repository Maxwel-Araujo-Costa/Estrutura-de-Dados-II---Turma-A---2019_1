#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void main () {
	int i, ta, j, y;
	char v[10][20], val[20];
	ta = 10;
	
	for (y=0; y<10; y++) {
		printf("Por favor, o elemento %d do vetor: ", y);
		fflush(stdin); //limpa o buffer
		scanf("%s", &v[y]);
	}
	
	for(i=1; i<ta; i++){
		strcpy(val, v[i]);
		j=i-1;
		while ((j>=0) && strcmp(val, v[j]) < 0) {
			strcpy(v[j+1] , v[j]);
			j=j-1;
		}
		strcpy(v[j+1], val);
	}
	for(i=0; i<10; i++)	{  //começa o último loop
		printf("\n %s", v[i]); //imprime resultado ordenado
	}
}
