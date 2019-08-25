#include<stdio.h>
#include<vector>
#include<map>
#include<string.h>
 
using namespace std;
 
map<long long int, long long int> vet1;
map<long long int, long long int> vet2;
 
int main(){
	//freopen("p14out.txt","w",stdout);
	long long int n, k, entrada, resp;
	scanf(" %lld %lld", &n, &k);
	resp = 0;
 
	while(n--){
		scanf(" %lld", &entrada);
		resp += vet1[entrada];
 
		if(entrada%k == 0){
			vet1[entrada*k] += vet2[entrada/k];
		}
		vet2[entrada]++;
	}
 
	printf("%lld\n",resp);
 
	return 0;
}