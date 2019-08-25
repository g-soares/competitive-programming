#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

#define maxN 70
#define limite 15

int main(){
	int d, dinheiro[limite], din, nPresentes, preco;
	char nomes[limite][limite];
	map<string, int> index;
	bool primeiro = true;

	while(scanf(" %d", &d) != EOF){
		index.clear();

		for (int i = 0; i < d; i++){
			scanf(" %s", nomes[i]);
			index[nomes[i]] = i;
			dinheiro[i] = 0;
		}

		char nome[limite], presenteado[limite];

		for (int i = 0; i < d; i++){
			scanf(" %s %d %d", nome, &din, &nPresentes);
			int pessoa = index[nome];
			
			if (nPresentes > 0){
				preco = din/nPresentes;
				dinheiro[pessoa] -= preco*nPresentes;
			}

			for (int j = 0; j < nPresentes; j++){
				scanf(" %s", presenteado);
				dinheiro[index[presenteado]] += preco;
			}
		}

		if(!primeiro){
			printf("\n");
		}

		for (int i = 0; i < d; i++){
			printf("%s %d\n",nomes[i], dinheiro[i] );
		}

		primeiro = false;
	}

	return 0;
}