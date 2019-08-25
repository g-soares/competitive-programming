#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace	 std;

#define max 40

char s1[max], s2[max];

int decimal(char b[]){
	int decimal = 0;
	for(int i = strlen(b)-1, count = 0; i >= 0; i--, count++){
		decimal += (b[i]-'0')*pow(2,count);
	}
	return decimal;
}

int mdc(int a, int b){
	int resto;
	do{
		resto = a%b;
		a = b;
		b = resto;
	}while(resto != 0);
	return a;
}

int main(){
	int n;
	scanf(" %d", &n);
	for(int count = 1; count <= n; count++){
		scanf(" %s %s", s1, s2);
		//printf("s1 -> %d --- s2 -> %d\n",decimal(s1), decimal(s2));
		printf("Pair #%d: ", count);
		if(mdc(decimal(s1), decimal(s2)) > 1 ){
			printf("All you need is love!\n");
		}
		else{
			printf("Love is not all you need!\n");
		}
	}

	return 0;
}