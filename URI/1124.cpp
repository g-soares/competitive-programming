#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main(){
	int l, c, r1, r2,r ;

	while(scanf(" %d %d %d %d", &l, &c, &r1, &r2) > 0){
		if(l+c+r1+r2 == 0){
			break;
		}
		r = r1+r2;
		if(min(l,c) < max(r1,r2)*2){
			printf("N\n");
		}/*else if(c-r1-r2 < 0){
			printf("N\n");
		}*//*else if(pow(2*r1 + 2*r2,2) > l*c){
			printf("N 2\n");
		}*/
		else{
						r1 += r2;
	        l -= r1; 
	        c -= r1;
	        
	        if(r1 * r1 > ((l * l) + (c * c))){
	        	printf("N\n");
	        }
	        else{
	        	printf("S\n");
	        }
		}
	}
	return 0;
}