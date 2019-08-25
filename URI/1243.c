#include <stdio.h>
#include <string.h>

main() {
	int cont,aux,validade,npalavras,tamanho_p,tamanho_t;
	int media,aux2;
	char frase[100],palavra[100];
	while(fgets(frase,100,stdin)!= NULL){
		fflush(stdin);
		aux = tamanho_t = npalavras = 0;
		media = 0;
		frase[strlen(frase)-1] = ' ';
		frase[strlen(frase)] = '\0';

		for(cont = 0; cont < strlen(frase);cont++){
			if(frase[cont]!=' '){
				palavra[aux] = frase[cont];
				aux++;
			}else{
				aux2 = 0;
				palavra[aux] = '\0';
				tamanho_p = strlen(palavra);
				validade = 1;
				
				for(aux = 0; aux < tamanho_p; aux++){
					if(palavra[aux] == 46 && aux == tamanho_p - 1 && tamanho_p > 1){
						aux2++;
					}
					else if((palavra[aux]> 64 && palavra[aux] < 91)||(palavra[aux] > 96 && palavra[aux] <123)){
					}
					else{
						validade = 0;
					}
				}	
		
				if(validade == 1 && tamanho_p > aux2){
					if(aux2 > 0){
						tamanho_p--;
					}
					tamanho_t += tamanho_p;
					npalavras++;
				}
				aux = 0;			
			}

		}
		if(tamanho_t != 0){
			media = (tamanho_t/npalavras);
		}

		if(media<= 3){
			printf("250\n");
		}
		else if(media<= 5){
			printf("500\n");
		}
		else{
			printf("1000\n");
		}		
	}
	return;
}
