#include <stdio.h>

int main (){
	int instancia,tamanho,cont,cont2;
	char aux;
	instancia = 0;
	scanf("%d",&tamanho);
	while(tamanho != 0){
		char alfabeto[26];
		int vetor[tamanho];
		char frase[tamanho];
		instancia ++;
		printf("Instancia %d\n",instancia);
		
		for(cont = 0; cont < 26; cont++){
			alfabeto[cont] = cont+65;
		}
		
		for(cont = 0; cont < tamanho; cont++){
			scanf("%d ",&cont2);
			vetor[cont] = cont2;
		}
		
		for(cont = 0; cont < tamanho; cont++){
			aux = alfabeto[vetor[cont]-1];
			frase[cont] = aux;
			for(cont2 = vetor[cont]-1; cont2 > 0 ;cont2 --){
				alfabeto[cont2] = alfabeto[cont2-1];				
			}
			alfabeto[0] = aux;
		}
		
		for(cont = 0; cont < tamanho; cont++){
			printf("%c",frase[cont]);
		}
		printf("\n\n");
		scanf("%d",&tamanho);
	}
	
	return 0;
}