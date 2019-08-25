#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int mdc( int x, int y){
    int resto = x%y;
    while(resto){
        x = y;
        y = resto;
        resto = x%y;
    }
    return y;
}

int mmc(int x, int y){
    return (x*y)/mdc(x,y);        
}


int getTotalX(int a_size, int* a, int b_size, int* b) {
    // Complete this function
    int mmc_a, mdc_b, count, cont, aux = 0;
        
    mmc_a = a[0];
    for(cont = 1; cont < a_size; cont++){
        mmc_a = mmc(mmc_a, a[cont]);
    }
    
    mdc_b = b[0];
    for(cont = 1; cont < b_size; cont++){
        mdc_b = mdc(mdc_b, b[cont]);
    }

    for(cont = mmc_a, aux = 2; cont <= mdc_b; cont = mmc_a*aux, aux++){
        if(mdc_b%cont == 0){
            count ++;
        }
    }
    
    return count;
}

int main() {
    int n; 
    int m; 
    scanf("%i %i", &n, &m);
    int *a = malloc(sizeof(int) * n);
    for (int a_i = 0; a_i < n; a_i++) {
       scanf("%i",&a[a_i]);
    }
    int *b = malloc(sizeof(int) * m);
    for (int b_i = 0; b_i < m; b_i++) {
       scanf("%i",&b[b_i]);
    }
    int total = getTotalX(n, a, m, b);
    printf("%d\n", total);
    return 0;
}
