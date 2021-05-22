#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	int i,j;
	char v[10][20];
	char val[20];
	
	for(i=0; i<10; i++)	{
		printf("Informe o nome: ");
		fflush(stdin);
		scanf("%s", &v[i]);
	}
	for (i=0; i<=10; i++) {
		for(j=i; j<10; j++){
			if(strcmp(v[i], v[j]) >0){
				strcpy(val, v[i]);
				strcpy(v[i], v[j]);
				strcpy(v[j], val);
			}
		}
	}
}
