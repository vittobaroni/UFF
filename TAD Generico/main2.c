// main da char

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

// Função para imprimir uma string
void imprimir_string(void *dado) {
    printf("%s ", (char*)dado);
}

// Função para liberar uma string
void liberar_string(void *dado) {
    free(dado);
}

int main() {
    // Cria uma lista
    Lista *lista = criar_lista();

    // Insere algumas strings na lista
    char *nomes[] = {"Breno", "Samuel", "Dudu", "Valim", "Nicolas"};
    for (int i = 0; i < 5; i++) {
        char *nome = (char*)malloc(strlen(nomes[i]) + 1);
        strcpy(nome, nomes[i]);
        inserir_no_inicio(lista, nome);
    }

    // Imprime a lista
    printf("Lista de strings: ");
    imprimir_lista(lista, imprimir_string);

    // Remove do início
    char *removido = (char*)remover_do_inicio(lista);
    printf("Removido do inicio: %s\n", removido);
    free(removido);

    // Imprime a lista novamente
    printf("Lista apos remocao: ");
    imprimir_lista(lista, imprimir_string);

    // Tamanho da lista
    printf("Tamanho da lista: %d\n", tamanho_lista(lista));

    // Destroi a lista
    destruir_lista(lista, liberar_string);

    return 0;
}