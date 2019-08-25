#include <stdio.h>
#include <string.h>

using namespace std;

#define maxN 70

bool slump(int ini, int fim, char* s){
	if (s[ini] != 'D' && s[ini] != 'E'){
		return false;
	}
	else if (s[fim] != 'G'){
		return false;
	}

	for (int i = ini+1; i <= fim; i++){
		if (s[i] != 'F'){
			if (i == ini+1){
				return false;
			}
			if (i == fim && s[i] == 'G'){
				return true;
			}
			else{
				return slump(i, fim, s);
			}
		}
	}
	return false;
}

bool slimp (int ini, int fim, char* s){
	if (fim <= ini){
		return false;
	}
	else if (fim - ini == 1){
		return s[ini] == 'A' && s[fim] == 'H';
	}
	else if (s[ini] != 'A'){
		return false;
	}
	else if (s[fim] != 'C'){
		return false;
	}
	else if (slump(ini+1, fim-1, s)){
		return true;
	}
	else if (s[ini+1] != 'B'){
		return false;
	}

	return slimp(ini+2, fim -1, s);
}

int main(){
	int n, tam;
	char s[maxN];
	bool result = false;

	scanf(" %d", &n);
	
	printf("SLURPYS OUTPUT\n");	
	for (int i = 0; i < n; i++){
		result = false;
		scanf(" %s",s);

		tam = strlen(s);
		for (int j = 0; j < tam; j++){
			if (s[j] == 'C' || s[j] == 'H'){
				result = slimp(0, j, s) && slump(j+1, tam-1, s);
				if (result){
					break;
				}
			}
		}

		if (result){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}

	printf("END OF OUTPUT\n");
	return 0;
}