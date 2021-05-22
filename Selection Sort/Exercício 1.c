#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	int x[10] = {};
	int i, j, aux, y, menor;
	
	for (y=0; y<10; y++) {
		printf("Por favor, o elemento %d do vetor: ", y);
		scanf("%d", &x[y]);
	}
		
	for(i=0;i<10;i++){
    	for(j=i+1;j<10;j++){
        	if(x[i]>x[j]){ 
	            aux=x[i];
	            x[i]=x[j];
	            x[j]=aux;
         	}
    	}
    	printf("\n\nIteracao %d: ", i+1);
		for (y=0; y<10; y++) { printf(" %d,", x[y]);}
    }
   return 0;	
}
