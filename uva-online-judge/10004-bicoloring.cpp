#include <stdio.h>
#include <vector>

using namespace std;

#define max 210

typedef struct no{
	int cor = -1;
	vector<int> v;	
};

bool colorir(no nos[], int pos, int cor){
	if(nos[pos].cor == cor){
		return true;
	}else if(nos[pos].cor != -1){
		return false;
	}

	nos[pos].cor = cor;
	bool result = true;
	for(int i = 0; i < nos[pos].v.size(); i++){
		result = result && colorir(nos, nos[pos].v[i], (cor+1)%2);
	}
	return result;
}

int main(){
	int n, m;
	while(scanf(" %d %d",&n, &m)){
		if (!n){
			break;
		}

		vector<int> idNos;
		no nos[max];
		int a, b, pos;
		while(m--){
			scanf(" %d %d", &a, &b);
			//printf("inserindo %d %d\n",a ,b );
			nos[a].v.push_back(b);
			nos[b].v.push_back(a);
			pos = a;
		}

		if(colorir(nos, a, 1)){
			printf("BICOLORABLE.\n");
		}
		else{
			printf("NOT BICOLORABLE.\n");
		}
	}

	return 0;
}