#include <stdio.h>

int fib(int x,int *call){
	if(x == 0){
		*call+=1;
		return 0;
	}
	else if(x == 1){
		*call+=1;
		return 1;
	}
	else {
		*call+=1;
		return fib(x-1,call)+fib(x-2,call);
	}
}

void main(){
	int casos,valor,aux;
	int call;
	scanf("%d",&casos);
	
	while(casos > 0){
		call = 0;
		scanf("%d",&valor);
		if(valor == 0){
			printf("fib(0) = 1 calls = 0\n");
		}
		else if(valor == 1){
			printf("fib(1) = 1 calss = 1\n");
		}
		else{
			aux = fib(valor,&call);
			printf("fib(%d) = %d calls = %d\n",valor,call-1,aux);
		}
		casos --;
	}

}