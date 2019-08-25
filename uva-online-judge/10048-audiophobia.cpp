#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define infinito 9999999

int matriz[110][110];

int main(){
	int c, s, q, aux1, aux2, aux3, count = 1;
	bool primeiro = true;
	//freopen("p10048out.txt","w",stdout);
	while(scanf(" %d %d %d", &c, &s, &q)){
		if( c == 0 && s ==0 && q == 0){
			break;
		}

		//memset(matriz, infinito, sizeof(matriz));
		for(int i = 1; i <= c; i++){
			for(int j = i; j <= c; j++){
				matriz[i][j] = matriz[j][i] = infinito;
			}
		}

		for(int i = 0; i < s; i++){
			scanf(" %d %d %d", &aux1, &aux2, &aux3);
			matriz[aux1][aux2] = matriz[aux2][aux1] = aux3;
		}

		for(int i = 1; i <= c; i++){
			for(int j = 1; j <= c; j++){
				for(int k = 1; k <= c; k++){
					/*if(matriz[i][j] > matriz[i][k] + matriz[k][j]){
						matriz[i][j] = matriz[j][i] = matriz[i][k] + matriz[k][j];
					}*/
					matriz[j][k] = matriz[k][j] = min(matriz[j][k], max(matriz[j][i], matriz[k][i]) );
				}
			}
		}

		/*for(int i = 1; i <= c; c++){
			for(int j = 1; j <= c; c++){
				printf("%d ", matriz[i][j]);
			}
			printf("\n");
		}*/

		if(!primeiro){
			printf("\n");
		}
		primeiro = false;
		printf("Case #%d\n",count++);
		for(int i = 1; i <= q; i++){
			scanf(" %d %d", &aux1, &aux2);
			//printf("matriz -> %d / infinito -> %d\n",matriz[aux1][aux2], infinito );
			if(matriz[aux1][aux2] == infinito){
				printf("no path\n");
			}
			else{
				printf("%d\n", matriz[aux1][aux2] );
			}
		}
	}
	return 0;
}