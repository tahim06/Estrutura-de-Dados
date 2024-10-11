#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    int *prox;

}No;

typedef struct list{
    No *inicio;
    No *fim;
    int tam;
}List;


No *criarNo(int valor){
    No * novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo; 
}

void inserirFim(No **head, int valor){
    No* novoNo = criarNo(valor);

    if (*head == NULL){

    }
}
