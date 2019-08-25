#include<stdio.h>
#include<string.h>

main(){
	char assinatura[8],sequencia[300001];
	int aux1,aux2,aux3,loop,cont,pulo[10],tamanho,achou;
	loop = 0;
	cont = 1;
	scanf("%s",assinatura);
	if(assinatura[0] == 48){
		loop = 1;
	}
	
	while(loop == 0){
		achou = 0;
		scanf("%s",sequencia);
		tamanho = strlen(assinatura);
		
		for(aux1 = 0; aux1 < 10; aux1++){
			pulo[aux1] = tamanho;
		}
		
		for(aux1 = 0; aux1 < tamanho-1; aux1++){
			pulo[assinatura[aux1]-48] = tamanho - aux1-1;
		}
		
		//bmhs
		for(aux1 = tamanho-1; aux1 < strlen(sequencia); aux1){
			aux3 = aux1;			
			//verifica se achou a palavra
			for(aux2 = tamanho-1; aux2 >= 0 ; aux2--){
				if(assinatura[aux2] != sequencia[aux3] ){
					aux1 += pulo[sequencia[aux3]-48];
					break;
				}
				aux3--;
				if(aux2 == 0){
					achou = 1;
				}
			}
			
			if(achou == 1){
				break;
			}
		}

		if(achou == 0){
			printf("Instancia %d\nfalsa\n",cont);
		}
		else{
			printf("Instancia %d\nverdadeira\n",cont);
		}
		
		scanf("%s",assinatura);
		if(assinatura[0]-48 == 0){
			loop = 1;
		}
		if(loop == 0){
			printf("\n");
		}
		cont++;
	}
	
	return;
}