#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int n, branco, meio;
	while(scanf(" %d", &n)){
		if(!n){
			return 0;
		}

		if ((n%4) == 0){
			branco = 0;
		}
		else{
			branco = (((n/4)+1)*4) - n;
		}

		printf("Printing order for %d pages:\n", n);
		if (n == 1){
			printf("Sheet 1, front: Blank, 1\n");
		}else{
			for(int ini = 1, fim = branco+n, sheet = 1; ini < fim; ini++, fim--, sheet++){
				printf("Sheet %d, front: ", sheet);
				if (fim > n){
					printf("Blank, %d\n", ini);
				}
				else{
					printf("%d, %d\n", fim, ini);
				}

				ini++;
				fim--;

				printf("Sheet %d, back : ", sheet);
				if(fim > n){
					printf("%d, Blank\n", ini);
				}
				else{
					printf("%d, %d\n", ini, fim);
				}
			}
		}
	}
	return 0;
}