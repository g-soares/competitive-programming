#include<stdio.h>
#include<algorithm>

#define MAX 252
#define INFINITO 99999999

using namespace std;

int resposta(int limR, int limB, int* roleta, int* bolas){
	int matriz[MAX/2][MAX];

	for(int i = 0; i < limR-1; i++){
		matriz[0][i] = bolas[0]*(roleta[i] + roleta[i+1]);
	}

	for(int i = 1; i < limB; i++){
		matriz[i][0] = matriz[i][1] = INFINITO;
		int aux = INFINITO;

		for(int j = 2; j < limR-1; j++){
			aux = min(aux, matriz[i-1][j-2]);
			if(aux == INFINITO){
				matriz[i][j] = INFINITO;
			}else{
				matriz[i][j] = aux + bolas[i]*(roleta[j]+roleta[j+1]);
			}
		}
	}

	return matriz[limB-1][limR-2];
}

int main(){
	//freopen("p5out.txt","w",stdout);
	int n, m, resp, roleta[MAX], bolas[MAX/2];
	scanf(" %d %d", &n, &m);

	while(n+m){
		for( int i = 0; i < n; i++){
			scanf(" %d", roleta+i);
		}

		for(int i = 0; i < m; i++){
			scanf(" %d", bolas+i);
		}

		resp = INFINITO;

		for(int i = 0; i < n; i++){
			int aux = resposta(n, m, roleta, bolas);
			resp = min(resp,aux);
			int auxFim = roleta[n-1];

			for(int j = n-1; j > 0 ; j--){
				roleta[j] = roleta[j-1];
			}

			roleta[0] = auxFim;
		}

		printf("%d\n",0-resp);
		scanf(" %d %d", &n, &m);
	}

	return 0;
}