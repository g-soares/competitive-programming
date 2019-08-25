#include<stdio.h>

main(){
	int casos;
	scanf("%d",&casos);
	while(casos > 0){
		int cidades,visiveis,cont1,cont2,cont3,resposta,inicio,saida;
		scanf("%d %d",&cidades,&visiveis);
		int matriz[cidades][cidades],verifica[cidades];
		for(cont1 = 0; cont1 < cidades; cont1++){
			verifica[cont1] = 0;
			for(cont2 = 0; cont2 < cidades; cont2++){
				matriz[cont1][cont2] = 0;
			}
		}
		for(cont1 = 0; cont1 < cidades; cont1++){
			matriz[cont1][cont1] = -1;
		}
		for(cont1 = 0;cont1 < visiveis; cont1++){
			scanf("%d %d",&cont2,&cont3);
			matriz[cont3][cont2] = 1;
			matriz[cont2][cont3] = 1;
		}
		inicio = resposta = 0;
		saida = 1;
		verifica[inicio] = 1;
		while(saida != 0){
			int custo = 999999;
			int proximo;
			for(cont1 = 0; cont1 < cidades; cont1++){
				if(verifica[cont1] == 1){
					for(cont2 = 0; cont2 < cidades; cont2++){
						if(matriz[cont1][cont2] != -1 && matriz[cont1][cont2] < custo && verifica[cont2] != 1){
							custo = matriz[cont1][cont2];
							proximo = cont2;
						}
					}
				}
			}
			resposta += custo;
			verifica[proximo] = 1;
						
			saida = 0;
			for(cont1 = 0; cont1 < cidades; cont1++){
				if(verifica[cont1] == 0){
					saida++;
				}
			}
		}
		printf("%d\n",resposta);
		casos--;
	}
	return;
}