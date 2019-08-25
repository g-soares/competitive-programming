#include<stdio.h>
#include<string.h>

main(){
	int linha,inicio,fim,fila,prioridade,pilha,tipo,numero,maior,cont,cont2;
	
	while(scanf("%d",&linha) == 1){
		int entrada[linha];
		inicio = fim = maior = 0;
		fila = prioridade = pilha = 1;
		
		while(linha > 0){
			scanf("%d %d",&tipo,&numero);
			if(tipo == 1){
				entrada[fim] = numero;
				if(numero > maior){
					maior = numero;
				}

				fim++;
			}
			else{					
				if(numero != entrada[inicio]){
					fila = 0;
				}
				
				if(numero != entrada[fim-1]){
					pilha = 0;
				}
				
				for(cont = 0; cont < fim; cont++){
					if(entrada[cont] == numero){
						cont2 = cont;
						break;
					}
				}
				
				for(cont = cont2; cont < fim-1; cont++){
					entrada[cont] = entrada[cont+1];
				}
			
				fim--;
				if(numero != maior){
					prioridade = 0;
				}else{
					maior = 0;
					for(cont = 0; cont < fim; cont++){
						if(entrada[cont]> maior){
							maior = entrada[cont];
						}
					}
				}
			}
			linha--;
		}
		
		if((fila+prioridade+pilha) > 1){
			printf("not sure\n");
		}
		else if((fila+prioridade+pilha) == 0){
			printf("impossible\n");
		}
		else if(fila == 1){
			printf("queue\n");
		}
		else if(prioridade == 1){
			printf("priority queue\n");
		}
		else{
			printf("stack\n");
		}
	}
	return;
}