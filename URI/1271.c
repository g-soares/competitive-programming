#include<stdio.h>

main(){
	int casos,tamanho,inversoes,consultas,cont,aux1,aux2,aux3,aux4,aux5;
	scanf("%d",&tamanho);
	
	cont = 1;
	while(tamanho != 0){
		int vetor[tamanho];
		
		for(aux1 = 0; aux1 < tamanho; aux1++ ){
			vetor[aux1] = aux1+1;
		}
		
		scanf("%d",&inversoes);
		int inver[inversoes*2];
		aux4 = (inversoes*2)-1;
		for(aux1 = 0; aux1 < inversoes; aux1++){
			scanf("%d %d",&aux2,&aux3);
			inver[aux4] = aux3;
			aux4--;
			inver[aux4] = aux2;
			aux4--;
		}

		for(aux1 = 0; aux1 < inversoes*2; aux1++){
			aux2 = inver[aux1];
			aux1++;
			aux3 = inver[aux1];
			aux4 = aux3-aux2+1;
			int aux[aux4];
			for(aux5 = 0; aux5 < aux4; aux5++){
				aux[aux5] = vetor[aux3-1];
				aux3--;
			}
			
			for(aux5 = 0; aux5 < aux4; aux5++){
				vetor[aux2-1] = aux[aux5];
				aux2++;
			}
		}
		
		
		scanf("%d",&consultas);
		printf("Genome %d\n",cont);
		for(aux1 = 0; aux1 < consultas; aux1++){
			scanf("%d",&aux2);
			aux3 = vetor[aux2-1];
			printf("%d\n",aux3);
		}
		
		cont++;
		scanf("%d",&tamanho);
	}
	
	return;
}