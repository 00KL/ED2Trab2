#include "PQ.h"

int main(){
    //quantidade de componentes
    int N;
    scanf("%d", &N);

    //leitura de todas as entradas
    int* vet = (int*)malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++){
        scanf("%d", &vet[i]);
    }

    sort(N, vet);

}
