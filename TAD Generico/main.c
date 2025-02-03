// Main dos Inteiros

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

// Função para imprimir um inteiro
void imprimir_int(void *dado) {
    printf("%d ", *(int*)dado);
}

// Função para liberar um inteiro
void liberar_int(void *dado) {
    free(dado);
}

int main() {
    // Cria uma lista
    Lista *lista = criar_lista();

    // Insere alguns inteiros na lista
    for (int i = 1; i <= 5; i++) {
        int *valor = (int*)malloc(sizeof(int));
        *valor = i * 10;
        inserir_no_inicio(lista, valor);
    }

    // Imprime a lista
    printf("Lista de inteiros: ");
    imprimir_lista(lista, imprimir_int);

    // Remove do início
    int *removido = (int*)remover_do_inicio(lista);
    printf("Removido do inicio: %d\n", *removido);
    free(removido);

    // Imprime a lista novamente
    printf("Lista apos remocao: ");
    imprimir_lista(lista, imprimir_int);

    // Tamanho da lista
    printf("Tamanho da lista: %d\n", tamanho_lista(lista));

    // Destroi a lista
    destruir_lista(lista, liberar_int);

    return 0;
}