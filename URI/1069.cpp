#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

string entrada;

int main(){
	//freopen("p2out.txt","w",stdout);
	int n;
	scanf(" %d ", &n);

	while(n--){
		getline(cin, entrada);
		int ini = 0, fim = 0;
		for(int i = 0; i < entrada.length(); i++){
			if(entrada[i] == '<'){
				ini ++;
			}
			else if(entrada[i] == '>' && ini){
				fim++;
				ini--;
			}
		}
		printf("%d\n", fim);
	}
	return 0;
}