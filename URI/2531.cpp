#include<stdio.h>
#include<vector>
#include<utility>

using namespace std;

#define MAX (1<<20)
#define INF 99999999

int entrada[MAX];
int M[MAX][2];

struct SegmentTree{
	//vector<vector<int>> M;
	//int M[4*MAX][2];
	
	SegmentTree(int n){
		//printf("entrou\n");
		//M.resize(2, vector<int>(100) );
		//M.resize(2, vector<int>(MAX*4));
		//return;
	}

	void ini(int no, int a, int b){
		if (a==b) {
			M[no][0] = M[no][1] = entrada[a];
		}else{
			ini(no*2,a,(a+b)/2);
			ini((no*2)+1 ,((a+b)/2)+1,b);
			M[no][0] = min(M[no*2][0], M[(no*2)+1][0]);
			M[no][1] = max(M[no*2][1], M[(no*2)+1][1]);
		}
	}

	pair<int, int> query(int no, int a, int b, int i, int j){	
		if( a > j || b < i){
			return make_pair(INF, -INF);
		}

		if(a >= i && b <= j){
			return make_pair(M[no][0], M[no][1]);
		}

		pair<int,int> p1 = query(no*2, a, (a+b)/2, i, j);
		pair<int,int> p2 = query((no*2)+1, ((a+b)/2)+1, b, i, j);

		return make_pair(min(p1.first, p2.first), max(p1.second, p2.second));
	}

	void atualizar(int no, int a, int b, int v, int i) {
		if(a > i || b < i){
			return;
		}

		if(a == b && a == i){
			M[no][0] = M[no][1] = v;
			return;
		}
		
		atualizar(no*2, a, (a+b)/2, v, i);
		atualizar((no*2)+1, ((a+b)/2)+1, b, v, i);

		M[no][0] = min(M[no*2][0], M[no*2+1][0]);
		M[no][1] = max(M[no*2][1], M[no*2+1][1]);
	}
};

int main(){
	int n, q, tipo, a, b;

	while(scanf("%d", &n) > 0 && n > 0){
		for(int i = 0; i < n; i++){
			scanf(" %d", &entrada[i]);
		}

		scanf(" %d", &q);

		SegmentTree arv(n);
		arv.ini(1, 0, n);

		while(q--){
			scanf(" %d %d %d", &tipo, &a, &b);
			if(tipo == 1){
				arv.atualizar(1, 0, n, b, a-1);
			}else{
				pair<int, int> resp = arv.query(1, 0, n, a-1, b-1);
				printf("%d\n", resp.second - resp.first);
			}
		}
	}
	return 0;
}