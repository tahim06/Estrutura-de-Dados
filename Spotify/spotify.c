#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct musica {
    char titulo[60];
    char artista[60];
    int minutos;
    int segundos;
    struct musica *prox;
    struct musica *ant;
};

typedef struct musica Musica;

struct lista {
    Musica *inicio;
    Musica *fim;
    int tamanho;
};

typedef struct lista Lista;

Lista *inicializar_lista();
void adicionar_musica(Lista *lista, const char *titulo, const char *artista, int minutos, int segundos);
void remover_musica(Lista *lista, const char *titulo);
void visualizar_musicas(const Lista *lista);
void limpar_lista(Lista *lista);
void pesquisar_musica(const Lista *lista, const char *titulo);
void ordenar_musicas(Lista *lista);
void contar_musicas(const Lista *lista);
void liberar_lista(Lista *lista);

int main() {
    Lista *lista = inicializar_lista();
    int opcao;
    char titulo[60], artista[60];
    int minutos, segundos;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar música\n");
        printf("2. Remover música\n");
        printf("3. Visualizar músicas\n");
        printf("4. Limpar lista de músicas\n");
        printf("5. Pesquisar música por título\n");
        printf("6. Ordenar músicas por título\n");
        printf("7. Contar músicas\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Título da música: ");
                scanf(" %59[^\n]", titulo);
                printf("Artista: ");
                scanf(" %59[^\n]", artista);
                printf("Duração (minutos e segundos): ");
                scanf("%d %d", &minutos, &segundos);
                adicionar_musica(lista, titulo, artista, minutos, segundos);
                break;
            case 2:
                printf("Título da música a remover: ");
                scanf(" %59[^\n]", titulo);
                remover_musica(lista, titulo);
                break;
            case 3:
                visualizar_musicas(lista);
                break;
            case 4:
                limpar_lista(lista);
                break;
            case 5:
                printf("Título da música a pesquisar: ");
                scanf(" %59[^\n]", titulo);
                pesquisar_musica(lista, titulo);
                break;
            case 6:
                ordenar_musicas(lista);
                break;
            case 7:
                contar_musicas(lista);
                break;
            case 8:
                liberar_lista(lista);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 8);

    return 0;
}

Lista *inicializar_lista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

void adicionar_musica(Lista *lista, const char *titulo, const char *artista, int minutos, int segundos) {
    Musica *nova = (Musica *)malloc(sizeof(Musica));
    strncpy(nova->titulo, titulo, sizeof(nova->titulo) - 1);
    strncpy(nova->artista, artista, sizeof(nova->artista) - 1);
    nova->minutos = minutos;
    nova->segundos = segundos;

    if (lista->tamanho == 0) {
        nova->prox = nova;
        nova->ant = nova;
        lista->inicio = nova;
        lista->fim = nova;
    } else {
        nova->prox = lista->inicio;
        nova->ant = lista->fim;
        lista->fim->prox = nova;
        lista->inicio->ant = nova;
        lista->fim = nova;
    }
    lista->tamanho++;
    printf("Música adicionada com sucesso!\n");
}

void remover_musica(Lista *lista, const char *titulo) {
    if (lista->tamanho == 0) {
        printf("A lista está vazia!\n");
        return;
    }

    Musica *atual = lista->inicio;
    do {
        if (strcmp(atual->titulo, titulo) == 0) {
            if (lista->tamanho == 1) {
                lista->inicio = NULL;
                lista->fim = NULL;
            } else {
                atual->ant->prox = atual->prox;
                atual->prox->ant = atual->ant;
                if (atual == lista->inicio) {
                    lista->inicio = atual->prox;
                }
                if (atual == lista->fim) {
                    lista->fim = atual->ant;
                }
            }
            free(atual);
            lista->tamanho--;
            printf("Música removida com sucesso!\n");
            return;
        }
        atual = atual->prox;
    } while (atual != lista->inicio);

    printf("Música não encontrada!\n");
}

void visualizar_musicas(const Lista *lista) {
    if (lista->tamanho == 0) {
        printf("A lista está vazia!\n");
        return;
    }
    
    Musica *atual = lista->inicio;
    do {
        printf("Título: %s | Artista: %s | Duração: %02d:%02d\n",
               atual->titulo, atual->artista, atual->minutos, atual->segundos);
        atual = atual->prox;
    } while (atual != lista->inicio);
}

void limpar_lista(Lista *lista) {
    while (lista->tamanho > 0) {
        remover_musica(lista, lista->inicio->titulo);
    }
    printf("Lista de músicas limpa!\n");
}

void pesquisar_musica(const Lista *lista, const char *titulo) {
    if (lista->tamanho == 0) {
        printf("A lista está vazia!\n");
        return;
    }

    Musica *atual = lista->inicio;
    do {
        if (strcmp(atual->titulo, titulo) == 0) {
            printf("Música encontrada: %s - %s (%02d:%02d)\n", atual->titulo, atual->artista, atual->minutos, atual->segundos);
            return;
        }
        atual = atual->prox;
    } while (atual != lista->inicio);

    printf("Música não encontrada!\n");
}

void ordenar_musicas(Lista *lista) {
    if (lista->tamanho < 2) {
        printf("A lista está vazia ou tem apenas uma música!\n");
        return;
    }

    Musica *atual, *proximo;
    char temp_titulo[60], temp_artista[60];
    int temp_min, temp_seg;

    for (int i = 0; i < lista->tamanho; i++) {
        atual = lista->inicio;
        do {
            proximo = atual->prox;
            if (strcmp(atual->titulo, proximo->titulo) > 0) {
                strcpy(temp_titulo, atual->titulo);
                strcpy(temp_artista, atual->artista);
                temp_min = atual->minutos;
                temp_seg = atual->segundos;

                strcpy(atual->titulo, proximo->titulo);
                strcpy(atual->artista, proximo->artista);
                atual->minutos = proximo->minutos;
                atual->segundos = proximo->segundos;

                strcpy(proximo->titulo, temp_titulo);
                strcpy(proximo->artista, temp_artista);
                proximo->minutos = temp_min;
                proximo->segundos = temp_seg;
            }
            atual = atual->prox;
        } while (atual != lista->fim);
    }
    printf("Lista de músicas ordenada!\n");
}

void contar_musicas(const Lista *lista) {
    printf("Total de músicas: %d\n", lista->tamanho);
}

void liberar_lista(Lista *lista) {
    limpar_lista(lista);
    free(lista);
}
