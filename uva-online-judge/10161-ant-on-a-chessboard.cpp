#include <stdio.h>
#include <math.h>

using namespace	 std;

int main(){
	int n, dim, dimAnterior, x, y;

	while(scanf(" %d", &n)){
		
		if(!n){
			break;
		}

		dim = ceil(sqrt(n));
		dimAnterior = dim -1;
		//printf("dim atual -> %d\ndim anterior -> %d\n", dim, dimAnterior);
		
		if (dim%2){
			//printf("impar\n");
			//printf("valor entre %d e %d\n", dimAnterior*dimAnterior, dim*dim );
			if(n <= dimAnterior*dimAnterior + dimAnterior){
				x = dim;
				y = n - dimAnterior*dimAnterior;
			}
			else{
				y = dim;
				x = dim*dim - n +1;
			}
		}
		else{
			//printf("par\n");
			//printf("valor entre %d e %d\n", dimAnterior*dimAnterior, dim*dim );
			if(n <= dimAnterior*dimAnterior + dimAnterior){
				y = dim;
				x = n - dimAnterior*dimAnterior;
			}
			else{
				x = dim;
				y = dim*dim - n + 1;
			}
		}

		printf("%d %d\n",x, y);
	}

	return 0;
}