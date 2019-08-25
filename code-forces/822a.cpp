#include <stdio.h>
#include<math.h>
 
using namespace std;
 
int main(){
	long long a, b, count = 0, resp = 1;
	scanf(" %lld %lld", &a, &b);
	count = min(a,b);
 
	while(count > 0){
		resp*=count;
		count--;
	}
	
	printf("%lld\n", resp);
}