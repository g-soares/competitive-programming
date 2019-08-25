#include<stdio.h>
#include<set>
#include<string>

using namespace std;

set<string> joias;
char entrada[1000010];

int main(){
	//freopen("p3out.txt","w",stdout);
	while(scanf(" %s", entrada) != EOF){
		joias.insert(entrada);
	}
	printf("%d\n",(int)joias.size());
	return 0;
}