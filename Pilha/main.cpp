/* 
 * File:   main.cpp
 * Author: Fernando
 *
 * Created on 15 de Novembro de 2015, 21:39
 */
#include<locale.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Pilha.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	
    setlocale(LC_ALL,"Portuguese");
    
    item pilha;
    int opcao=0,dado=0;
    
    do{
        printf("Escolha a op��o para trabalhar com pilhas\n");
        printf("1 - Criar Pilha\n");
        printf("2 - Verificar se a Pilha est� vazia\n");
        printf("3 - Empilhar Dado\n");
        printf("4 - Desempilhar\n");
        printf("5 - Buscar Topo\n");
        printf("6 - Buscar posi��o atrav�s de um Dado da Pilha\n");
        printf("7 - Retirar Dado\n");
        printf("0 - Sair do programa\n\n");
        
        printf("Digite a op��o!\n");
        scanf(" %d",&opcao);

        switch (opcao){
            case 1:
                criar(&pilha);
                printf("Pilha Criada!\n");
                break;
            case 2:
                if (vazia(&pilha)){
                    printf("Pilha Vazia!\n");
                }else{
                    printf("Pilha n�o Vazia!\n");
                }
                break;
            case 3:
                printf("Digite o dado!\n");
                scanf(" %d",&dado);
                //cin>>dado;
                empilhar(&pilha, dado);
                printf("Valor %d foi inserido no topo da pilha\n",dado);
                break;
            case 4:
                dado=top(&pilha);
                desempilhar(&pilha);
                printf("Valor %d foi removido do topo da pilha\n",dado);
                break;
            case 5:
                printf("O valor do topo da pilha �: %d\n",top(&pilha));
                break;
            case 6:
                printf("Digite um dado!\n");
                scanf(" %d",&dado);
                if (posicao(&pilha,dado) > -1){
                    printf("O dado %d foi encontrado na posi��o %d\n",dado,posicao(&pilha,dado));
                }else{
                    printf("O valor n�o foi encontrado em nenhuma posi��o!\n");
                }
                break;
            case 7:
                printf("Digite um dado!\n");
                scanf(" %d",&dado);
                //retirar(&pilha,dado);
                printf("Valor %d foi removido da pilha\n",dado);
                break;
            case 0:
                return (EXIT_SUCCESS);
        }
        printf("\n");
      }
      while (opcao != 0);
}
