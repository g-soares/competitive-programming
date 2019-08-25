#include <stdio.h>
#include <string.h>

using namespace std;

#define maxTam 140

int main(){
	char linha[maxTam];
	while(gets(linha)){
		int tam = strlen(linha);
		if(!tam){
			printf("\n");
		}
		else{
			int count = 0;
			for(int i = 0; i < tam; i++){
				if(linha[i] == '!'){
					printf("\n");
				}
				else if('9' >= linha[i] && linha[i] >= '0'){
					count += linha[i] - '0';
				}
				else if(linha[i] == 'b'){
					while(count--){
						printf(" ");
					}
					count = 0;
				}else{
					while(count--){
						printf("%c",linha[i]);
					}
					count = 0;
				}
			}
			printf("\n");
		}
	}
	return 0;
}