#include <stdlib.h>
#include "Pilha.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void criar (item * p) {
    p->prox=NULL;
    topo=0;
}

int vazia (item* p) {
    return p->prox==NULL;
}

void empilhar (item * p, int dado) {
    item* novoitem = (item*) malloc (sizeof(item));
    item* atual = p->prox;  // atual aponta para onde "p" aponta
    novoitem->valor=dado; //recebe o valor digitado e preenche na pilha
    
    if (atual!=NULL) { //atual diferente de nulo?
        while (atual->prox!=NULL) { //atual diferente de nulo?
            atual=atual->prox; //aponta para o proximo
        }
    }
    if (vazia(p)) { // a pilha esta vazia?
        p->prox=novoitem;
        novoitem->prox=atual;
    } else {
        novoitem->prox=atual->prox;
        atual->prox=novoitem; // aponta para o novo item (novo valor)
    }
    topo+=1;
    
}

void desempilhar (item* p) {
    item* atual=p->prox;
    item* anterior=p;
    
    if (!vazia(p)) { //se a pilha não estiver vazia
        while (atual->prox!=NULL){ // fazer o ponteiro ir migrando para o proximo
            anterior=atual;
            atual=atual->prox;
        }
    }
    anterior->prox=NULL;
    free(atual);
    topo-=1;
}

int top (item* p) { //mostra qual o valor do item que está no topo
    item* atual=p->prox;
    if(!vazia(p)) {
        while (atual->prox!=NULL){ //laço que percorre até chegar no topo
            atual=atual->prox;
        }
        return atual->valor;
    }
}

int posicao (item * p, int dado) {
    item* atual = p->prox;
    item* novapilha = (item*) malloc (sizeof(item));
    int pos=-1;
    if (!vazia(p)) { //testa se esta vazia
        novapilha->prox=NULL; //seta para onde a nova pilha aponta
        while ((atual->prox!=NULL)&&(atual->valor!=dado)) { //verificar se existem mais valores para percorrer a pilha
            atual=atual->prox;
        }
        if ((atual->prox!=NULL)||(atual->valor==dado)) {
            while (atual->prox!=NULL) { //faz a nova pilha
                empilhar(novapilha,top(p)); //top se torna a cabeça da pilha p/ nova pilha
                topo-=1;
                desempilhar(p); //desempilha da pilha anterior até chegar no valor esperado
            }
            pos=topo;
            while (!vazia(novapilha)) { //desfaz a nova pilha até que fique vazia
                empilhar(p,top(novapilha)); //empilha o topo da "nova pilha" p/ a pilha anterior
                desempilhar(novapilha);
                topo+=1; //atualiza a quantidade
                
            }
        }
    }
    return pos; //tratar como inexistente
}



