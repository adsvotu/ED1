
#include<stdlib.h>
#include "Lista.h"

int TAMANHO = 0;

void criar(item* L) {
    L = (item*) malloc(sizeof(item)); //malloc alocar na memoria
    L-> prox = NULL;
    TAMANHO=0;
}

int vazia(item* L) {
    return (TAMANHO==0) && (L->prox == NULL);
}

void inserir(item* L, int dado, int posicao) {
    int i;
    //1º passo
    item* novoitem = (item*) malloc(sizeof(item));
    novoitem->valor=dado;
    
    if ( (posicao > 0) && (posicao<=TAMANHO +1)) {
        //2º passo
        item* anterior = L;
        item* atual = L->prox;
        
        //3º passo executar as interacoes, e deslocamento
        for (i=1; i<posicao;i++) {
            anterior = atual;
            atual = atual->prox; //aponta para o 8 o proximo depois do primeiro e assim por diante
        }
        
        //4º passo, arranjo dos ponteiros depois que esta tudo no jeito
        //se invertar as linhas aqui da zica
        novoitem->prox = atual;
        anterior->prox = novoitem; //L-->5-->8-->null
        
        //5º passo atualizacao do tamanho da lista
        TAMANHO += 1;
    }
}

void remover(item* L, int posicao) {
    //1 passo
    int i;
    item* atual = L->prox;
    
    if ((!vazia(L)) && (posicao>0) && (posicao <= TAMANHO)) {
        item* anterior = L;
        
    //deslocamento    
        for (i=1; i<posicao; i++) {
            anterior = atual;
            //atual->prox pega para onde o atual-prox aponta (como se fosse um next() )
            atual = atual->prox;
        }
        
        //3 passo
        anterior->prox = atual->prox;
        
        //4 passo elimina o atual da memoria
        free(atual);
        
        //5 passo atualiza o tamanho
        TAMANHO-=1;
    }
}

int buscar(item* L, int posicao) {
    int i;
    item* atual = L->prox;
    
    if ((!vazia(L)) && (posicao>0) && (posicao <= TAMANHO)) {
        item* anterior = L;
        for (i=1; i<posicao; i++) {
            anterior = atual;
            atual = atual->prox;
        }
        
        return atual->valor;
        
    } else {
        return -1;
    }
}

int localizar(item* L, int dado) {
    int i = 1;
    int r = -1;
    item* atual = L->prox;
    
    while((i<=TAMANHO) && (atual->valor != dado)) {
        i++;
        atual = atual->prox;
    }
    if (i <= TAMANHO) {
        r = i;
    }
    return r;
    
}


void atualizar(item* L, int dado, int posicao) {
    int i;
    item* atual = L->prox;
    if ((!vazia(L)) && (posicao>0) && (posicao<=TAMANHO)) {
        for (i=1; i<posicao; i++) {
            atual = atual->prox;
        }
        atual->valor = dado;
    }
}

void excluir(item* L, int dado) {
    int posicao;
    if (!vazia(L)) {
        posicao = localizar(L, dado);
        if (posicao != -1) {
            remover(L, posicao);
        }
    }
}
