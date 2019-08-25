#include <stdio.h>
 
int main() {
int ncasos,casos, primeiro, vertices, arestas, ponto1, ponto2, linha, nrepitidas;
	scanf("%d", &ncasos);
	int resultado[ncasos];
	casos = ncasos;
	
	while(ncasos > 0){
		scanf("%d", &primeiro);
		scanf("%d %d", &vertices, &arestas);
		int matriz[arestas][2];
		int aux;
		
		for(aux = 0; aux < arestas; aux++ ){
			scanf("%d %d", &ponto1, &ponto2);
			matriz[aux][0] = ponto1;
			matriz[aux][1] = ponto2;
		}
		
		nrepitidas = arestas;
		for(linha = 0; linha < (arestas-1); linha++){
			for(aux = (linha+1); aux < arestas; aux ++){
				if((matriz[linha][0] == matriz[aux][0] || matriz[linha][0] == matriz[aux][1]) &&
				(matriz[linha][1] == matriz[aux][0] || matriz[linha][1] == matriz[aux][1])){
					nrepitidas--;
				}
			}
		}
		resultado[ncasos-1] = nrepitidas*2;
		ncasos--;
	}
	
	for(casos; casos > 0; casos--){
		printf("%d\n",resultado[casos-1]);
	}
    return 0;
}