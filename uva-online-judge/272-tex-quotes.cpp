#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	char c;
	bool impar = true;
	while(scanf("%c", &c)!= EOF){
		if ( c == '"'){
			if (impar){
				printf("``");
			}
			else{
				printf("''");
			}
			impar = !impar;
		}
		else{
			printf("%c", c);
		}
	}
	return 0;
}