#include<stdio.h>
#include<math.h>
#include <algorithm> 
 
using namespace std;
 
int main(){
	long long n, p1 = 0, p2 = 1;
	scanf(" %lld", &n);
	long long entrada[n];
 
	for(long long count = 0; count < n; count++){
		scanf(" %lld", entrada+count);
	}
 
	sort(entrada, entrada+n);
 
	for(long long count = 2; count < n; count++){
		if(entrada[p1]+entrada[p2]>entrada[count]){
			printf("YES\n");
			return 0;
		}
		p1++;
		p2++;
	}
 
	printf("NO\n");
 
	return 0;
}