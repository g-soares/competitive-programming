#include <stdio.h>
#include <math.h>

int main(){
	int casos;
	int cont,cont2,aux,parada;
	long long int resultado;
	scanf("%d",&casos);

	while( casos != 0){
		int rua[casos];

		for(cont =0; cont < casos;cont++){
			scanf("%d",&aux);
			rua[cont] = aux;
		}
		parada = 0;
		resultado = 0;
		
		for(cont = 1; cont < casos; cont++){
			if(rua[cont-1] < 0){
				resultado += abs(rua[cont-1]);
			}
			else{
				resultado += rua[cont-1];
			}
			rua[cont] += rua[cont-1];
		}

		printf("%lld\n",resultado);
		scanf("%d",&casos);
	}
	return 0;
}