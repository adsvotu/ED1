/* 
 * File:   Lista.h
 * Author: lucas
 *
 * Created on November 16, 2015, 9:28 PM
 */

#ifndef LISTA_H
#define	LISTA_H



typedef struct Item item;

struct Item {
    int valor;
    item *prox;
};

extern int TAMANHO;

void criar(item*);
int vazia(item*);
void inserir(item*, int, int);
void remover(item*, int);
int buscar(item*, int);
int localizar(item*, int);
void atualizar(item*, int, int);
void excluir(item*, int);

#endif	/* LISTA_H */


