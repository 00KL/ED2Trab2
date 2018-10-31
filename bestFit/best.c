#include "abb.h"

int bestFit(int N, int* vet){
    //cria arvore vazia e a retorna
    arv* arvore = cria_vazia();

    //insere novo dado na arvore
    for(int i = 0; i < N; i++){
        arvore = insercao(arvore, vet[i]);
    }

    //guarda a quantidade de discos usada
    int retorno = quantDisco(arvore);
    //libera memoria usada pela arvore
    libera(arvore);
    //retorna valor guardado
    return retorno;

}
