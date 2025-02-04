// Arvore binaria de Busca --> arvore que é ordenada, mas nao balanceada

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// estrutura de uma árvore

typedef struct arvore{
    int info;
    struct arvore *esquerda;
    struct arvore *direita;
} Arvore;

int existe(Arvore*a, int x){
    if(a == NULL)
        return 0;   // caso basem nao existe
    else{
        if(x == a->info)
            return 1;
        if(x < a -> info)
            return existe(a->esquerda,x );
        else{
            return existe(a->direita, x);
        }
    }
}

// imprimir é a mesma coisa que uma arvore comum, sendo pre, in e pos order


// imprimir valores que sao maiores ou iguais a x
void imprimirMaioresIguais(Arvore *a, int x){
    if(a != NULL){
        if(a -> info >= x){  // comparando a raiz ao x
            printf("%d", a->info);
            imprimirMaioresIguais(a->direita, x);
            imprimirMaioresIguais(a->esquerda, x);
        }
        else{
            imprimirMaioresIguais(a->direita, x);
        }
    }    
}

// imprimir elementos de uma abb maiores que x e menores que y
void Imprimir(Arvore *a, int x, int y){
    if(a!= NULL){   
        if(a-> info <= x)
            Imprimir(a->direita, x , y);
        if(a -> info >= y){
            Imprimir(a->esquerda, x, y);
        }
        else{
            printf("%d",a->info);
            Imprimir(a->esquerda, x , y);
            Imprimir(a->direita, x , y);
        }
    }
}

// toda vez que inserir um elemento, precisa manter a ordenação
// estrategia --> percorrer a abb ate encontrar NULL. entao inserir o elemento

Arvore *Inserir(Arvore *a, int x){
    if(a == NULL) {   // se chegar a null, ta na hora de inserir o elemento
        a = (Arvore*)malloc(sizeof(Arvore));
        a->info == x;
        a->esquerda = NULL;
        a->direita = NULL;
    }
    else{
        if(a -> info <= x)
            a->esquerda = Inserir(a->esquerda, x);  // necessario colocar o igual, pois como vai alterar a lista, é necessario atualizar o caminho dela
        else
            a->direita = Inserir(a->direita, x);    
    }
    return a;   
}

// quando for remover um elemento, mantendo a ordenaçao, precisamos considerar 3 coisas:
// 1 -> no a ser removido é folha ( so remover)
// 2-> no a ser removido possui 1 filho nulo    --> encontra o no, junta o filho nao nulo ao pai e remove
// 3 -> no nao possui filhos nulos  -> encontra o no, encontra o maior elemento y da subarvore da esquerda, substitui x por y, remove y da subarvore da esquerda de x

/*
Arvore* Remover(Arvore* a, int x){
    if(a!= NULL){
        if(a->info == x){
            // primeiro caso:
            if(a->esquerda == NULL && a->direita == NULL){
                free(a);
                return NULL;
            }
            // segundo caso
            else if(a->esquerda == NULL){
                Arvore *aux = a->esquerda;
                free(a);
                return aux;
            }
            else if(a->direita == NULL){
                Arvore *aux = a->direita;
                free(a);
                return aux;
            }
            else{   // terceiro caso
                Arvore *aux = a->esquerda;
                while(aux -> direita != NULL){  // subarvore da esquerda, pra achar o maior
                    aux = aux ->direita;
                }
                a->info = aux->info;        // atribuicao de valor, pra tirar depois
                a -> esquerda = Remover(a->esquerda, aux->info);    // tirou
            }
            else if ( x < a->info)
                a-> esquerda = Remover(a->esquerda, x);
            else
                a->direita = Remover(a->direita, x);
            return a;
        }
    }
}
*/


int altura(Arvore*a){
    if(a == NULL)
        return 0;
    else{
        int he = altura(a->esquerda);
        int hd = altura(a->direita);
        if(he > hd)
            return he + 1;
        if(he < hd)
            return hd + 1;
    }
}

void ImprimirNivel(Arvore *a, int cont, int nivel){
    if(a!=NULL){
        if(cont == nivel){
            printf("%d",a->info);
        }
        else{
            ImprimirNivel(a->esquerda, cont + 1, nivel +1);
            ImprimirNivel(a->direita, cont +1, nivel +1);
        }
    }
}

Arvore * Inserir2(Arvore*a, int x){
    if(a == NULL){  // se tiver chegar em NULL, precisamos alocar memoria para ele
        Arvore *no = (Arvore*)malloc(sizeof(Arvore));
        no -> info = x;
        no -> esquerda = NULL;
        no -> direita = NULL;
    }
    else{
        if(a->info <= x){
            a->esquerda = Inserir2(a->esquerda, x);
        }
        else{
            a->direita = Inserir(a->direita, x);
        }
    }
    return a;
}

void Imprimirfolhasmenores(Arvore*a, int x){
    if(a!= NULL){
        if(a->info < x){
            if(a->esquerda == NULL && a->direita == NULL){
                printf("%d", a->info);
                Imprimirfolhasmenores(a->esquerda, x);
                Imprimirfolhasmenores(a->direita,x);
            }
        }
        else
            Imprimirfolhasmenores(a->esquerda, x);
    }
}


int nivelno(Arvore*a, int x){   
    if(a != NULL){
        if(a -> info == x)
            return 0;
        else if( x < a -> info){
            return nivelno(a->esquerda, x) + 1;
        }
        else{
            return nivelno(a->direita, x) + 1;
        }
    }   
}