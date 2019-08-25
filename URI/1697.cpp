#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

#define MAX 2*1000010

int main(){
	//freopen("p7out.txt","w",stdout);
	int t, n, aux;
	bool entrada[MAX];
	scanf(" %d", &t);

	while(t--){
		scanf(" %d", &n);
		memset(entrada, false, sizeof(entrada));

		for(int i = 0; i < n; i++){
			scanf(" %d", &aux);
			if(aux < MAX){
				entrada[aux] = true;
			}
		}

		if(entrada[1] == 0){
			printf("0\n");
		}
		else{
			for(int i = 2; i < MAX; i++){
				if(entrada[i] == 0){
					printf("%d\n",i-1);
					break;
				}
				else{
					for(int j = i+i; j < MAX; j+=i){
						entrada[j] = true;
					}
				}
			}
		}
	}

	return 0;
}