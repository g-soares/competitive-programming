#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

int matriz[2][101];

int main(){
	//freopen("p4out.txt","w",stdout);
	int teste, n, dano, peso, capacidade, resistencia, linha;
	scanf(" %d", &teste);
	while(teste--){
		memset(matriz, 0, sizeof(matriz));

		scanf(" %d", &n);
		for(int i = 1; i <= n; i++){
			scanf(" %d %d", &dano, &peso);
			linha = i%2;

			for(int j = 1; j < 101; j++){
				if(j < peso){
					matriz[linha][j] = matriz[(linha+1)%2][j];
				}
				else{
					matriz[linha][j] = max(matriz[(linha+1)%2][j], matriz[(linha+1)%2][j-peso] + dano);
				}
			}
		}

		scanf(" %d", &capacidade);
		scanf(" %d", &resistencia);
		if(matriz[n%2][capacidade] >= resistencia){
			printf("Missao completada com sucesso\n");
		}
		else{
			printf("Falha na missao\n");
		}
	}
	return 0;
}