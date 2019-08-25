#include<stdio.h>
#include<math.h>
#include<vector>

using namespace std;

int area(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	int area = a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);
	return (int)abs(area);
}


bool estaDentro(pair<int, int> x, pair<int, int> a, pair<int, int> b, pair<int, int> c){
	int aTotal = area(a, b, c);
	int a1 = area(x, b, c);
	int a2 = area(a, x, c);
	int a3 = area(a, b, x);

	return (aTotal == a1 + a2 + a3);
}

int main(){
	int n, m, atual;
	long long total;
	pair<int,int> brancos[110], pretos[110];
	
	while(scanf(" %d %d", &n, &m) > 0){
		for(int i = 0; i < n; i++){
			scanf(" %d %d", &pretos[i].first, &pretos[i].second);
		}

		for(int i = 0; i < m; i++){
			scanf(" %d %d", &brancos[i].first, &brancos[i].second);
		}

		total = 0;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++){
				for(int k = 0; k < j; k++){
					atual = 0;

					for(int l = 0; l < m; l++){
						if (estaDentro(brancos[l], pretos[i], pretos[j], pretos[k])){
							atual++;
						}
					}

					total+= atual*atual;
				}
			}
		}
		printf("%lld\n",total);
	}
	return 0;
}