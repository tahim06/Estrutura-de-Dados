#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

void inserir_inicio(No **lista, int num){
    No *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->prox = *lista;
        *lista = novo;

    }else{
        printf("Erro ao alocar memoria!\n");
    }

}


