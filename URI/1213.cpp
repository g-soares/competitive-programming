#include<stdio.h>

using namespace std;

int main(){
	int n, aux, resp;
	while(scanf(" %d", &n) > 0){
		aux = resp = 1;
		while(aux%n > 0){
			aux =((10*aux)+1)%n;
			resp++;
		}
		printf("%d\n", resp);
	}

	return 0;
}