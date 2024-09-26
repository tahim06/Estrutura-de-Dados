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

void inserir_no_fim(No **lista, int num){
    No *novo = (No*)malloc(sizeof(No));
    No *aux;

    if(novo){
        novo->valor = num;
        novo->prox = NULL;

        if(*lista == NULL){
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->prox){
                aux = aux->prox;
                aux->prox = novo;
            }
        }
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

