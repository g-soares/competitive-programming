#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace	 std;

#define max 1500

int fila[max];

int main(){
	//freopen("p10440out.txt","w",stdout);
	int casos, cap, ttrav, m, ttotal, atual, v;
	scanf(" %d", &casos);
	
	while(casos--){
		memset(fila, 0, max);
		scanf(" %d %d %d", &cap, &ttrav, &m );
		
		for(int i = 1; i <= m; i++){
			scanf(" %d", &fila[i]);
		}

		sort(fila, fila+m+1);

		//atual = (m%cap) ? m%cap : cap;
		if(m%cap == 0){
			atual = cap;
			v = m/cap;
		}
		else{
			atual = m%cap;
			v = m/cap + 1;
		}

		ttotal = fila[atual] + 2*ttrav;

		//printf("Ttotal inicial -> %d\n atual -> %d\n", ttotal, atual );
		while(atual + cap  <= m ){
			if(ttotal >= fila[atual + cap]){
				ttotal += 2*ttrav;
			}
			else{
				ttotal = fila[atual+cap] + 2*ttrav;
			}
			atual += cap;
		}
		//printf("tempo total -> %d\ntempo de travessia -> %d\n", ttotal, ttrav );
		printf("%d %d\n", ttotal-ttrav, v);
	}

	return 0;
}