#include<stdio.h>

using namespace std;

int main(){
	//freopen("p8out.txt","w",stdout);
	int entrada[50010], n, max;
	scanf(" %d", &n);
	entrada[0] = entrada[n+1] = max = 0;

	for(int i = 1; i <= n; i++){
		scanf(" %d", entrada+i);
		if(entrada[i] > entrada[i-1]){
			entrada[i] = entrada[i-1]+1;
		}
	}

	for(int i = n; i > 0; i--){
		if(entrada[i] > entrada[i+1]){
			entrada[i] = entrada[i+1]+1;
		}
	}

	for(int i = 1; i <= n; i++ ){
		if(entrada[i] > max){
			max = entrada[i];
		}
	}

	printf("%d\n",max);
	return 0;
}