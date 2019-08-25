#include<stdio.h>
#include<vector>
#include<map>
 
using namespace std;
 
int main(){
	//freopen("p13out.txt","w",stdout);
	int n, maior, menor, resp = 0;
	map<int, int> mapa;
	scanf(" %d", &n);
	int vetor[n];
 
	for(int i = 0; i < n; i++){
		scanf(" %d", vetor+i);
		mapa[vetor[i]] = mapa[vetor[i] - 1] + 1;
		if(resp < mapa[vetor[i]]){
			resp = mapa[vetor[i]];
			maior = vetor[i];
		}
	}
 
	menor = maior - resp + 1;
	printf("%d\n", resp);
	for(int i = 0; resp > 0; i++){
		if(vetor[i] == menor){
			printf("%d ", i+1);
			resp--;
			menor++;
		}
	}
	printf("\n");
	return 0;
}	