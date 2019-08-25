#include<stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

#define infinito 9999999
#define maxN 110

pair<double, double> pontos[maxN];
double matrizD[maxN][maxN], distancia[maxN];
bool livre[maxN];
int linha[maxN];

void prim(int arestas){
	int aux;
	double min;
	distancia[1] = 0;
	for(int i = 1; i <= arestas; i++){
		aux = 0;
		min = infinito;
		for(int j = 1; j <= arestas; j++){
			if(livre[j] && distancia[j] < min){
				aux = j;
				min = distancia[j];
			}
		}
		if(aux == 0){
			break;
		}
		livre[aux] = false;
		for(int j = 1; j <= arestas; j++){
			if(livre[j] && distancia[j] > matrizD[aux][j]){
				distancia[j] = matrizD[aux][j];
				linha[j] = aux;
			}
		}
	}
}

int main(){
	int n, arestas;
	bool primeiro = true;
	scanf(" %d", &n);
	while(n--){
		if(!primeiro){
			printf("\n");
		}

		scanf(" %d", &arestas);
		for(int i = 1; i <= arestas; i++ ){
			scanf("%lf %lf", &pontos[i].first, &pontos[i].second);
			distancia[i] = infinito;
			livre[i] = true;
		}

		for(int i = 1; i <= arestas; i++){
			matrizD[i][i] = 0;
			for(int j = i+1; j <= arestas; j++){
				matrizD[i][j] = matrizD[j][i] = sqrt( pow((pontos[i].first - pontos[j].first), 2) 
					+ pow((pontos[i].second - pontos[j].second), 2) );
			}
		}
		/*
		for(int i = 1; i <= arestas; i++){
			for(int j = 1; j <= arestas; j++){
				printf("%f ",matrizD[i][j]);
			}
			printf("\n");
		}*/

		prim(arestas);
		double resultado = 0;
		for(int i = 2; i <= arestas; i++){
			resultado += matrizD[i][linha[i]];
		}
		printf("%.2f\n",resultado);
		primeiro = false;
	}
	return 0;
}