
// recursao em listas

// Recursão --> Caso base (condição de parada) + formula recursiva

// ex : contador de 0 a 10

#include <stdio.h>

int cont(int n){
    if(n == 11)
        printf("\nFim da contagem");
    else{
        printf("\n%d",n);
        return cont(n+1);
    }
}   // saida esperada --> 0 1 2 3 4 5 6 7 8 9 10 Fim da contagem


// recursao em lista
// Cabeça == no inicial
// calda == demais nos

typedef struct lista{   // lista encadeada basica
    int info;
    struct lista *prox;
} Lista;

// analisar a cabeça e chamar a recursiva pra cauda

int verificar (int x, Lista*l){
    //Duas condições de parada : Se a lista for vazia e se L for igual a x
    if(l == NULL){
        return 0;
    }
    else{
        if(l->info == x){
            return 1;
        }
        else{
            l = l->prox;
            return verificar(x,l);
        }
    }
}

// Inserir elemento no final da lista
// 1 : verificar caso base

Lista *InserirFinal(Lista*l, int x){
    if(l == NULL){  // se l for null, entao nao ha elementos . Pra isso, devemos criar um no
        Lista *no = (Lista*)malloc(sizeof(Lista));
        no -> info = x;
        no -> prox = NULL;
        return no;
    }
    else{
        l -> prox = InserirFinal(l->prox, x);
        return l;
    }
}
// na main, seria necessario atualizar l, pois implementaria no final

// Somar todos os elementos da lista

int soma(Lista*l){
  if(l == NULL){   // condição de parada 
    return 0;
  }
  else{
    return l->info + soma(l->prox);
  }
}

// contar o numero de ocorrencias de um elemento x na lista
int cont(Lista*l,int x){
    if( l == NULL)
        return 0;
    else if(l -> info == x){
        return 1 + cont(l->prox,x);
    }
    else
        return cont(l->prox, x);
}

//Remover um elemento x da lista
Lista* Remover(Lista*l, int x){
    if(l == NULL){
        printf("Lista ja esta vazia !!");
    }
    else{
    }
}

Lista *remover(Lista* l, int x){
    if(l == NULL)
        return NULL;
    else
        if(l-> info == x){
            Lista*aux = l->prox;
            free(l);
            return aux;
        }
        else{
            l->prox = remover(l->prox, x);  // precisa atualizar o valor de l-> prox, pois a lista foi modificada
            return l;
        }
        return 1;
}

