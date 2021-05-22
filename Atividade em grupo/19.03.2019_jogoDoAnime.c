//Alterado por(integrantes do grupo): 
//MAXWEL ARAUJO COSTA, LEONARDO VICTOR DE SOUZA,e THIBOR RAMOS MISSIO

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct str_node node;

struct str_node{
    char info[40];
    node *yes;
    node *no;
    node *father;
    
};

node* root;

node* makeNode(char[]);
void addYes(node*,node*);
void addNo(node*,node*);
int isLeaf(node*);
int isNo(node*);
void showNode(node*);
void makeInitialTree();
node* whoAnime();
void addNewAnime(node*);


int main(int argc, const char * argv[]) {
    char op;
    node *p;
    
    makeInitialTree();
    
    do{
        p=whoAnime();
        printf("\nO anime eh %s?  ",p->info);
        do{
            printf("\nResponda S para sim ou N para nao: ");
            fflush(stdin);	 //limpar o buffer do teclado.
            scanf("%c",&op);
            fflush(stdin);
            op=toupper(op);
        }while(op!='S' && op!='N');
        
        if (op=='N')  addNewAnime(p);
        
        system("cls");
        printf("\n Umu! Vivendo e aprendendo!");
        
        printf("\nDeseja continuar (S para sim ou N para nao): ");
        scanf("%c",&op);
        op=toupper(op);
    }while(op!='N');
    return 1;
    
}

//verifica se um nó é uma folha
int isLeaf(node* p){
    if (p==NULL) return 0;
    
    if(p->yes==NULL && p->no==NULL) return 1;
    
    return 0;
}

//verifica se um nó está no lado não de um determinado pai
int isNo(node* p){
    if (p==NULL || p->father==NULL) return 0;
    
    if((p->father)->no==p) return 1;
    
    return 0;
}

//adiciona um nó quando a resposta é sim, o nó pai é father
void addYes(node* p,node* father){
    if( p==NULL ) return;
    
    father->yes=p;
    p->father=father;
}

//adiciona um nó quando a resposta é não, o nó pai é father
void addNo(node* p,node* father){
    if( p==NULL ) return;
    
    father->no=p;
    p->father=father;
}

//cria um nó com a informação passada como parâmetro
node* makeNode(char info[]){
    node* p;
    
    p=(node*)malloc(sizeof(node));
    
    p->yes=NULL;
    p->no=NULL;
    p->father=NULL;
    strcpy(p->info,info);
    
    return p;
}

//exibe a informação de um nó
void showNode(node* p){
    printf("\n%s",p->info);
}

//cria a árvore inicial
void makeInitialTree(){
    node *yes,*no;
    
    root=makeNode("\nO genero eh comedia? ");
    yes=makeNode("Konosuba");
    no=makeNode("Death Note");
    
    addYes(yes,root);
    addNo(no,root);
}

//tenta encontrar o anime a partir de uma árvore de decisão
node* whoAnime(){
	node *p=root;
    char op;
    
    while(p->no!=NULL && p->yes!=NULL){
    	printf("%s\n",p->info);
    	printf("Responda s(sim) ou n(nao): ");
   		scanf("%c",&op);
   		fflush(stdin);
    	if(op=='s'){
    		p = p->yes;	
		}
		if(op=='n'){
    		p = p->no;	
		}
		system("cls");
	}
    return p;	
}


//Acrescenta um novo anime na lista, como irmão de p
void addNewAnime(node* p){
	
    node *father, *anime, *question;
    char nameAnime[40],nameQuestion[40],op;
    
    printf("\nNeste caso qual eh o anime? ");
    gets(nameAnime);
    fflush(stdin);
    system("cls");
    printf("\nQual eh a pergunta que diferencia o %s de %s? \n",p->info,nameAnime);
    gets(nameQuestion);
    fflush(stdin);
    system("cls");
    printf("\nQual eh a resposta desejavel para %s ? ", nameAnime);
    scanf("%c",&op);
    fflush(stdin);
    system("cls");
    
    anime = makeNode(nameAnime);
    question = makeNode(nameQuestion);
    
    father = p->father;
    
    if(father->yes == p){
    	father->yes = question;
    	if(op =='s'){
    		addYes(anime,question);
    		addNo(p,question);
		}else{
			addYes(p,question);
			addNo(anime,question);
		}
	}
	if(father->no == p){
		father->no = question;
    	if(op =='s'){
    		addYes(anime,question);
    		addNo(p,question);
		}else{
			addYes(p,question);
			addNo(anime,question);
		}
	}    
}

