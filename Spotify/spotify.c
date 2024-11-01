#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct musica {
    char titulo_musica[60];
    char artista[60];
    int valor;
    struct musica *prox;
    struct musica *ant;
};

typedef struct musica Musica;

struct lista {
    Musica *inicio;
    Musica *fim;
    int tamanho;
};

typedef struct lista LISTA;

LISTA *lista_inicia();
void lista_insere(LISTA *lista, const char *titulo, const char *artista, int valor);
void lista_imprime(LISTA *l);
void contar(LISTA *lista, int qnt);
void lista_remover(LISTA *l, const char *titulo);
void lista_libera(LISTA *l);

int main() {
    int n, valor;    
    char titulo[60], artista[60];    

    LISTA *lista = lista_inicia();
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %59s %59s %d", titulo, artista, &valor);
        lista_insere(lista, titulo, artista, valor);
    }
    
    contar(lista, lista->inicio->valor);
    lista_libera(lista);

    return 0;
}

LISTA *lista_inicia() {
    LISTA *new_list = (LISTA *)malloc(sizeof(LISTA));
    new_list->inicio = NULL;
    new_list->fim = NULL;
    new_list->tamanho = 0;
    return new_list;
}

void lista_insere(LISTA *l, const char *titulo, const char *artista, int valor) {
    Musica *new_musica = (Musica *)malloc(sizeof(Musica));
    strncpy(new_musica->titulo_musica, titulo, sizeof(new_musica->titulo_musica) - 1);
    strncpy(new_musica->artista, artista, sizeof(new_musica->artista) - 1);
    new_musica->valor = valor;

    if (l->tamanho == 0) {
        new_musica->prox = new_musica;
        new_musica->ant = new_musica;
        l->inicio = new_musica;
        l->fim = new_musica;
    } else {
        new_musica->prox = l->inicio;
        new_musica->ant = l->fim;
        l->fim->prox = new_musica;
        l->inicio->ant = new_musica;
        l->fim = new_musica;
    }
    l->tamanho++;
}

void lista_imprime(LISTA *l) {
    if (l->tamanho == 0) return;

    Musica *percorre = l->inicio;
    do {
        printf("%s %s %d\n", percorre->titulo_musica, percorre->artista, percorre->valor);
        percorre = percorre->prox;
    } while (percorre != l->inicio);
}

void contar(LISTA *lista, int qnt) {
    Musica *percorre = lista->inicio;

    while (lista->tamanho > 1) {
        for (int i = 0; i < qnt; i++) {
            percorre = (qnt % 2 == 0) ? percorre->ant : percorre->prox;
        }
        printf("Removendo: %s\n", percorre->titulo_musica);
        lista_remover(lista, percorre->titulo_musica);
        percorre = (qnt % 2 == 0) ? percorre->prox : percorre->ant; // Move to next
        qnt = percorre->valor;
    }
    printf("Vencedor(a): %s\n", lista->inicio->titulo_musica);
}

void lista_remover(LISTA *l, const char *titulo) {
    Musica *percorre = l->inicio;

    do {
        if (strcmp(percorre->titulo_musica, titulo) == 0) {
            if (l->tamanho == 1) {
                free(percorre);
                l->inicio = l->fim = NULL;
            } else {
                if (percorre == l->inicio) {
                    l->inicio = percorre->prox;
                }
                if (percorre == l->fim) {
                    l->fim = percorre->ant;
                }
                percorre->ant->prox = percorre->prox;
                percorre->prox->ant = percorre->ant;
                free(percorre);
            }
            l->tamanho--;
            return;
        }
        percorre = percorre->prox;
    } while (percorre != l->inicio);
}

void lista_libera(LISTA *l) {
    if (!l) return;

    Musica *percorre = l->inicio;
    if (!percorre) {
        free(l);
        return;
    }

    Musica *temp;
    do {
        temp = percorre;
        percorre = percorre->prox;
        free(temp);
    } while (percorre != l->inicio);

    free(l);
}
