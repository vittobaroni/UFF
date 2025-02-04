// TAD --> dar liberdade para o usuario, ocultando informações desnecessarias

// separação em dois arquivos --> arq.h e arq.c
// informações que eu quero que o usuario saiba == .h
// nao quero que saiba == .c

// é como se fosse se fosse um videogame
// pra pessoa mover o personagem, ou clicar em alguma opção no menu, ela nao precisa saber como foi feito
// apenas saber que tem como clicar ou mover o personagem

// ou seja, nos arquivos .h ficarao o cabeçalho (apenas a chamada da função)
// nos .c, fica a implementação das funções


// NO ARQUIVO .C

#include "pilha.h"

struct pilha{
    int vet[n];
    int topo;
} ;

int Push(Pilha p, int x)
// codigo aqui embaixo

int Pop(Pilha p, int 8x)

// codigo

void Imprimir(Pilha p)


// NO ARQUIVO .H

typedef struct pilha *Pilha;    // precisa desse ponteiro, para estar definido
int Push(Pilha*p, int x);
int Pop(Pilha*p, int*x);
void Imprimir(Pilha p);
Pilha inicializar();
Pilha Destruir(Pilha p);



// a materia é basicamente isso : em .h, tu so usa o cabeçalho das funções
// no .c, tu implementa as funções
// o include fica no arquivo.c e puxa do .h
// no .h, puxa a struct do .c com um ponteiro entre o nome e o renamen da struct


