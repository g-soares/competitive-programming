#include<stdio.h>
#include<cstring>
 
using namespace std;
 
#define MAX 100100
 
bool venceu[MAX], perdeu[MAX];
int arvore[MAX][26];
char entrada[MAX];
 
void buscaProfundidade(int raiz){
	bool folha = true;
	
	for(int i = 0; i < 26; i++){
		int atual = arvore[raiz][i];
		if(atual != -1){
			folha = false;
			buscaProfundidade(atual);
			venceu[raiz] = venceu[raiz] || !venceu[atual];
			perdeu[raiz] = perdeu[raiz] || !perdeu[atual];
		}
	}
 
	if(folha){
		perdeu[raiz] = true;
	}
}
 
int main(){
	int n, k, tam, raiz;
	tam = 0;
	raiz = 0;
 
	scanf(" %d %d", &n, &k);	
	memset(arvore, -1, sizeof(arvore));
	memset(venceu, false, sizeof(venceu));
	memset(perdeu, false, sizeof(perdeu));
	
	for(int i = 0; i < n; i++){
		scanf(" %s", entrada);
		int nivel = raiz;
		
		for(int j = 0; entrada[j] != '\0'; j++){
			int pos = entrada[j] -'a';
			if(arvore[nivel][pos] == -1){
				arvore[nivel][pos] = tam+1;
				tam++;
			}
			nivel = arvore[nivel][pos];
		}
	}
	
	buscaProfundidade(raiz);
 
	if(k == 1 && venceu[raiz]){
		printf("First\n");
	}else if( k == 1 && !venceu[raiz]){
		printf("Second\n");
	}else if(!venceu[raiz]){
		printf("Second\n");
	}else if(perdeu[raiz] && venceu[raiz]){
		printf("First\n");
	}else if(perdeu[raiz] && !venceu[raiz]){
		printf("Second\n");
	}else if(k%2 == 1 && venceu[raiz]){
		printf("First\n");
	}else if(k%2 == 1 && venceu[raiz]){
		printf("Second\n");
	}else{
		printf("Second\n");
	}
 
	return 0;
}