#include <stdio.h>
 
int main() {
    int aux1,resposta,teste;
	scanf("%d", &teste);
	while(teste != 0){
		int vetor[teste];
		resposta   = 0;
		
		for(aux1 = 0; aux1 < teste ; aux1++){
			scanf("%d", &vetor[aux1]);
		}
		
		for(aux1 = 1 ; aux1 < teste-1; aux1++){
			if(vetor[aux1-1] < vetor[aux1] && vetor[aux1+1] < vetor[aux1]){
				resposta++;
			}
			else if(vetor[aux1-1] > vetor[aux1] && vetor[aux1+1] > vetor[aux1]){
				resposta++;
			}
		}
		
		if(vetor[teste-1] < vetor[0] && vetor[1] < vetor[0]){
			resposta++;
		}
		else if(vetor[teste-1] > vetor[0] && vetor[1] > vetor[0]){
			resposta++;
		}
		
		if(vetor[teste-2] < vetor[teste-1] && vetor[0] < vetor[teste-1]){
			resposta++;
		}
		else if(vetor[teste-2] > vetor[teste-1] && vetor[0] > vetor[teste-1]){
			resposta++;
		}
		
		printf("%d\n",resposta);
		scanf("%d", &teste);
	}	
    return 0;
}