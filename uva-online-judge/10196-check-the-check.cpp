#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

#define max 10

typedef struct p{
	vector<pair<int, int>> damas;
	vector<pair<int, int>> peoes;
	vector<pair<int, int>> torres;
	vector<pair<int, int>> cavalos;
	vector<pair<int, int>> bispos; 
}pecas;

bool tabuleiro [max][max];
pair<int, int> reiB;
pair<int, int> reiP;

bool xequeCavalo(vector<pair<int, int>> cavalos, pair<int,int> rei){
	int tam = (int)cavalos.size();
	int resultado = false;
	if (!tam){
		return resultado;
	}

	for(int i = 0; i < tam && !resultado; i++){
		if(cavalos[i].first - 1 == rei.first){
			if(cavalos[i].second - 2 == rei.second || cavalos[i].second + 2 == rei.second){
				resultado = true;
			}
			/*if(resultado){
				printf("xeque rei %d %d e cavalo %d %d\n",rei.first, rei.second, cavalos[i].first, cavalos[i].second );
			}*/
		}
		else if(cavalos[i].first - 2 == rei.first){
			if(cavalos[i].second - 1 == rei.second || cavalos[i].second + 1 == rei.second){
				resultado = true;
			}
			/*if(resultado){
				printf("xeque rei %d %d e cavalo %d %d\n",rei.first, rei.second, cavalos[i].first, cavalos[i].second );
			}*/
		}
		else if(cavalos[i].first + 1 == rei.first){
			if(cavalos[i].second - 2 == rei.second || cavalos[i].second + 2 == rei.second){
				resultado = true;
			}
			/*if(resultado){
				printf("xeque rei %d %d e cavalo %d %d\n",rei.first, rei.second, cavalos[i].first, cavalos[i].second );
			}*/
		}
		else if(cavalos[i].first + 2 == rei.first){
			if(cavalos[i].second - 1 == rei.second || cavalos[i].second + 1 == rei.second){
				resultado = true;
			}
			/*if(resultado){
				printf("xeque rei %d %d e cavalo %d %d\n",rei.first, rei.second, cavalos[i].first, cavalos[i].second );
			}*/
		}
	}
	return resultado;
}

bool xequeBispo(vector<pair<int, int>> bispos, pair<int,int> rei){
	int tam = (int) bispos.size();
	bool resultado = false;

	if(!tam){
		return resultado;
	}

	for(int i = 0; i < tam && !resultado; i++){
		if(rei.first - bispos[i].first == rei.second - bispos[i].second){ // diagonal noroeste-sudeste
			//printf("O rei %d %d está na diagonal noroeste-sudeste do bispo %d %d\n",rei.first, rei.second, bispos[i].first, bispos[i].second );
			if(rei.first  < bispos[i].first){ // noroeste
				for(int x = rei.first+1, y = rei.second+1; x < bispos[i].first; x++, y++){
					resultado = resultado || tabuleiro[x][y];
				}
			}
			else{ //sudeste
				for(int x = rei.first-1, y = rei.second-1; x > bispos[i].first; x--, y--){
					resultado = resultado || tabuleiro[x][y];
				}
			}
			resultado = !resultado;
			/*if(resultado){
				printf("xeque rei %d %d e bispo %d %d\n",rei.first, rei.second,bispos[i].first, bispos[i].second );
			}*/
		}
		else if(rei.first - bispos[i].first == -1*(rei.second - bispos[i].second) ){ //diagonal nordeste-sudoeste
			//printf("O rei %d %d está na diagonal nordeste-sudoeste do bispo %d %d\n",rei.first, rei.second, bispos[i].first, bispos[i].second );
			if(rei.first < bispos[i].first){ //nordeste
				for(int x = rei.first+1, y = rei.second-1; x < bispos[i].first; x++, y--){
					resultado = resultado || tabuleiro[x][y];
				}
			}
			else{ //sudoeste
				for(int x = rei.first-1, y = rei.second+1; x > bispos[i].first; x--, y++){
					resultado = resultado || tabuleiro[x][y];
				}
			}
			resultado = !resultado;
			/*if(resultado){
				printf("xeque rei %d %d e bispo %d %d\n",rei.first, rei.second,bispos[i].first, bispos[i].second );
			}*/
		}
	}
	return resultado;
}

