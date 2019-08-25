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
	else if(numero < l->primeiro->numero){
		No* temp = (No*) malloc(sizeof(No));
		temp->numero = numero;
		temp->prox = l->primeiro;
		l->primeiro = temp;
	}
	else{
		No* atual = l->primeiro;
		while(atual->prox != NULL && atual->prox->numero < numero){
			atual = atual->prox;
		}
		No* temp = (No*) malloc(sizeof(No));
		temp->numero = numero;
		temp->prox = atual->prox;
		atual->prox = temp; 
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

void resposta( lista *grafo,int *vetor, int espaco, int local){
	int cont;
	No* atual = grafo[local].primeiro;
	vetor[local] = 1;
	
	while(atual != NULL){
		for(cont = 0; cont < espaco; cont++){
			printf(" ");
		}
		printf("%d-%d",local,atual->numero);
		if( vetor[atual->numero] == 0){
			printf(" pathR(G,%d)\n",atual->numero);
			resposta( grafo,vetor,espaco+2, atual->numero);
		}
		else{
			printf("\n");
		}
		atual = atual->prox;
	}
}

main (){
	int caso, vertices, arestas, cont,testes,a,b;
	scanf("%d",&testes);
	caso = 1;
	while(caso <= testes){
		scanf("%d %d", &vertices, &arestas);
		lista* grafo = (lista*) malloc(sizeof(lista)*vertices);
		int vetor[vertices];
		
		for(cont = 0; cont < vertices; cont++){
			inicia_lista(&grafo[cont]);
		}
		
		for(cont = 0; cont < vertices; cont++){
			vetor[cont] = 0;
		}
		
		for(cont = 0; cont < arestas; cont++){
			scanf("%d %d",&a,&b);
			insere_lista(&grafo[a],b);
		}
		
		printf("Caso %d:\n",caso);
		for(cont = 0; cont < vertices; cont++){
			if(vetor[cont] == 0 && grafo[cont].primeiro != NULL){
				resposta(grafo, vetor,2,cont);
				printf("\n");
			}
		}
		
		for(cont = 0; cont < vertices; cont++){
			destroi(&grafo[cont]);
		}
		free(grafo);
		caso++;
	}
	
	return 0;
}