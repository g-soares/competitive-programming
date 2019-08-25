#include <stdio.h>
#include <string.h>

int cs[100001];

int main(){
	int a, c;
	while(scanf(" %d %d", &a, &c)){
		if( a == 0 && c == 0){
			break;
		}

		int result = 0;
		
		for(int i = 0; i < c; i++){
			scanf(" %d", &cs[i]);	
		}

		for(int i = 1; i < c; i++){
			if(cs[i-1] > cs[i]){
				result += cs[i-1] - cs[i];
			}
		}
		result += a - cs[0];
		printf("%d\n",result);
	}
	return 0;
}