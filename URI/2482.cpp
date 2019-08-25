#include<stdio.h>
#include<iostream>
#include <map>

using namespace std;

int main(){
	//freopen("p1out.txt","w",stdout);
	int n, m;
	string lingua, trad, nome;
	map<string, string> traducoes;
	scanf(" %d ", &n);
	//cin.ignore();
	
	for(int i = 0; i < n; i++){
		getline(cin,lingua);
		getline(cin,trad);
		traducoes[lingua] = trad;
	}

	scanf(" %d ", &m);
	for(int i = 0; i < m; i++){
		getline(cin,nome);
		getline(cin,lingua);
		printf("%s\n%s\n\n",nome.c_str(), traducoes[lingua].c_str());
	}

	return 0;
}