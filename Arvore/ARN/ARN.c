// Arvore Rubro Negra = Ordenada, balanceada
// Todo nó é vermelho ou preto
// a raiz é preta
// NULL é preto

// se um no é vermelho, seu filho sao pretos
// a distancia entre a raiz ate qualquer null tem que ser exatamente a mesma quantidade de nos pretos

// nao podem ter nos consecutivos vermelhos

// balanceamento --> permite que uma das subarvores tenha ate o dobro da altura da outra subarvore

typedef struct arvoreRN{
    int info;
    char cor;   // 'p' ou 'v'
    struct arvoreRN* esq;
    struct arvoreRN* dir;
} arvoreRN;

// inserçoes e remoçoes tem que ser ajustadas com rotações

// inserçoes --> usando algoritmo de inserção de uma abb
// no inserido sempre é folha

// toda vez que voce for inserir um no, é inserido na cor vermelha

// cinco casos diferentes 
// 1 --> se for a raiz, pinte de preto
// 2 --> se o pai for preto, vermelho
// 3 --> 

#include <stdio.h>
#include <stdlib.h>

void imprimeVermlehos(arvoreRN* a, int x){
    if(a!= NULL){
        if(a -> cor == 'v' && a->info > x){
            printf("%d",a->info);
        }
        imprimeVermlehos(a->esq,x);
        imprimeVermlehos(a->dir,x);
    } else{
        imprimeVermlehos(a->dir, x);
    }
}

