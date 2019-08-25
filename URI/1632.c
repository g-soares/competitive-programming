#include<stdio.h>
#include<string.h>

main(){
	char palavra[16];
	int total,aux1,resp;
	scanf("%d",& total);
	while(total > 0){
		resp = 1;
		scanf("%s",palavra);
		int aux_resp[strlen(palavra)];
		
		for(aux1 = 0; aux1 < strlen(palavra); aux1++){
			if(palavra[aux1] == 'a'|| palavra[aux1] == 'A'){
				aux_resp[aux1] = 3;
			}
			else if(palavra[aux1] == 'e'|| palavra[aux1] == 'E'){
				aux_resp[aux1] = 3;
			}
			else if(palavra[aux1] == 'i'|| palavra[aux1] == 'I'){
				aux_resp[aux1] = 3;
			}
			else if(palavra[aux1] == 'o'|| palavra[aux1] == 'O'){
				aux_resp[aux1] = 3;
			}
			else if(palavra[aux1] == 's'|| palavra[aux1] == 'S'){
				aux_resp[aux1] = 3;
			}
			else{
				aux_resp[aux1] = 2;
			}
			resp = resp*aux_resp[aux1];
		}
		printf("%d\n",resp);
		total--;
	}
	return;
}