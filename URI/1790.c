#include<stdio.h>

int busca_profundidade(int inicio,int tamanho,unsigned int matriz[tamanho][tamanho],unsigned int visitou[tamanho]){
	int cont = 0;
	visitou[inicio] = 1;
	while(cont < tamanho){
		if(matriz[inicio][cont] == 1 || matriz[cont][inicio] == 1){
			if(visitou[cont] == 0){
				busca_profundidade(cont,tamanho,matriz,visitou);
			}
		}
		cont++;
	}
	visitou[inicio] = 2;
	return;
}

main(){
	unsigned int cidades, pontes;
	
	while(scanf("%d %d",&cidades,&pontes) == 2){
		unsigned int matriz[cidades][cidades];
		unsigned int visitou[cidades];
		unsigned int cont1,cont2,cont3,cont4,resposta,retorno;
		
		for(cont1 = 0 ; cont1 < cidades; cont1++){
			for(cont2 = 0; cont2 < cidades; cont2++){
				matriz[cont1][cont2] = 0;
			}
		}
		
		for(cont1 = 0; cont1 < pontes; cont1++){
			scanf("%d %d",&cont2,&cont3);
			matriz[cont2-1][cont3-1] = 1;
		}

		resposta = 0;
		for(cont1 = 0;cont1 < cidades; cont1++){
			for(cont2 = 0; cont2 < cidades; cont2++){
				if(matriz[cont1][cont2] == 1){
					
					for(cont3 = 0; cont3 < cidades; cont3++){
						visitou[cont3] = 0;
					}
					
					matriz[cont1][cont2] = 0;
					busca_profundidade(cont1,cidades,matriz,visitou);
					matriz[cont1][cont2] = 1;
					
					for(cont3 = 0;cont3 < cidades; cont3++){
						if(visitou[cont3] == 0){
							resposta++;
							break;
						}
					}
				}
			}
		}

		printf("%d\n",resposta);
	}
	return;
}