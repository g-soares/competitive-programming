#include <stdio.h>
#include <iostream>

using namespace std;

//char l[] = {'a',',','b',',','c',',','d',',','e',',','f',',','g',',','h',','};
char l[] = {'a','b','c','d','e','f','g','h'};
char ordenado[10] = "a";
int tam = 0;

void ident(int tam){
	for(int i = 0; i < tam; i++){
		printf("  ");
	}
}

/*void meio(int a, int b,int tam, int index){
	if (b == -1){
		return meio(a+1, a, tam, index);
	}
	else if(a == tam){
		ident(index);
		printf("writeln(");
		for(int i = 0; i < tam*2 -1; i++){
			printf("%c", l[i]);
		}
		printf(")\n");
		return;
	}

	ident(index);
	printf("if %c > %c then\n", l[b*2], l[(b+1)*2]);
	char aux = l[b*2];
	l[b*2] = l[(b+1)*2];
	l[(b+1)*2] = aux;
	meio(a, b-1, tam, index+1);
	aux = l[b*2];
	l[b*2] = l[(b+1)*2];
	l[(b+1)*2] = aux;
	ident(index);
	printf("else\n");
	meio(a+1, a, tam, index+1);

}*/

void meio(int index){
	if( index == tam){
		ident(index);
		printf("writeln(%c",ordenado[0]);
		for(int i = 1; i <tam; i++){
			printf(",%c",ordenado[i]);
		}
		printf(")\n");
		return;
	}

	ident(index);
	for(int i = index; i > 0; i--){
		ordenado[i] = ordenado[i-1];
	}
	
	for(int i = 0; i < index; i++){
		printf("if %c > %c then\n", ordenado[i+1], l[index]);
		ordenado[i] = l[index];
		meio(index+1);
		ordenado[i] = ordenado[i+1];
		ident(index);
		if( i < index-1){
			printf("else ");
		}
		else{
			printf("else");
		}
	}
	printf("\n");
	ordenado[index] = l[index];
	meio(index+1);
}

int main(){
	//freopen("p110out.txt","w",stdout);
	int n, iden = 1;
	scanf(" %d", &n);
	while(n--){
		scanf(" %d", &tam);

		printf("program sort(input,output);\nvar\n%c",l[0]);

		for(int i = 1; i < tam ; i++){
			printf(",%c", l[i]);
		}

		printf(" : integer;\nbegin\n");
		printf("  readln(%c",l[0]);
		
		for(int i = 1; i < tam; i++){
			printf(",%c", l[i]);
		}

		printf(");\n");

		//meio(1, 0, tam, iden);
		meio(1);
		printf("end.\n");

		if(n){
			printf("\n");
		}
	}
	return 0;
}