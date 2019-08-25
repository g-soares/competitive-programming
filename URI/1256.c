#include<stdio.h>
#include<stdlib.h>

typedef struct no {
	int numero;
	struct no* prox;
} No;

typedef struct{
	No* primeiro;
}lista;

void inicia_lista(lista *l){
	l->primeiro = NULL;
}

void insere_lista(lista *l, int numero){
	if(l->primeiro == NULL){
		l->primeiro = (No*) malloc(sizeof(No));
		l->primeiro->numero = numero;
		l->primeiro->prox = NULL;
	}
	else{
		No* atual = l->primeiro;
		while(atual->prox != NULL){
			atual = atual->prox;
		}
		atual->prox = (No*) malloc(sizeof(No));
		atual->prox->numero = numero;
		atual->prox->prox = NULL;
	}
}

void destroi(lista* l){
	No* atual = l->primeiro;
	while (atual != NULL){
		No* temp = atual->prox;
		free(atual);
		atual = temp;
	}
}
void imprime(lista *l){
	if(l->primeiro == NULL){
		printf("-> \\\n");
	}
	else{
		No* atual = l->primeiro;
		while(atual!= NULL){
			printf("-> %d ",atual->numero);
			atual = atual->prox;
		}
		printf("-> \\\n");
	}
}

main(){
	int casos,n_endereco,n_chave,chave,cont,aux;
	scanf(" %d ",&casos);
	while(casos > 0){
		scanf("%d %d",&n_endereco,&n_chave);
		lista* grafo = (lista*) malloc(sizeof(lista)*n_endereco*5);
		for(cont = 0; cont < n_endereco*5; cont++){
			inicia_lista(&grafo[cont]);
		}
		for(cont = 0; cont < n_chave; cont++){
			scanf("%d",&chave);
			aux = chave%n_endereco;
			insere_lista(&grafo[aux],chave);
		}
		for(cont = 0; cont < n_endereco; cont++){
			printf("%d ",cont);
			imprime(&grafo[cont]);
		}
		if(casos > 1){
			printf("\n");
		}
		for(cont = 0; cont < n_endereco*5; cont++){
			destroi(&grafo[cont]);
		}
		free(grafo);
		casos--;
	}	

	return;
}