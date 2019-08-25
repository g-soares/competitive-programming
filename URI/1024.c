#include <stdio.h>
#include <string.h>

int main(){
	int n_linhas,tamanho, cont,parada;
	char vetor[1100];
	char letra;
	
	scanf("%d ",&n_linhas);
	
	while(n_linhas > 0){
		
		for(cont = 0; cont < 1100; cont++){
			vetor[cont] = 0;
		}
		
		parada = 0;
		cont = 0;
		while(parada == 0){
			letra = getchar();
			vetor[cont] = letra;
			cont++;
			if(letra == '\n'){
				parada = 1;
			}
		}

		cont = 0;
		letra = vetor[cont];
		while(vetor[cont] != '\n'){
			if((vetor[cont] > 64 && vetor[cont] < 91) 
			|| (vetor[cont] > 96 && vetor[cont] < 123)){
				vetor[cont]+=3;
			}
			cont++;
		}
		
		tamanho = strlen(vetor);
		tamanho--;
		char aux[tamanho];	
		int tam_aux = tamanho-1;
		strncpy(aux,vetor,tamanho);
		
		for(cont = 0; cont < tamanho; cont++ ){
			vetor[cont] = aux[tam_aux];
			tam_aux--;
		}
		
		for(cont = tamanho/2; cont < tamanho; cont ++){
			vetor[cont]--;
		}
		printf("%s",vetor);
		n_linhas--;
	}

	return 0;
}