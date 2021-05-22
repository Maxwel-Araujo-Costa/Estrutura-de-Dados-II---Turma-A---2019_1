//*Programa para verificar entrada em duplicidade*//
#include <stdio.h>
#include <stdlib.h>

typedef struct stNo { // cria estrutura stNo: [*Esq[info]*Dir]
	int info;
	struct stNo *esq, *dir;
} tNo; //Declara��o de tNo como estrutura stNo


tNo *cria_no() {
	tNo *p; //declara o ponteiro 'p'
	
	if ((p = (tNo *) malloc(sizeof(tNo))) == NULL) //Se o epa�o dispon�vel para 'p' for igual a NULO, execute
		return NULL; //Retorna NULO
	else {  //Caso contr�rio
		p->esq = NULL; p->dir = NULL; //'esq' e 'dir' recebem NULO
		return p; //retorna o valor de p
	}
}


tNo *cria_arvore (int x) {
	tNo *p; //declara o ponteiro 'p'
	
	p = cria_no (); //'p' recebe a fun��o 'cria_no'
	if (p) { //Se 'p' n�o for nulo
		p->info = x; //'info' recebe 'x', como valor
		return p; //retorna o valor de p
	}
	else { //Caso contr�rio
		puts("Faltou espaco para alocar no."); //envia uma menssagem
		exit(1); //Termina o programa
	}
}


void pos_esq(tNo *p, int x) {
	tNo *q; //declara o ponteiro 'q'
	
	if (p->esq) //se 'esq' n�o for nulo
		puts ("Operacao de insercao a esquerda ilegal."); //envia uma menssagem
	else { //Caso contr�rio
		q = cria_arvore(x); // 'q' recebe a fun��o cria_arvore, com 'x' como par�metro
		p->esq = q; //'esq' recebe 'q' como valor
	}		
}

void pos_dir(tNo *p, int x) {
	tNo *q; //declara o ponteiro 'q'
	
	if (p->dir) //se 'dir' n�o for nulo
		puts ("Operacao de insercao a esquerda ilegal."); //envia uma menssagem
	else { //Caso contr�rio
		q = cria_arvore(x); // 'q' recebe a fun��o cria_arvore, com 'x' como par�metro
		p->dir = q; //'esq' recebe 'q' como valor
	}		
}


int main () {
	tNo *raiz, *p, *q;   //declara os ponteiros
	int num;     //declara a vari�vel num
	raiz = NULL;   //"raiz" recebe NULO como valor
	do {           //do = repita
		printf("Insira um numero:  "); //envia uma menssagem
		scanf("%d", &num); // l� a resposta do usu�rio 
		
		if(!raiz) raiz = cria_arvore(num); // Se raiz for igual a zero ou nulo, ela recebe o valor de cria_arvore com num como par�metro
		else {   //se n�o, realize:
			q = raiz; p = raiz;  //as vari�veis 'q' e 'p' recebem 'raiz' como valor
			
			while (num != p->info && q != NULL) {  //enquanto 'num' for diferente da vari�vel 'info' (que pertence ao tipo heterog�neo tNo), e enquanto 'q' for diferente de NULO
				p = q;   //'p' recebe o valor de 'q'
				if(num < p->info) //Se 'num' for menor do que a vari�vel 'info', realize
					q = p->esq; // 'q' recebe a vari�vel 'esq', atrav�s do ponteiro 'p'
				else  // caso contr�rio
					q = p->dir; // 'q' recebe a vari�vel 'dir', atrav�s do ponteiro 'p
			}
			if (num == p->info) //Se o conte�do de 'num' for equivalente ao conte�do de 'info', fa�a
				printf("O numero %d ja existe na arvore.\n", num); //envia uma menssagem, que mensiona o conte�do de 'num
			else { /* vou inserir o numero da arvore */    //Caso contr�rio
				if (num < p->info) //Se 'num' for menor do que a vari�vel 'info', fa�a
					pos_esq(p, num); //executa a fun��o pos_esq, com os par�metros 'p' e 'num'
				else  //Caso contr�rio
					pos_dir(p, num); //executa a fun��o pos_dir, com os par�metros 'p' e 'num'
			}
		}
	} while (num!=0); // enquanto a vari�vel 'num' for diferente de 0.
}
