#include<stdio.h>
#include<vector>

using namespace std;

int main(){
	long long n, aux, passado, resp;
	scanf(" %lld", &n);

	while(n){
		vector<int> entrada;
		resp = 0;
		passado =0;
		for(long long i = 0; i < n; i++){
			scanf(" %d", &aux);
			entrada.push_back(aux);
		}

		for(long long  i = n-1; i >= 0; i--){
			resp += passado + entrada[i];
			passado += passado + entrada[i];
		}

		printf("%lld\n",resp);
		scanf(" %lld", &n);
	}
	return 0;
}