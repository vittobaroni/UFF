#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Cria uma nova lista vazia
Lista* criar_lista() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    if (lista) {
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

// Destroi a lista e libera a memória
void destruir_lista(Lista *lista, void (*liberar_dado)(void*)) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        if (liberar_dado) {
            liberar_dado(atual->dado); // Libera o dado, se a função for fornecida
        }
        free(atual); // Libera o nó
        atual = proximo;
    }
    free(lista); // Libera a estrutura da lista
}

// Insere um dado no início da lista
void inserir_no_inicio(Lista *lista, void *dado) {
    No *novo_no = (No*)malloc(sizeof(No));
    if (novo_no) {
        novo_no->dado = dado;
        novo_no->proximo = lista->inicio;
        lista->inicio = novo_no;
        lista->tamanho++;
    }
}

// Remove e retorna o dado do início da lista
void* remover_do_inicio(Lista *lista) {
    if (lista->inicio == NULL) {
        return NULL; // Lista vazia
    }

    No *primeiro = lista->inicio;
    void *dado = primeiro->dado;
    lista->inicio = primeiro->proximo;
    free(primeiro);
    lista->tamanho--;
    return dado;
}

// Retorna o tamanho da lista
int tamanho_lista(Lista *lista) {
    return lista->tamanho;
}

// Imprime a lista (requer uma função para imprimir o dado)
void imprimir_lista(Lista *lista, void (*imprimir_dado)(void*)) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        imprimir_dado(atual->dado); // Chama a função para imprimir o dado
        atual = atual->proximo;
    }
    printf("\n");
}