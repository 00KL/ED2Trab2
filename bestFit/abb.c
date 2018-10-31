#include "abb.h"

//retorna arvore vazia
arv* cria_vazia(){
    return NULL;
}

//checa se uma arvore é vazia
int arvore_vazia(arv* arvore){
    if(arvore == NULL) return 1;
    return 0;
}

//gera um disco novo, representado como um no na arvore na estrutura usada
arv* geraDisco(int x){
    arv* arvore = (arv*)malloc(sizeof(arv));

    arvore->esq = NULL;
    arvore->dir = NULL;
    arvore->info = x;

    return arvore;
}

//descobre qual sera a inserção devida para o novo dado
//ela pode caber em um disco ja existente ou precisar
//de um disco novo para ser alocada
arv* insercao(arv* arvore, int x){

    //busca o melhor disco para guardar tal informação
    arv* aux = buscaBestFit(arvore, x);
    //caso o retorno seja nulo n há disco que caiba o valor
    if(aux == NULL){
        //nesse caso um novo disco é criado e posto na arvore
        int ajuste = Giga;
        ajuste -= x;
        return insereAbb(arvore, ajuste);
    }
    //caso caso caiba a função ira retornar o endereço do
    //disco q será atualizado
    else{
        //a quantidade de dados contida nele sera armazenada
        int resultado = aux->info;
        //o no q simboliza o disco sera retirado e atualizado e reincerido
        //na arvore
        arvore = retira_aux(arvore, resultado);
        resultado -= x;
        arvore = insereAbb(arvore, resultado);
    }
    return arvore;
}

arv* insereAbb(arv* arvore, int x){
    //caso a arvore esteja vazia é importante
    //um novo disco sera criado como o nó raiz da arvore e
    //sera retornado
    if(arvore_vazia(arvore)){
        return geraDisco(x);
    }

    //caso a arvore n seja vazia é necessário procurar a mehor posição
    //para colocar o novo disco
    else{
        //caso menor q a informação atual se deve colocar o novo disco a
        //esquerda
        if(x < arvore->info){
            //como o novo disco ira atuallizar a arvore a esquerda
            //a arvore a esquerda deve ser atualizada
            arvore->esq = insereAbb(arvore->esq, x);
        }
        //caso maior q a informação atual se deve colocar o novo disco a
        //direita
        else{
            //como o novo disco ira atuallizar a arvore a direita
            //a arvore a direita deve ser atualizada
            arvore->dir = insereAbb(arvore->dir, x);
        }
    }

    //retorna-se a arvore atualizada
    return arvore;

}

//utilizada apenas para testes
//imprime a arvore gerada
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


//busca um no especifico na arvore
int busca(arv* arvore, int x){
    //caso a arvore n seja vazia
    if(!arvore_vazia(arvore)){
        //se a arvore atual foi a procurada se retorna a mesma
        if(arvore->info == x){
            return 1;
        }

        else{
            //caso a atual n seja se pergunda se o no procurado é menor
            //q o atual assim se busca a esquerda
            if(arvore->info > x){
                return busca(arvore->esq, x);
            }

            else{
                //caso a atual n seja se pergunda se o no procurado é maior
                //q o atual assim se busca a direita
                return busca(arvore->dir, x);
            }

        }
    }

    //o no atual seja vazio se retorna 0
    return 0;
}

arv* buscaBestFit(arv* arvore, int x){
    //
    if(!arvore_vazia(arvore)){
        //busca o bestfit a esquerda
        arv* retorna = NULL;
        if(x < arvore->info){
            retorna = buscaBestFit(arvore->esq, x);
        }

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

    while(!arvore_vazia(arvore->dir)){
        arvore = arvore->dir;
    }

    return arvore->info;
}

int menor(arv* arvore){
    while(!arvore_vazia(arvore->esq)){
        arvore = arvore->esq;
    }

    return arvore->info;
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
