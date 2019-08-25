#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX 50010

int contador[MAX];

int pai[MAX], rk[MAX]={0};


int acha(int a){
	if (pai[a]==a)
		return a;

	int t = a;

	while (pai[t]!=t)
		t = pai[t];

	while (pai[a]!=a){
		int c = pai[a];
		pai[a] = t;
		a = c;
	}

	return t;
}


void une (int a, int b){
	a = acha(a);
	b = acha(b);

	if (rk[a] > rk[b]){
		pai[b] = a;
	}
	else if (rk[a] < rk[b])	{
		pai[a] = b;
	}
	else //rk igual
	{
		pai[a] = b;
		rk[b]++;
	}
}

int main(){
	//freopen("p10583out.txt","w",stdout);
	int n, m, a, b, resultado = 0,count = 1;
	while(scanf(" %d %d", &n, &m)){
		//printf("n -> %d m ->%d\n",n, m);
		if( n == 0 && m == 0){
			break;
		}

		memset(rk, 0, sizeof(rk));
		for(int i = 1; i <= n; i++){
			pai[i] = i;
			contador[i] = 0;
		}

		while(m--){
			scanf(" %d %d", &a, &b);
			if(acha(a) != acha(b)){
				une(a, b);
			}	
		}

		resultado = 0;
		for(int i = 1; i <= n; i++){
			//printf("%d",acha(i));
			if(!contador[acha(i)]){
				resultado++;
				contador[pai[i]]++;
			}
		}
		printf("Case %d: %d\n", count++, resultado);
	}
	return 0;
}