#include<stdio.h>
#include<string.h>

int qnt_casas(int tamanho){
	tamanho = tamanho/10;
	if(tamanho < 1){
		return 1;
	}
	else{
		return (1+qnt_casas(tamanho));
	}
}

main(){
	int inicio, fim, tamanho,aux1,aux2,aux3,aux4,resposta;
	while(scanf("%d %d",&inicio,&fim) == 2){
		resposta = fim - inicio +1;
		tamanho = qnt_casas(fim);
		char string[tamanho+1];
		for(aux1 = inicio; aux1 <= fim; aux1++){
			sprintf(string,"%i",aux1);
			aux4 = 0;
			for(aux2 = 0; aux2 < strlen(string)-1; aux2++){
				for(aux3 = aux2+1; aux3 < strlen(string); aux3++){
					if(string[aux2] == string[aux3]){
						resposta--;
						aux4 = 1;
						break;
					}
				}
				if(aux4 == 1){
					break;
				}
			}	
		}
		printf("%d\n",resposta);
	}
	return;
}