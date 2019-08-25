#include<stdio.h>
#include<vector>

using namespace std;

#define MAX (1<<20)

struct SegmentTree{
	vector<long long> M;
	vector<long long> pendente;
	
	SegmentTree(int n) {
		M.resize(MAX);
		pendente.resize(MAX);
	}

	void ini(int no, int a, int b) {
		if (a==b) {
			M[no] = pendente[no] = 0LL;
		}else{
			ini(no*2,a,(a+b)/2);
			ini((no*2)+1 ,((a+b)/2)+1,b);
			M[no] = M[no*2] + M[(no*2)+1];
		}
	}

	void propagar(int no, int a, int b){
		if (a == b) {
			M[no] += pendente[no];
			pendente[no] = 0LL;
			return;
		}

		M[no] += pendente[no];
		long long unit = pendente[no]/(b-a+1);
		pendente[no*2] += (((a+b)/2)- a + 1)*unit;
		pendente[(no*2)+1] += (b - ((a+b)/2))*unit;
		pendente[no] = 0LL;
	}

	long long query(int no, int a, int b, int i, int j){
		propagar(no,a,b);
		
		if( a > j || b < i){
			return 0LL;
		}

		if(a >= i && b <= j){
			return M[no];
		}

		long long p1 = query(no*2, a, (a+b)/2, i, j);
		long long p2 = query((no*2)+1, ((a+b)/2)+1, b, i, j);

		return p1 + p2;
	}

	void atualizar(int no, int a, int b, long long int v, int i, int j){
		propagar(no, a, b);
		
		if (b < i || a > j){ 
			return;
		}

		if (a >=i && b <= j){
			M[no] += (b-a+1) * v;
			pendente[no*2] += (((a+b)/2) - a +1) * v;
			pendente[(no*2)+1] += (b - ((a+b)/2)) * v;
			return;
		}

		atualizar(no*2, a, (a+b)/2, v, i, j);
		atualizar((no*2)+1, ((a+b)/2)+1, b, v, i, j);
		M[no] = M[no*2] + M[(no*2)+1];
	}
};

int main(){
	int t, tipo;
	scanf(" %d", &t);

	while(t--){
		int n, c;
		scanf(" %d %d", &n, &c);
		SegmentTree arv(n);
		arv.ini(1, 0, n);

		while(c--){
			int p, q;
			scanf(" %d %d %d", &tipo, &p, &q);
			if(tipo){
				printf("%lld\n",arv.query(1, 0, n, p, q));
			}else{
				int v;
				scanf(" %d", &v);
				arv.atualizar(1, 0, n, v, p, q);
			}
		}
	}
	return 0;
}