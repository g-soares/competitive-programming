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
		No* temp = (No*) malloc(sizeof(No));
		temp->numero = numero;
		temp->prox = l->primeiro->prox;
		l->primeiro->prox = temp; 
	}
}

void busca_largura(int atual,lista *grafo,int *visitado){
	int cont;
	No* temp = grafo[atual].primeiro;
	while(temp != NULL){
		if(visitado[temp->numero] == 0){
			visitado[temp->numero]++;
			busca_largura(temp->numero,grafo,visitado);
		}
		temp = temp->prox;
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

main(){
	int n,m,cont,a,b,c,resposta,saida;
	scanf("%d %d",&n,&m);
	while(n != 0 && m != 0){
		lista *grafo = (lista*) malloc(sizeof(lista)*n);
		int visitado[n];
		
		for(cont = 0; cont < n; cont++){
			inicia_lista(&grafo[cont]);
		}
		
		for(cont = 0; cont < m; cont++){
			scanf("%d %d %d", &a,&b,&c);
			a--;
			b--;
			insere_lista(&grafo[a],b);
			if(c == 2){
				insere_lista(&grafo[b],a);
			}
		}
		a = 0;
		resposta = 0;
		for(cont = 0; cont < n; cont++){
			if(grafo[cont].primeiro == NULL){
				a++;
				break;
			}
		}
		
		if(a == 0){
			saida = 0;
			resposta = 1;
			for(b = 0; b < n; b++){
				
				for(cont = 0; cont < n; cont++){
					visitado[cont] = 0;
				}
				visitado[b]++;
				busca_largura(b,grafo,visitado);
				
				for(cont = 0; cont < n; cont++){
					if (visitado[cont] == 0){
						saida = 1;
						resposta = 0;
					}
					visitado[cont] = 0;
				}
				if(saida != 0){
					break;
				}
			}
		}
		
		for(cont = 0; cont < n; cont++){
			destroi(&grafo[cont]);
		}
		free(grafo);
		
		printf("%d\n",resposta);
		scanf("%d %d",&n,&m);
	}
	return 0;
}