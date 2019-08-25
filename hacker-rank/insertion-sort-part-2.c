#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


void print(int* vetor, int tamanho){
    for(int cont = 0; cont < tamanho - 1; cont++){
        printf("%d ",vetor[cont]);
    }
    printf("%d\n",vetor[tamanho-1]);
    
}

void insertionSort(int ar_size, int *  ar) {
    int valor = ar[ar_size-1];
    int cont;
    for( cont = ar_size - 1; cont > 0 && ar[cont-1] > valor; cont--){
        ar[cont] = ar[cont-1];
        print(ar,ar_size);
    }
    ar[cont] = valor;
    print(ar,ar_size);

}

int main(void) {
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        scanf("%d", &_ar[_ar_i]); 
    }

    insertionSort(_ar_size, _ar);
    return 0;
}
