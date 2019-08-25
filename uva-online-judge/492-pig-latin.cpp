#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
	char c, palavra[1000];
	int count = 0;
	while(c = getchar()){
		if( c == EOF){
			//printf("fim de arquivo\n");
			return 0;
		}

		if (('z' >= c && c >= 'a') || ('Z' >= c && c >= 'A')){
			//printf("letra %c encontrada\n", c);
			palavra[count] = c;
			count++;
		}
		else{
			if(count){
				palavra[count] = '\0';
				if(palavra[0] == 'a' || palavra[0] == 'e' || palavra[0] == 'i' || 
				palavra[0] == 'o' || palavra[0] == 'u' || palavra[0] == 'A' ||
				palavra[0] == 'E' || palavra[0] == 'I' || palavra[0] == 'O' || 
				palavra[0] == 'U'){
					printf("%say",palavra);
				}
				else{
					printf("%s%cay",palavra+1, palavra[0]);
				}
				count = 0;
			}
			printf("%c",c);
		}
	}
	//printf("\n");
	return 0;
}
