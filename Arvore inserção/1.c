#include <stdio.h>
#include <stdlib.h>

struct arvore {
	char info;
	struct arvore *esquerda;
	struct arvore *direita;
};

struct arvore *raiz; 

struct arvore *subArvore(struct arvore *raiz, struct arvore *nodo, char info) {
	if (!nodo) {
		nodo = (struct arvore *) malloc(sizeof(struct arvore));
		if (!nodo) {
			printf("Sem memória\n");
			exit(0);
		}
		nodo->esquerda = NULL;
		nodo->direita = NULL;
		nodo->info = info;
		if(!raiz) return nodo; //primeira entrada
		if(info<raiz->info) raiz->esquerda=nodo;
		else raiz->direita = nodo;
		return nodo;
	}
	if (info<nodo->info) subArvore(nodo, nodo->esquerda, info);
	else subArvore(nodo, nodo->direita, info);
}

void print_arvore(struct arvore *nodo, int espaco) {
	int i;
	if (!nodo) return;
	print_arvore(nodo->direita, espaco +1);
	for (i=0; i< espaco; ++i) printf(" ");
	printf("%c\n", nodo->info);
	print_arvore(nodo->esquerda, espaco+1);
}

void main(void) {
	char letra[1];
	raiz = NULL; //inicializa a raiz
	do {
		printf("Insira uma letra: ");
		gets(letra);
		if(!raiz) raiz = subArvore(raiz, raiz, *letra);
		else subArvore(raiz, raiz, *letra);
	} while (*letra);
	print_arvore(raiz, 0);
}
