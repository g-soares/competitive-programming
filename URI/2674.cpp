#include<stdio.h>
#include<math.h>

using namespace std;

bool ehPrimo(int n){
	if(n == 0 || n == 1){
		return false;
	}
	else if(n == 2){
		return true;
	}
	else if (n%2 == 0){
		return false;
	}

	for(int i = 3; i <= sqrt(n); i += 2){
		if(n%i == 0){
			return false;
		}
	}

	return true;
}

bool ehSuperPrimo(int n){
	while(n >= 10){
		int ultimoDigito = n%10;
		n = n/10;
		if(!ehPrimo(ultimoDigito)){
			return false;
		}
	}

	if(n == 2 || n == 3 || n == 5 || n == 7){
		return true;
	}

	return false;
}

int main(){
	//freopen("p1out.txt","w",stdout);
	int n;
	while(scanf("%d", &n) > 0){
		if(!ehPrimo(n)){
			printf("Nada\n");
		}
		else{
			if(ehSuperPrimo(n)){
				printf("Super\n");
			}
			else{
				printf("Primo\n");
			}
		}
	}
}