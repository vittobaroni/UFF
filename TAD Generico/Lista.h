#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    void *dado;           // Ponteiro genérico para o dado
    struct No *proximo;   // Ponteiro para o próximo nó
} No;

typedef struct {
    No *inicio;           // Ponteiro para o início da lista
    int tamanho;          // Tamanho da lista
} Lista;

// Funções essenciais
Lista* criar_lista();
void destruir_lista(Lista *lista, void (*liberar_dado)(void*));
void inserir_no_inicio(Lista *lista, void *dado);
void* remover_do_inicio(Lista *lista);
int tamanho_lista(Lista *lista);
void imprimir_lista(Lista *lista, void (*imprimir_dado)(void*));

#endif