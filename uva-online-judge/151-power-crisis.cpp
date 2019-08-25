#include <stdio.h>
#include <string.h>

using namespace std;

#define maxR 110
#define headquarters 12
bool desligado[maxR];

bool verifica(int ini, int fim){
	if (ini == fim && ini == headquarters){
		return true;
	}
	else if(ini == fim){
		return desligado[ini];
	}
	else if (ini == headquarters){
		return verifica(ini+1, fim);
	}
	else{
		return desligado[ini] && verifica(ini+1,fim);
	}
}

int prox(int intervalo,int ini,int limite){
	if (intervalo == 0){
		return ini;
	}
	int aux = ini;
	do{
		aux = (aux+1)%limite;
	}while(desligado[aux]);

	return prox(intervalo-1, aux, limite);
}

int main(){
	int m,intervalo, proximo, atual;
	scanf(" %d", &m);
	while(m != 0){
		//printf("m ->%d\n", m );
		for (intervalo=1, desligado[headquarters] = false; !desligado[headquarters]; intervalo++){
			memset(desligado, false, maxR);
			//printf("intervalo -> %d\n", intervalo );

			for (atual = 0; true; atual){
				//printf("atual -> %d\n",atual );
				if (atual == headquarters){
					if (verifica(0, m-1)){
						desligado[headquarters] = true;
						printf("%d\n",intervalo);
					}
					break;
				}
				else{
					desligado[atual] = true;
					atual = prox(intervalo, atual, m);;
				}

			}
		}
		scanf(" %d", &m);
	}

	return 0;
}