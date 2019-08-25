#include<stdio.h>
void Quick(int tamanho,int vetor[tamanho], int inicio, int fim){
	
	int pivo, aux, i, j, meio;
	
	i = inicio;
	j = fim;
	
	meio = (int) ((i + j) / 2);
	pivo = vetor[meio];
	
	do{
		while (vetor[i] < pivo) i = i + 1;
		while (vetor[j] > pivo) j = j - 1;
		
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
		}
	}while(j > i);
	
	if(inicio < j) Quick(tamanho,vetor, inicio, j);
	if(i < fim) Quick(tamanho,vetor, i, fim);	

}

int main(){
	unsigned int testes,tamanho,limite,extra,aux1,aux2,aux3,menor;
	scanf("%d",&testes);
	
	while(testes > 0){
		scanf("%d %d %d",&tamanho,&limite,&extra);
		int vetor[tamanho];
		float aux_resposta[tamanho],resposta,velocidade;

		for(aux1 = 0; aux1 < tamanho; aux1++){
			scanf("%d",&aux2);
			vetor[aux1] = aux2;
		}
		Quick(tamanho,vetor,0,(tamanho-1));

		for(aux1 = 0; aux1 < tamanho; aux1++){
			if(limite > 0){
				velocidade = vetor[aux1]+extra;
				limite--;
			}
			else{
				velocidade = vetor[aux1];
			}
			aux_resposta[aux1] = 1/velocidade;
		}
		
		resposta = 0;
		for(aux1 = 0; aux1 < tamanho; aux1++){
			resposta+=aux_resposta[aux1];			
		}
		
		printf("%.2f\n",resposta);
		testes--;
	}
	return;
}