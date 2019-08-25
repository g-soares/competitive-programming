#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int orientacao(pair<int,int> x, pair<int,int> a, pair<int,int> b){
	return (a.first - x.first)*(b.second - x.second) - (b.first - x.first)*(a.second - x.second);	
}

vector<pair<int, int>> encontrarUltimaCamada(vector<pair<int, int>> pontos){
	int tam = pontos.size();
	int pont1 = 0;
	int pont2 = 0;
	vector<pair<int, int>> saida(2*tam);
	sort(pontos.begin(), pontos.end());

	for(int i = 0; i < tam; i++){
		while(pont1 >= 2 && orientacao(saida[pont1-2], saida[pont1-1], pontos[i]) < 0){
			pont1--;
		}
		saida[pont1] = pontos[i];
		pont1++;
	}

	pont2 = pont1+1;
	for(int i = tam-2; i >= 0; i--){
		while(pont1 >= pont2 && orientacao(saida[pont1-2], saida[pont1-1], pontos[i]) < 0){
			pont1--;
		}
		saida[pont1] = pontos[i];
		pont1++;
	}

	saida.resize(pont1);

	return saida;
}

int main(){
	int n, resp, tam;

	while(scanf(" %d", &n)){
		if(n == 0){
			break;
		}

		vector<pair<int, int>> pontos(n);
		resp = 0;
		tam = n;

		for(int i = 0; i < n; i++){
			scanf(" %d %d", &pontos[i].first, &pontos[i].second);
		}

		while(tam > 0){
			resp++;
			vector<pair<int,int>> ultCamda = encontrarUltimaCamada(pontos);
			vector<pair<int,int>> novo;

			for(int i = 0; i < tam; i++){
				if(find(ultCamda.begin(), ultCamda.end(), pontos[i]) == ultCamda.end()){
					novo.push_back(pontos[i]);
				}
			}

			pontos = novo;
			tam = pontos.size();
		}

		if(resp%2){
			printf("Take this onion to the lab!\n");
		}else{
			printf("Do not take this onion to the lab!\n");
		}
	}

	return 0;
}