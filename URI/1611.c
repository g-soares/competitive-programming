#include <stdio.h>
#include <stdlib.h>

int comparacao (const void *a, const void *b){
	return (*(int*)b - *(int*)a);
}

int main(){
	int testes, capacidade, andares, pessoas, resposta, aux;
	scanf("%d ", &testes);
	
	while(testes > 0){
		scanf("%d %d %d",&andares, &capacidade, &pessoas);
		int vetor[pessoas];
		
		for(aux = 0; aux < pessoas; aux++){
			scanf("%d", &vetor[aux]);
		}
		
		qsort(vetor,pessoas,sizeof(int),comparacao);
		resposta = 0;

		for(aux = 0 ; aux < pessoas; aux += capacidade){
			resposta += vetor[aux]*2;
		}
		printf("%d\n",resposta);
		testes--;
	}
	
	return 0;
}