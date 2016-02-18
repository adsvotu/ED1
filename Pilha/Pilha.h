#ifndef PILHA_H
#define	PILHA_H

typedef struct item item;

struct item {
    int valor;
    item *prox;
};

int static topo;
void criar (item*);
int vazia (item*);
void empilhar (item*,int);
void desempilhar (item*);
int top (item*);
int posicao (item*, int);
void retirar (item*, int);

#endif	/* PILHA_H */

