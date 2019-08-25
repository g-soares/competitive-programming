#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <iterator>
#include <vector>
#include <sstream>
#include <algorithm> 
#include <iterator>

using namespace std;

#define maxCan 30
#define maxNome 90
#define maxVotos 1010

char nome[maxNome];
string linha;
int n,candidatos, eleitores, votos[maxVotos][maxCan];
map<int, string> mapa;

bool valido(int i){
	return mapa.find(i) != mapa.end();
}

int main(){
	scanf(" %d", &n);

	while(n--){
		mapa.clear();
		memset(votos, 0, sizeof(votos));
		scanf(" %d", &candidatos);

		for(int i = 1; i <= candidatos; i++ ){
			scanf(" %[^\n]s ", nome);
			mapa[i] = nome;
			//printf("candidato -> %s\n", mapa[i].c_str());
		}

		cin.ignore();
		eleitores = 0;
		while(getline(cin,linha)){
			int tam = linha.size();
			if(tam == 0){
				break;
			}
			//printf("votos ->%s\n", linha.c_str());

			istringstream auxLinha(linha);
			string voto;
			for(int i = 0; getline(auxLinha, voto, ' '); i++){
				votos[eleitores][i] = stoi(voto);
				//printf("%d ",votos[eleitores][i]);
			}
			//printf("\n");
			eleitores++;
		}

		/*for(int i = 0; i < eleitores; i++){
			for(int j = 0; j < candidatos; j++){
				printf("%d ", votos[i][j] );
			}
			printf("\n");
		}*/

		int ganhador = 0;
		bool empate = false;
		while(!ganhador && !empate){
			vector<pair<int,int>> contador;
			for(int i = 0; i <= candidatos; i++){
				contador.push_back(make_pair(0,i));
			}

			float total = 0;
			for(int i = 0; i < eleitores; i++){
				for (int j = 0; j < candidatos; j++){
					if(votos[i][j] > 0 && valido(votos[i][j])){
						//printf("voto do eleitor %d para o canditado %d\n",i, votos[i][j]);
						total++;
						contador[votos[i][j]].first ++;
						break;
					}
				}
			}

			sort(contador.begin(), contador.end());
			reverse(contador.begin(), contador.end());
			
			/*printf("-----votos----\n");
			for(int i = 0; i <= candidatos; i++){
				printf("%d %d\n", contador[i].first, contador[i].second);
			}

			printf("--------------\n");*/

			if(contador[0].first > total*0.5){
				//printf("%d > %f\n", contador[0].first, total*0.5);
				ganhador = contador[0].second;
			}
			else{
				int minimo = 0;
				for(int count = (int)contador.size() - 1; count >= 0; count--){
					//printf("testando candidato %d\n", count);
					if(valido(contador[count].second)){
						minimo = contador[count].first;
						//printf("canditado com o minimo -> %d\n",contador[count].second );
						break;
					}
				}

				empate = true;
				//printf("minimo -> %d\n", minimo);
				for(int i = 0; i <= candidatos; i++){
					if(valido(contador[i].second) && contador[i].first != minimo){
						empate = false;
						//printf("canditado %d teve %d votos e o mínimo é %d\n",contador[i].second, contador[i].first, minimo );
						break;
					}
				}

				if(!empate){
					for (int i = candidatos; i > 0 ; i--){
						if(valido(contador[i].second) && contador[i].first == minimo){
							//printf("canditado %d 	removido\n",contador[i].second );
							mapa.erase(contador[i].second);
						}
					}
				}/*else{
					printf("empate\n");
				}*/

			}
		}
		if(!empate){
			printf("%s\n",mapa[ganhador].c_str());
		}
		else{
			for(int i = 0; i <= candidatos; i++){
				if(valido(i)){
					printf("%s\n",mapa[i].c_str());
				}
			}
		}
		if(n){
			printf("\n");
		}
  }
  return 0;
}