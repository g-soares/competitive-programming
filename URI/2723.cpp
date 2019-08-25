#include<stdio.h>
#include<math.h>

int main(){
	//freopen("p10out.txt","w",stdout);
	int testes, p, x,y, entrada;
	scanf(" %d", &testes);
	bool res;

	while(testes--){
		x = 0;
		y = 0;
		res = true;
		scanf(" %d", &p);
		for(int i = 0; i < p; i++){
			scanf(" %d", &entrada);
			if(res){
				if(abs(x+entrada-y) <= 5){
					x+= entrada;
				}else if(abs(y+entrada-x) <= 5){
					y += entrada;
				}else{
					res = false;
				}
			}
		}

		if(res){
			printf("Feliz Natal!\n");
		}else{
			printf("Ho Ho Ho!\n");
		}
	}

	return 0;
}