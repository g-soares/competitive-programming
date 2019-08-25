#include<stdio.h>
#include<vector>
#include<math.h>
 
using namespace std;
 
#define MAX (1<<20)
 
int main(){
	int n, nim, resp;
	resp = 0;
	scanf(" %d", &n);
	
	for(int i = 0; i < n; i++){
		scanf(" %d", &nim);
		int j = sqrt(2*nim);
		
		while(j*(j+1) <= 2*nim){
			j++;
		}
 
		resp ^= (j-1);
	}
 
	if(resp){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
 
	return 0;
}