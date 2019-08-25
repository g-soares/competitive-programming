#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

#define MAX (1<<20)

int entrada[100100];

struct SegmentTree{
	vector<int> M;
	//vector<long long> pendente;
	
	SegmentTree(int x) {
		M.resize(MAX);
		//pendente.resize(MAX);
	}

	void ini(int no, int a, int b){
		if (a==b) {
			//M[no] = pendente[no] = 0LL;
			M[no] = valor(entrada[a-1]);
		}else{
			ini(no*2, a, (a+b)/2);
			ini((no*2)+1, ((a+b)/2)+1, b);
			M[no] = M[no*2] * M[(no*2)+1];
		}
	}

	long long query(int no, int a, int b, int i, int j){
		//propagar(no,a,b);
		
		if( a > j || b < i){
			return 1;
		}

		if(a >= i && b <= j){
			return M[no];
		}

		long long p1 = query(no*2, a, (a+b)/2, i, j);
		long long p2 = query((no*2)+1, ((a+b)/2)+1, b, i, j);

		return p1*p2;
	}

	void atualizar(int no, int a, int b, int v, int i){
		//propagar(no, a, b);
		
		if (b < i || a > i){ 
			return;
		}

		if (a == b && b == i){
			/*M[no] += (b-a+1) * v;
			pendente[no*2] += (((a+b)/2) - a +1) * v;
			pendente[(no*2)+1] += (b - ((a+b)/2)) * v;*/
			M[no] = valor(v);
			return;
		}

		atualizar(no*2, a, (a+b)/2, v, i);
		atualizar((no*2)+1, ((a+b)/2)+1, b, v, i);
		M[no] = M[no*2]*M[(no*2)+1];
	}

	int valor(int v){
		if(v > 0){
			return 1;
		}else if(v < 0){
			return -1;
		}

		return 0;
	}
};

int main(){
	int n, k, a, b;
	char c;

	while(scanf(" %d %d",&n, &k) > 0){
		for(int i = 0; i < n; i++){
			scanf(" %d", &entrada[i]);
		}

		SegmentTree arv(n);
		arv.ini(1, 1, n);

		for (int i = 0 ; i < k; i++){
			scanf(" %c %d %d", &c, &a, &b);

			if (c == 'P'){
				int resp = arv.query(1, 1, n, a, b);
				if(resp == 1){
					printf("+");
				}else if(resp == 0){
					printf("0");
				}else{
					printf("-");
				}
			}
			else if (c == 'C'){
				arv.atualizar(1, 1, n, b, a);
			}
		}
		printf("\n");
	}

	return 0;
}