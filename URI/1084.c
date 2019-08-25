#include<stdio.h>

int main(){
	int tamanho,t_final, remove,indice,aux;
	scanf("%d %d",&tamanho,&remove);
	
	while (tamanho != 0 && remove != 0){
		char entrada[tamanho+1];
		char vetor[tamanho+1];
		t_final = tamanho-remove;
		scanf("%s",entrada);
		indice = 0;
		
		for(aux = 0; aux <= tamanho; aux++){
			while(indice > 0 && remove > 0 && vetor[indice-1] < entrada[aux]){
				indice--;
				remove--;
			}
			vetor[indice] = entrada[aux];
			indice++;
		}
		
		for(aux = 0; aux < t_final; aux++){
			printf("%c",vetor[aux]);
		}
		printf("\n");
		
		scanf("%d %d",&tamanho,&remove);
	}

	return 0;
}