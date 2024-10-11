#include <stdio.h>
#include <stdlib.h>
#define TAM 15

typedef struct no{
    char info;
    struct no *prox;
}No;

typedef struct list{
    int qtd;
    No *inicio;
    No *fim;
}List;

void incializar(List *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    int qtd = 0;
}

void exemplo(List *lista, char num[TAM]){
    No *aux;
    char c;
    for(int i = 0; i < TAM; i++){
        c = num[i];
    }
    
}























// void inserir_inicio(No **lista, int num){
//     No *novo = (No*)malloc(sizeof(No));

//     if(novo){
//         novo->valor = num;
//         novo->prox = *lista;
//         *lista = novo;

//     }else{
//         printf("Erro ao alocar memoria!\n");
//     }

// }

// void inserir_no_fim(No **lista, int num){
//     No *novo = (No*)malloc(sizeof(No));
//     No *aux;

//     if(novo){
//         novo->valor = num;
//         novo->prox = NULL;

//         if(*lista == NULL){
//             *lista = novo;
//         }else{
//             aux = *lista;
//             while(aux->prox){
//                 aux = aux->prox;
//             }
//             aux->prox = novo;
//         }
//     }else{
//         printf("Erro ao alocar memoria!\n");
//     }
// }

// void inserir_meio(No **lista, int num, int ant){
//     No *novo = (No*)malloc(sizeof(No));
//     No *aux;

//     if(novo){
//         novo->valor = num;
   
//         if(*lista == NULL){
//             novo->prox = NULL;
//             *lista = novo;

//         }else{
//             aux = *lista;
//             while(aux->valor != ant && aux->prox) {
//                 aux = aux->prox;
//             }
//             novo->prox = aux->prox;
//             aux->prox = novo;

//         }
//     }else{
//         printf("Erro ao alocar memoria!\n");
//     }
// }

// int main(){
    

//     return 0;
// }