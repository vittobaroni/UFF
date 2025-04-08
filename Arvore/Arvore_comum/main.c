/* Implemente um programa que apresente na telaw o seguinte menu de opções

1- Ler uma árvore de um arquivo fornecido pelo usuário
2- Imprimir a árvore (pré-ordem, em-ordem, pós-ordem)
3- Verificar se um elemento x existe na árvore
4- Contar o número de elementos na árvore
5- Imprimir os nós folhas da árvore --> corrigido
6- Sair



VERSAO ATUALIZADA : Adicionar a impressão em largura    --> feito (pedir correção)
                    Verificar se a árvore está balanceada   --> feito
                    Verificar se uma árvore é cheia     --> feito
                    imprimir o nível de um nó x --> pedir ajuda
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//estrutura da árvore

typedef struct Arvore{
    int info;
    struct Arvore* direita;
    struct Arvore* esquerda;
} arvore;

// Função para ler uma árvore de um arquivo 

arvore *LerArvore(FILE*arq)
{
    char c;
    int num;

    fscanf(arq,"%c",&c);    // ler '('
    fscanf(arq,"%d",&num);  // ler numero

    if(num == -1){      // se for null, vai colocar ')'
        fscanf(arq,"%c",&c);
        return NULL;
    }
    else {
        arvore *a =(arvore*)malloc(sizeof(arvore));
        a -> info = num;
        a->esquerda = LerArvore(arq);
        a->direita = LerArvore(arq);
        fscanf(arq,"%c",&c);    // ler ')'
        return a;
    }
}


// Imprimir a árvore

 void preordem(arvore*a)
 {
    if(a!=NULL){
        printf("%d ",a->info);
        preordem(a->esquerda);
        preordem(a->direita);
    }
 }

 void emordem(arvore*a)
 {
    if(a!=NULL){
        emordem(a->esquerda);
        printf("%d ",a->info);
        emordem(a->direita);
    }
 }

 void posordem(arvore *a)
 {
    if(a!=NULL){
        posordem(a->esquerda);
        posordem(a->direita);
        printf("%d",a->info);
    }
 }

// calculo da altura, para ajudar nas outras funções

int altura(arvore*a)
{
    if(a == NULL)
        return 0;
    else{
        int he = altura(a->esquerda);
        int hd = altura(a->direita);
        if(he > hd)
            return he + 1;
        else
            return hd + 1;
    }
}

//imprimindo por nivel

void imprimir_nivel(arvore*a, int cont, int nivel)
{
    if(a != NULL){
        if(cont == nivel)
            printf("%d",a->info);
        else{
            imprimir_nivel(a->esquerda,cont + 1,nivel);
            imprimir_nivel(a->direita,cont + 1, nivel);
        }
    }
}

//imprimir nivel do nó x

int imprimir_nivel_no(arvore*a,int x)
{
    if(a == NULL)
        return -1 ;
    else{
        if(a->info == x)
            return 0;
        else{
        }
    }
}







//imprimir por largura

void imprimir_largura(arvore*a)
{
    if(a != NULL){
        for(int i = 0; i <= altura(a); i++)
            imprimir_nivel(a,0,i)
    }
}

// verificar se um elemento x existe na lista

int existe(arvore *a, int x)
{
    if(a == NULL){  // raiz é nula ?
        return 0;
    }
    else{
        if(a->info == x){
            return 1;
        }
        else{
            return existe(a->esquerda,x) || existe(a->direita, x);
        }
    }
}

// vendo se a arvore é balanceada

int balanceada(arvore*a){
    if(a == NULL)
        return 1;
    else{
        int he = altura(a->esquerda);
        int hd = altura(a->direita);
        if(he - hd > 1 || hd - hd > 1)
            return 0;
        else
            return 1;
    }
}


//verificar se a arvore esta cheia

int cheia(arvore*a)
{
    if(a == NULL)
        return 1;
    else
        int h = altura(a);
        if(contar(a) == pow(2,h) - 1 )
            return 1;
        else
            return 0;
}

//contar o numero de elementos na arvore

int contar(arvore*a)
{
    if(a == NULL){
        return 0;
    }
    else{
        return 1 + contar(a->esquerda) + contar(a->direita);
    }
}

void imprimir_folhas(arvore *a)
{
    if(a!=NULL){   // uma arvore vazia é considerado uma folha ?
        if(a->esquerda == NULL && a->direita == NULL)
            printf("%d ", a->info);
    }
    imprimir_folhas(a->direita);
    imprimir_folhas(a->esquerda);
}

int main()
{
    int escolha;
    int escolha_ordem;
    arvore *a = NULL;

    while(escolha!=6)
    {
        printf("\nBem vindo ao Menu . Qual opcao deseja escolher ?\n\n");
        printf("1- Ler uma arvore de um arquivo fornecido pelo usuario\n");
        printf("2- Imprimir arvore (pre-ordem, em-ordem, pos-ordem)\n");
        printf("3- Verificar se um elemento x existe na arvore\n");
        printf("4- Contar o numero de elementos na arvore\n");
        printf("5- Imprimir os nos folhas da arvore\n");
        printf("6- Sair\n\n");
        scanf("\n%d",&escolha);
        switch(escolha){

            case 1: {
                FILE *arq = fopen("arq.txt", "rt");
                if (arq == NULL) {
                    printf("Erro ao abrir o arquivo.\n");
                } else {
                    a = LerArvore(arq);
                    fclose(arq);
                    if (a != NULL) {
                        printf("\nArvore lida com sucesso!\n");
                    } else {
                        printf("\nErro: arvore vazia ou mal formatada.\n");
                    }
                }
                break;
            }
            case 2:
                while(escolha_ordem != 4){
                printf("como deseja fazer?\n\n");
                printf("1- pre-ordem\n");
                printf("2- em-ordem\n");
                printf("3- pos-ordem\n");
                printf("4- voltar ao menu\n\n");
                scanf("%d",&escolha_ordem);
                    switch(escolha_ordem){
                        case 1:
                            printf("Pre-ordem: ");
                            preordem(a);
                            break;
                        case 2:
                            printf("Em-ordem: ");
                            emordem(a);
                            break;
                        case 3:
                            printf("pos-ordem: ");
                            posordem(a);
                            break;
                        case 4:
                            printf("\nvoltando pro menu\n");
                            break;
                    }
            }
                break;
            case 3:
                printf("\nQual valor deseja verificar se existe ?");
                int x;
                scanf("%d",&x);
                existe(a,x);
                if(existe(a,x) == 1)
                    printf("\nO numero existe!\n");
                else
                    printf("\nO numero nao existe ..........\n");
                break;
            case 4:
                printf("O total da arvore e de %d elementos",contar(a));
                break;
            case 5:
                imprimir_folhas(a);
                break;
            case 6:
                printf("\nSaindo do programa");
                free(a);
                break;
        }
    }
    return 0;
}
