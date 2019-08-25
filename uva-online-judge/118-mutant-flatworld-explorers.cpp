#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

#define maxCom 110
#define maxCoor 50

int x, y, d, maxX, maxY;
const int mudancasX[] = {0,1,0,-1};
const int mudancasY[] = {1,0,-1,0};
bool quedas[maxCoor][maxCoor];
char comandos[maxCom];


int mover(int pos, int tx, int ty, int direcao, int tam){
	x = tx;
	y = ty;
	d = direcao;
	int sx = x + mudancasX[d];
	int sy = y + mudancasY[d];
	if (pos == tam){
		//printf("terminou\n");
		return true;
	}
	else if (comandos[pos] == 'R'){
		//printf("comando %c da posicao %d\n",comandos[pos], pos );
		return mover(pos+1, tx, ty, (direcao+1)%4, tam);
	}
	else if (comandos[pos] == 'L'){
		//printf("comando %c da posicao %d\n",comandos[pos], pos );
		return mover(pos+1, tx, ty, (direcao+3)%4, tam);
	}
	else{
		if (sx < 0 || sx > maxX || sy < 0 || sy > maxY){
			if (quedas[tx][ty]){
				return mover(pos+1, tx, ty, direcao, tam);
			}
			else{
				quedas[tx][ty] = true;
				return false;	
			}
		}
		return mover(pos+1, sx, sy, direcao, tam);
	}
}

int main(){
	char direcao;

	scanf(" %d %d", &maxX, &maxY);
	while(scanf(" %d %d %c", &x, &y, &direcao) != EOF){
		scanf(" %s", comandos);

		if (direcao == 'N'){
			d = 0;
		}
		else if (direcao == 'S'){
			d = 2;
		}
		else if (direcao == 'E'){
			d = 1;
		}
		else if (direcao == 'W'){
			d = 3;
		}

		bool terminou = mover(0, x, y, d, (int)strlen(comandos));

		printf("%d %d", x, y);
		if (d == 0){
			printf(" N");
		}
		else if (d == 1){
			printf(" E");
		}
		else if (d == 2){
			printf(" S");
		}
		else if (d == 3){
			printf(" W");
		}

		if (!terminou){
			printf(" LOST\n");
		}
		else{
			printf("\n");
		}
	}

	return 0;
}