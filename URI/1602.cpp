#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX 2*1000010

using namespace std;

bool primos[MAX];
int vetor[MAX], respostas[MAX], n;

int main(){
	//freopen("p9out.txt","w",stdout);
	memset(vetor, 0 , sizeof(vetor));
	memset(primos, true, sizeof(primos));

	for(int i = 2; i < MAX; i++){
		
		if(primos[i]){
			vetor[i] = 2;

			for(int j = 2*i; j < MAX; j+= i){
				primos[j] = false;
				int count = 0;
				int tam = j;

				while(tam%i == 0){
					tam = tam/i;
					count++;
				}

				if(vetor[j] == 0){
					vetor[j] = count+1;
				}
				else{
					vetor[j] = vetor[j]*(count+1);
				}
			}
		}
	}

	respostas[1] = 0;
	for(int i = 2; i <= MAX; i++){
		respostas[i] = respostas[i-1];

		if(primos[vetor[i]]){
			respostas[i]++;
		}
	}

	while(scanf(" %d", &n) != EOF){
		printf("%d\n", respostas[n]);
	}

	return 0;
}