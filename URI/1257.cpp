#include<stdio.h>
#include<string.h>

main(){
	int aux,cont,casos,linhas,resposta;
	char palavra[51];
	scanf("%d",&casos);
	
	while(casos > 0){
		scanf("%d",&linhas);
		resposta = 0;
		cont = 0;
		
		while(linhas > 0){
			scanf("%s",palavra);
			
			for(aux = 0; aux < strlen(palavra); aux++){
				resposta += palavra[aux]-65+cont+aux;
			}
			linhas--;
			cont++;
		}
		printf("%d\n",resposta);
		casos--;
	}

	return;
}