#include<stdio.h>
#include<vector>

using namespace std;

#define maxA 30
#define infinito 999999999

int me [maxA][maxA], sgt[maxA][maxA];

int main(){
	//freopen("p10171out.txt","w",stdout);
	int a, custo;
	char idade, direcao, cid1, cid2, iniMe, iniSgt;
	while(scanf(" %d",&a)){
		if(a == 0){
			break;
		}

		for(int i = 0; i < maxA; i++){
			for(int j = i; j < maxA; j++){
				me[i][j] = me[j][i] = infinito;
				sgt[i][j] = sgt[j][i] = infinito;
			}
			me[i][i] = sgt[i][i] = 0;
		}

		for(int i = 0; i < a; i++ ){
			scanf(" %c %c %c %c %d", &idade, &direcao, &cid1, &cid2, &custo);
			if( cid1 != cid2){
				if(idade == 'Y'){
					me[cid1-'A'][cid2-'A'] = custo; 
					if (direcao == 'B'){
						me[cid2-'A'][cid1-'A'] = custo;
					}
				}
				else{
					sgt[cid1-'A'][cid2-'A'] = custo; 
					if (direcao == 'B'){
						sgt[cid2-'A'][cid1-'A'] = custo;
					}
				}
			}
		}

		for(int i = 0; i < maxA; i++){
			for(int j = 0; j < maxA; j++){
				for(int k = 0; k < maxA; k++){
					if(me[i][j] > me[i][k] + me[k][j]){
						me[i][j] = me[i][k] + me[k][j];
					}
					if(sgt[i][j] > sgt[i][k] + sgt[k][j]){
						sgt[i][j] = sgt[i][k] + sgt[k][j];
					}
				}
			}
		}
		
		/*printf("--------------me---------------\n");
		for(int i = 0; i < maxA; i++){
			for(int j = 0; j < maxA; j++){
				printf("%d ", me[i][j]);
			}
			printf("\n");
		}
		printf("-----------------\nsgt-----------------\n");
		for(int i = 0; i < maxA; i++){
			for(int j = 0; j < maxA; j++){
				printf("%d ",sgt[i][j]);
			}
			printf("\n");
		}*/

		scanf(" %c %c", &iniMe, &iniSgt);

		vector<char> v;
		int min = infinito;
		for(int i = 0; i < maxA; i++){
			if(me[iniMe - 'A'][i] != infinito && sgt[iniSgt - 'A'][i] != infinito){
				if(me[iniMe - 'A'][i]+sgt[iniSgt - 'A'][i] < min){
					v.clear();
					min = me[iniMe - 'A'][i]+sgt[iniSgt - 'A'][i];
					v.push_back(i+'A');
				}else if (me[iniMe - 'A'][i]+sgt[iniSgt - 'A'][i] == min){
					v.push_back(i+'A');
				}
			}
		}

		if(min != infinito){
			printf("%d", min);
			for(int i = 0; i < v.size(); i++){
				printf(" %c", v[i]);
			}
		}
		else{
			printf("You will never meet.");
		}
		printf("\n");
	}
	return 0;
}