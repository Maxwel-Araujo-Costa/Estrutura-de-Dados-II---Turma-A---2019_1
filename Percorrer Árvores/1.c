//*Programa para verificar entrada em duplicidade*//
#include <stdio.h>
#include <stdlib.h>

typedef struct stNo { // cria estrutura stNo: [*Esq[info]*Dir]
	int info;
	struct stNo *esq, *dir;
} tNo; //Declaração de tNo como estrutura stNo


tNo *cria_no() {
	tNo *p; //declara o ponteiro 'p'
	
	if ((p = (tNo *) malloc(sizeof(tNo))) == NULL) //Se o epaço disponível para 'p' for igual a NULO, execute
		return NULL; //Retorna NULO
	else {  //Caso contrário
		p->esq = NULL; p->dir = NULL; //'esq' e 'dir' recebem NULO
		return p; //retorna o valor de p
	}
}


tNo *cria_arvore (int x) {
	tNo *p; //declara o ponteiro 'p'
	
	p = cria_no (); //'p' recebe a função 'cria_no'
	if (p) { //Se 'p' não for nulo
		p->info = x; //'info' recebe 'x', como valor
		return p; //retorna o valor de p
	}
	else { //Caso contrário
		puts("Faltou espaco para alocar no."); //envia uma menssagem
		exit(1); //Termina o programa
	}
}


void pos_esq(tNo *p, int x) {
	tNo *q; //declara o ponteiro 'q'
	
	if (p->esq) //se 'esq' não for nulo
		puts ("Operacao de insercao a esquerda ilegal."); //envia uma menssagem
	else { //Caso contrário
		q = cria_arvore(x); // 'q' recebe a função cria_arvore, com 'x' como parâmetro
		p->esq = q; //'esq' recebe 'q' como valor
	}		
}

void pos_dir(tNo *p, int x) {
	tNo *q; //declara o ponteiro 'q'
	
	if (p->dir) //se 'dir' não for nulo
		puts ("Operacao de insercao a esquerda ilegal."); //envia uma menssagem
	else { //Caso contrário
		q = cria_arvore(x); // 'q' recebe a função cria_arvore, com 'x' como parâmetro
		p->dir = q; //'esq' recebe 'q' como valor
	}		
}


int main () {
	tNo *raiz, *p, *q;   //declara os ponteiros
	int num;     //declara a variável num
	raiz = NULL;   //"raiz" recebe NULO como valor
	do {           //do = repita
		printf("Insira um numero:  "); //envia uma menssagem
		scanf("%d", &num); // lê a resposta do usuário 
		
		if(!raiz) raiz = cria_arvore(num); // Se raiz for igual a zero ou nulo, ela recebe o valor de cria_arvore com num como parâmetro
		else {   //se não, realize:
			q = raiz; p = raiz;  //as variáveis 'q' e 'p' recebem 'raiz' como valor
			
			while (num != p->info && q != NULL) {  //enquanto 'num' for diferente da variável 'info' (que pertence ao tipo heterogêneo tNo), e enquanto 'q' for diferente de NULO
				p = q;   //'p' recebe o valor de 'q'
				if(num < p->info) //Se 'num' for menor do que a variável 'info', realize
					q = p->esq; // 'q' recebe a variável 'esq', através do ponteiro 'p'
				else  // caso contrário
					q = p->dir; // 'q' recebe a variável 'dir', através do ponteiro 'p
			}
			if (num == p->info) //Se o conteúdo de 'num' for equivalente ao conteúdo de 'info', faça
				printf("O numero %d ja existe na arvore.\n", num); //envia uma menssagem, que mensiona o conteúdo de 'num
			else { /* vou inserir o numero da arvore */    //Caso contrário
				if (num < p->info) //Se 'num' for menor do que a variável 'info', faça
					pos_esq(p, num); //executa a função pos_esq, com os parâmetros 'p' e 'num'
				else  //Caso contrário
					pos_dir(p, num); //executa a função pos_dir, com os parâmetros 'p' e 'num'
			}
		}
	} while (num!=0); // enquanto a variável 'num' for diferente de 0.
}
