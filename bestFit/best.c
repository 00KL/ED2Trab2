#include "abb.h"

//arvore test <6 <2 <1 < > < > > <4 <3 < > < > > < > > <8 < > < > > >

void bestFit(int N, int* vet){
    arv* arvore = cria_vazia();

    for(int i = 0; i < N; i++){
        arvore = insereAbb(arvore, vet[i]/10000);
        printf("[%d]\n", vet[i]/10000);
    }



    imprime_crescente(arvore);
    printf("\n\n");
    //
    // if(busca(arvore, 6)){
    //     printf("6 esta na arvore.\n");
    // }else{
    //     printf("6 nao esta na arvore.\n");
    // }
    //
    // if(busca(arvore, 14)){
    //     printf("14 esta na arvore.\n");
    // }else{
    //     printf("14 nao esta na arvore.\n");
    // }
    //
    // arvore = retira(arvore, 6);
    //
    // arvore = retira(arvore, 3);
    //
    // arvore = retira(arvore, 8);
    //
    // arvore = retira(arvore, 2);

    libera(arvore);

}