bool xequeTorre(vector<pair<int, int>> torres, pair<int,int> rei){
	int tam = (int) torres.size();
	bool resultado = false;

	if(!tam){
		return resultado;
	}

	for(int i = 0; i < tam && !resultado; i++){
		if(torres[i].first == rei.first){
			if(torres[i].second > rei.second){ //torre mais a direita
				for(int j = rei.second+1; j < torres[i].second; j++){
						resultado = resultado || tabuleiro[rei.first][j]; //retorna v se encontrar uma peça no caminho
				}
			}
			else{ // torre mais a esquerda
				for(int j = rei.second-1; j > torres[i].second; j--){
					resultado = resultado || tabuleiro[rei.first][j]; //retorna v se encontrar uma peça no caminho
				}
			}
			resultado = !resultado;
			/*if(resultado){
				printf("xeque rei %d %d e torre1 %d %d\n",rei.first, rei.second,torres[i].first, torres[i].second );
			}*/
		}
		else if(torres[i].second == rei.second){
			if(torres[i].first > rei.first){ // torre por baixo
				for(int j = rei.first+1; j < torres[i].first; j++){
					resultado = resultado || tabuleiro[j][rei.second]; //retorna v se encontrar uma peça no caminho
				}
			}
			else{
				for(int j = rei.first-1; j > torres[i].first; j--){
					resultado = resultado || tabuleiro[j][rei.second];
				}
			}
			resultado = !resultado;
			/*if(resultado){
				printf("xeque rei %d %d e torre2 %d %d\n",rei.first, rei.second,torres[i].first, torres[i].second );
			}*/
		}
	}

	return resultado;
}

bool xequeDama(vector<pair<int, int>> damas, pair<int,int> rei){
	return (xequeBispo(damas, rei) || xequeTorre(damas, rei));
}

bool xequePecas(pecas pe, pair<int,int> rei){
	return (xequeCavalo(pe.cavalos, rei) || xequeBispo(pe.bispos, rei) || xequeTorre(pe.torres, rei) || xequeDama(pe.damas, rei) );
}

bool xequeBrancas(pecas brancas){
	if(xequePecas(brancas, reiP)){
		return true;
	}

	int resultado = false;
	int tam = (int) brancas.peoes.size();
	
	if(tam){
		for(int i = 0; i < tam && !resultado; i++){
			if(brancas.peoes[i].first - 1 == reiP.first){
				if(brancas.peoes[i].second-1 == reiP.second || brancas.peoes[i].second+1 == reiP.second){
					resultado = true;
				}
			}
		}
	}

	return resultado;
}

bool xequePretas(pecas pretas){
	if(xequePecas(pretas, reiB)){
		return true;
	}

	int resultado = false;
	int tam = (int) pretas.peoes.size();

	if(tam){
		for(int i = 0; i < tam && !resultado; i++){
			if(pretas.peoes[i].first +1 == reiB.first){
				if(pretas.peoes[i].second-1 == reiB.second || pretas.peoes[i].second+1 == reiB.second){
					resultado = true;
				}
			}
		}
	}
	return resultado;
}

int main(){
	int jogo = 0;
	while(true){
		pecas pretas;
		pecas brancas;
		bool vazio = true;
		string entrada;

		memset(tabuleiro, false, sizeof(tabuleiro));
		jogo++;

		for(int i = 0; i < 8; i++){
			getline(cin, entrada);
			for(int j = 0; j < 8; j++){
				if(entrada[j] != '.'){
					vazio = false;
					tabuleiro[i][j] = true;
					if(entrada[j] == 'p'){
						pretas.peoes.push_back(make_pair(i,j));
					}else if(entrada[j] == 'P'){
						brancas.peoes.push_back(make_pair(i,j));
					}else if(entrada[j] == 'n'){
						pretas.cavalos.push_back(make_pair(i,j));
					}else if(entrada[j] == 'N'){
						brancas.cavalos.push_back(make_pair(i,j));
					}else if(entrada[j] == 'b'){
						pretas.bispos.push_back(make_pair(i,j));
					}else if(entrada[j] == 'B'){
						brancas.bispos.push_back(make_pair(i,j));
					}else if(entrada[j] == 'r'){
						pretas.torres.push_back(make_pair(i,j));
					}else if(entrada[j] == 'R'){
						brancas.torres.push_back(make_pair(i,j));
					}else if(entrada[j] == 'q'){
						pretas.damas.push_back(make_pair(i,j));
					}else if(entrada[j] == 'Q'){
						brancas.damas.push_back(make_pair(i,j));
					}else if(entrada[j] == 'k'){
						reiP.first = i;
						reiP.second = j;
					}else if(entrada[j] == 'K'){
						reiB.first = i;
						reiB.second = j;
					}
				}
			}
		}

		if(vazio){
			break;
		}

		/*for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				printf("%d ", tabuleiro[i][j]);
			}
			printf("\n");
		}*/

		if(xequeBrancas(brancas)){
			printf("Game #%d: black king is in check.\n", jogo);
		}else if(xequePretas(pretas)){
			printf("Game #%d: white king is in check.\n", jogo );
		}else{
			printf("Game #%d: no king is in check.\n", jogo);
		}
		cin.ignore();
	}
	return 0;
}