#include <stdio.h>
#include <string.h>
//#include <map>

#define maxPLinha 16
//#define arestasPP 4

using namespace std;
//arestasPP -> N, E, S, W
bool mapaH[maxPLinha][maxPLinha];
bool mapaV[maxPLinha][maxPLinha];
int limite;
//int fcount[maxPLinha];

/*bool existeLinha(char t, int x1, int y1, int x2, int y2){
	bool resultado = true;
	if (t = 'h'){
		for(int i = 0, tam = x2 - x1; i < tam; i++){
			if (!mapa[x1+i][y1][1]){
				resultado = false;
				break;
			}
		}
	}
	else{
		for(int i =0, tam = y1 - y2; i < tam; i++){
			if(!mapa[x1][y1+i][2]){
				resultado = false;
				break;
			}
		}

	}
	return resultado;
}*/

int contar(int tam){
	int c = 0;
	for (int x = 0; x + tam < limite; x++){
		for (int y = 0; y + tam < limite; y++){
			bool existe = true;
			for(int i = 0; i < tam; i++){
				if (!(mapaH[x][y+i] && mapaH[x+tam][y+i] &&
					mapaV[x+i][y] && mapaV[x+i][y+tam])){
					existe = false;
				break;
				}
			}
			if (existe){
				c++;
			}
		}
	}
	return c;
}

/*bool verifica(){
	for (int x = 0; x <= limite; x++){
		if (fcount[x] > 0){
			return true;
		}
	}
	return false;
}*/

int main(){
	int count = 0, a, b, arestas, retorno;
	char h;
	while(scanf(" %d", &limite) != EOF){
		count++;
		if (count > 1){
			printf("\n");
			printf("**********************************\n");
			printf("\n");
		}

		memset(mapaH, false, sizeof(mapaH));
		memset(mapaV, false, sizeof(mapaV));
		//memset(fcount,0 ,sizeof(fcount));

		retorno = scanf(" %d", &arestas);
		while(arestas--){
			retorno = scanf(" %c %d %d", &h, &a, &b);
			//printf("%c %d %d\n", h, a ,b);
			if (h == 'H'){
				mapaH[a-1][b-1] = true;
			}
			else{
				mapaV[b-1][a-1] = true;
			}
		}

		//contar();

		printf("Problem #%d\n\n", count);
		/*if (verifica()){
			for(int i =1; i <= limite; i++){
				if (fcount[i] > 0){
					printf("%d square (s) of size %d\n", fcount[i], i);
				}
			}
		}
		else{
			printf("No completed squares can be found.\n");
		}*/
		bool existe = false;
		for(int tam = 1; tam <=limite; tam++){
			retorno = contar(tam);
			if (retorno > 0){
				printf("%d square (s) of size %d\n", retorno, tam);
				existe = true;
			}
		}
		if (!existe){
			printf("No completed squares can be found.\n");
		}
	}
	return 0;
}