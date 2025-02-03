// Árvore geral --> nao linear, hierarquia e sem ciclos
// Muito importante para dar velocidade ao sistema

// cada elemento é o nó da arvore
// o no inicial é a raiz
// nos que possuem ambos os filhos NULOS sao folhas
// nos que nao sao folhas sao nos internos

// raiz ocupa o nivel 0
// a altura de uma arvore pode ser definida pela Quantidade de niveis de uma arvore ou a distancia (numero de nos no caminho)
// entre a raiz e a folha mais distantes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// estrutura de uma árvore

typedef struct arvore{
    int info;
    struct arvore *esquerda;
    struct arvore *direita;
} Arvore;

// vamos quebrar a arvore em tres grandes componentes : Raiz, Subarvore esquerda e Subarvore esquerda

// Assim como listas, NULL é uma condição de parada tradicional
// Analisar a raiz --> depois analisar as subarvores da esquerda e direita

void imprimir(Arvore *a){
    if(a !=NULL) {
        printf("%d", a->info);
        imprimir(a -> esquerda);
        imprimir(a->direita);
    }
}

 // impressao em largura (por niveis)

int existe(Arvore *a, int x){
    if(a == NULL){
        return 0;
    }
    else{
        if(a -> info == x)
            return 1;
        if(existe(a->esquerda, x) == x)
            return 1;
        if(existe(a->direita, x) == x)
            return 1;

        return 0;
    }
}

// precisamos primeiro de uma arvore na memoria !!
// notacao de identificacao da arvore
// Bota a raiz, sub esquerda, sub direita e (-1) pra arvore nula


void preorder(Arvore*a){
    if(a!=NULL){
        printf("%d",a->info);
        preorder(a->esquerda);
        preorder(a->direita);
    }
}

void inorder(Arvore*a){
    if(a!= NULL){
        inorder(a->esquerda);
        printf("%d",a->info);
        inorder(a->direita);
    }
}

void posordem(Arvore*a){
    if(a!=NULL){
        posordem(a->esquerda);
        posordem(a->direita);
        printf("%d",a->info);
    }
}

int existe2(Arvore*a, int x){   // recursao == caso base + resto
    if(a == NULL)
        return 0;
    else{
        if(a->info == x)
            return 1;
        if(a->esquerda == x)
            return 1;
        if(a->direita == x)
            return 1;
        
        return 0;
    }
}

int contar(Arvore*a){
    if(a == NULL){
        return 0;
    }
    return 1 + contar(a->esquerda) + contar(a->direita);
}

// imprimir nos folhas da arvore

void Folhas(Arvore*a){
    if(a == NULL);
        return NULL;    // caso base, nao ha arvore
    if(a-> esquerda == NULL && a->direita == NULL){
        return 1;
    }
    Folhas(a->esquerda);
    Folhas(a->direita);
}

int altura (Arvore*a){
    if(a == NULL)
        return 0;
    else{
        int he = altura(a->esquerda);
        int hd = altura(a->direita);
        if(he > hd)
            return he + 1;  // +1, para incluir a raiz
        else
            return hd + 1;
    }
}

void imprimirnivel(Arvore*a, int cont, int nivel){
    if(a != NULL){  // caso base
        if(cont == nivel)   // se onde começou é engal o nivel
            printf("%d",a->info);

        else{
            imprimirnivel(a->esquerda, cont + 1,nivel);
            imprimirnivel(a->direita, cont + 1, nivel);
        }
    }
}

int contnivel(Arvore *a, int cont, int nivel){
    if(a == NULL){
        return 0;   // nada para contar
    }
    if( cont == nivel){
        return 1;
    }
    return(a->esquerda, cont + 1, nivel) + contnivel(a->direita, cont + 1, nivel);
}

// arvore cheia == arvore que possui todos os nós em todos os seus niveis

// estrategia -> contar numero total de nos e verifiar se é igual a 2 elevado a h -1, onde h é a altura
// estrategia 2 --> contar apenas o numero de nos no ultimo nivel da arvore( nivel h -1 ) e verificar se é igual a 2 elevado a h -1

int cheia(Arvore*a, int cont, int nivel){
    if(a == NULL){
        return 1;   // arvore vazia é cheia
    }
    else{
        int x = contnivel(a,cont, altura(a)- 1);
        if(x == pow(x, altura(a)-1)){
            return 1;
        }
        else{
            return 0;
        }
    }
}

// arvore completa == todos os niveis estao completos ou se apenas o ultimo estiver incompleto
// no caso, veja se o penultimo nivel é igual a 2 elevado a H, sendo h a altura
// ex : nivel 3 precisa ter 8 nos, pois 2³ é 8

// ordenação --> dizemos qu eesta ordenada se todos os nos a esquerda ssao menores que a raiz
// e tudo que está maior está a direita



// dizemos que uma árvore binaria está balanceada se para todo nó x, as altiras das subárvores esquerda
// e direita diferem de no maximo uma unidade

int balanceada(Arvore*a){
    if(a == NULL){  // caso base
        return 1;
    }
    else{
        if(balanceada(a->esquerda) == 0 || balanceada(a->direita) == 0)
            return 0;
        else{
            int he = altura(a->esquerda);
            int hd = altura(a->direita);
            if(he - hd == 1 || he - hd == -1 || he - hd == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}

int cheia2(Arvore*a){
    if(a == NULL)
        return 1;   // arvore vazia = arvore cheia
    if(a -> esquerda == NULL && a -> direita == NULL)
        return 1;   // se o nó é folha, entao é valido
    if(a -> esquerda != NULL && a->direita != NULL)
        return cheia2(a->esquerda) && cheia2(a->direita);

    return 0;   // entra no caso se dele ter apenas um filho
}
