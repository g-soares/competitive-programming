#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

long long int mdc(long long int a, long long int b){
	long long int resto;
	do{
		resto = a%b;
		a = b;
		b = resto;
	}while(resto != 0);

	return a;
}

int fib(int n){
	int vetor[n+1];
	vetor[0] = 0;
	vetor[1] = 1;
	
	for(int i = 2; i <= n; i++){
		vetor[i] = vetor[i-1] + vetor[i-2];
	}

	return vetor[n];
}

int main(){
	//freopen("p2out.txt","w",stdout);
	long long int n, num, den, div;
	vector<long long int> fib, numerador, denominador;
	fib.push_back(0);
	fib.push_back(2);
	fib.push_back(3);

	for(int i = 3; i < 42; i++){
		fib.push_back(fib[i-1] + fib[i-2]);
	}
	//printf("passou fib\n");

	for(int i = 1; i < 42; i++){
		num = fib[i];
		den = pow(2, i);
		div = mdc(num, den);
		numerador.push_back(num/div);
		denominador.push_back(den/div);
	}
	//printf("passou den\n");

	while(scanf(" %lld", &n) > 0){
		printf("%lld/%lld\n",numerador[n-1],denominador[n-1]);
	}
}