#include "abb.h"

//variavel global
int reincere;
arv* salvaNoix;

arv* cria_vazia(){

    return NULL;
}

int arvore_vazia(arv* arvore){
    if(arvore == NULL){
        return 1;
    }

    return 0;
}

arv* geraDisco(int x){
    arv* arvore = (arv*)malloc(sizeof(arv));

    arvore->esq = NULL;
    arvore->dir = NULL;
    arvore->info = x;
    //printf("%d \n", arvore->info);

    return arvore;
}

arv* insercao(arv* arvore, int x){

    arv* aux = buscaBestFit(arvore, x);
    if(aux == NULL){
        //printf("test3\n");
        int ajuste = Giga;
        ajuste -= x;
        return insereAbb(arvore, ajuste);
    } else{
        int resultado = aux->info;
        arvore = retira_aux(arvore, resultado);
        resultado -= x;
        arvore = insereAbb(arvore, resultado);
    }
    return arvore;
}

arv* insereAbb(arv* arvore, int x){
    //caso a arvore esteja vazia é importante
    //setar o valor do camo info da raiz
    if(arvore_vazia(arvore)){
        return geraDisco(x);
    }

    else{
        //Caso o valor a ser inserido seja menor q a raiz
        //ele deve ser inserido a esquerda
        if(x <= arvore->info){


            //caso n haja filhos a esquerda um novo deve ser
            //criado e o novo valor inserido
            if(arvore->esq == NULL){
                arvore->esq = geraDisco(x);

                return arvore;
            }

            //caso haja um filho a esquerda o novo valor
            //funcao e executada considerando o no a esquerda da
            //raiz original como nova raiz numa recursão
            else{
                arvore->esq = insereAbb(arvore->esq, x);

                return arvore;
            }
        }

        //Caso o valor a ser inserido seja maior q a raiz
        //ele deve ser inserido a direita
        if(arvore->info < x){

            if(arvore->dir == NULL){
                arvore->dir = geraDisco(x);

                return arvore;
            }

            else{
                arvore->dir = insereAbb(arvore->dir, x);

                return arvore;
            }
        }

    }

    return NULL;

}

void imprime_crescente(arv* arvore){
    if(arvore_vazia(arvore)){
        printf("<VAZIO");
    }
    else{
        printf("<%d ", arvore->info);

        imprime_crescente(arvore->esq);
        printf(">   ");

        imprime_crescente(arvore->dir);
        printf("> %d", arvore->info);
    }
}


int busca(arv* arvore, int x){
    if(!arvore_vazia(arvore)){

        if(arvore->info == x){
            return 1;
        }

        else{

            if(arvore->info > x){
                return busca(arvore->esq, x);
            }

            else{
                return busca(arvore->dir, x);
            }

        }
    }

    return 0;
}

arv* buscaBestFit(arv* arvore, int x){
    if(!arvore_vazia(arvore)){
        //busca o bestfit a esquerda
        arv* retorna = buscaBestFit(arvore->esq, x);

        //caso n encontre se pergunta se o no atual é
        //o bestFit
        if(retorna == NULL){

            if(x <= arvore->info){
                return arvore;
            }
            //caso o no atual seja o best fit ele busca a direita
            else{
                return buscaBestFit(arvore->dir, x);
            }
        }

        return retorna;

    }

    return NULL;
}

/////////////////////////////RETIRA
arv* tira_folha(arv* folha){
    free(folha);
    return NULL;
}

int maior(arv* arvore){
    //checa se arvore é vazia
    if(!arvore_vazia(arvore)){
        //caso a arvore a direita seja vazia
        //a raiz atual é a maior de toda a arvore
        if(arvore_vazia(arvore->dir)){

            return arvore->info;
        }

        //caso haja mais nos a direita existe algum
        //valor maior q ainda deve ser retornado
        else{
            return maior(arvore->dir);
        }
    }

    return 0;
}

int menor(arv* arvore){
    if(!arvore_vazia(arvore)){

        if(arvore_vazia(arvore->esq)){
            return arvore->info;
        }

        else{
            return menor(arvore->esq);
        }
    }

    return 0;
}

arv* reestrutura(arv* arvore){
    if(!arvore_vazia(arvore)){
        if(!arvore_vazia(arvore->esq)){
            arvore->info = maior(arvore->esq);
            arvore->esq = retira_aux(arvore->esq, arvore->info);

            return arvore;
        }else{
            arvore->info = menor(arvore->dir);
            arvore->dir = retira_aux(arvore->dir, arvore->info);

            return arvore;
        }
    }

    return NULL;
}

arv* retira_aux(arv* arvore, int x){
        if(arvore->info == x){
            //folha
            if(arvore->esq == NULL && arvore->dir == NULL){
                return tira_folha(arvore);
            }
            //no
            else{
                return reestrutura(arvore);
            }

        }

        else if(arvore->info > x){
            arvore->esq = retira_aux(arvore->esq, x);
            return arvore;
        }

        else if(arvore->info < x){
            arvore->dir = retira_aux(arvore->dir, x);
            return arvore;
        }

        return NULL;

}
////////////////////RETIRA

void libera(arv* arvore){
    if(!arvore_vazia(arvore)){
        libera(arvore->esq);
        libera(arvore->dir);
        free(arvore);
    }
}


//Quantidade de nos na arvore
int quantDisco(arv* arvore){
    if(!arvore_vazia(arvore)){
        int cont = quantDisco(arvore->esq);
        cont++;//arvore atual;
        cont += quantDisco(arvore->dir);

        return cont;
    }

    return 0;
}
