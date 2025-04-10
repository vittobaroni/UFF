/* Implemente um programa que apresente na telaw o seguinte menu de opções

1- Ler uma árvore de um arquivo fornecido pelo usuário  --> feito
2- Imprimir a árvore (pré-ordem, em-ordem, pós-ordem)   --> feito
3- Verificar se um elemento x existe na árvore --> feito
4- Contar o número de elementos na árvore --> feito
5- Imprimir os nós folhas da árvore --> feito
6- Sair



VERSAO ATUALIZADA : Adicionar a impressão em largura    --> feito 
                    Verificar se a árvore está balanceada   --> feito
                    Verificar se uma árvore é cheia     --> feito
                    imprimir o nível de um nó x --> pedir ajuda
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>   // math.h está dando problema na função POW, então criei uma função para
                    // simbolizar a potencia

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
        printf("%d ",a->info);
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
        if(cont == nivel){
            printf("%d ",a->info);
        }else{
            imprimir_nivel(a->esquerda,cont + 1,nivel);
            imprimir_nivel(a->direita,cont + 1, nivel);
        }
    }
}

//imprimir nivel do nó x

int imprimir_nivel_no(arvore*a,int x, int cont)
{
    if(a == NULL)
        return -1 ;
    else{
        if(a->info == x)
            return cont;
        else{
            return imprimir_nivel_no(a->esquerda, x, cont + 1) > imprimir_nivel_no(a->direita, x, cont + 1) ? imprimir_nivel_no(a->esquerda, x, cont + 1) : imprimir_nivel_no(a->direita,x, cont + 1);
        }
    }
}


//imprimir por largura

void imprimir_largura(arvore*a)
{
    if(a != NULL){
        for(int i = 0; i <= altura(a); i++){
            imprimir_nivel(a,0,i);
            printf("\n");
        }
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
        if(he - hd > 1 || hd - he > 1)
            return 0;
        else {
            if(!balanceada(a->esquerda) || !balanceada(a->direita))
              return 0;  
        }
    }
    return 1;
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



// função de potencia, ja que o math.h nao ta funcionando

int potencia(int base, int expoente)
{
    int aux = 1;
    for(int i = 1; i <= expoente;i++)
        aux = aux * base;
    return aux;
}

//verificar se a arvore esta cheia


int cheia(arvore*a)
{
    int h;
    if(a == NULL)
        return 1;
    else{
        h = altura(a);
        if(contar(a) == potencia(2,h)-1)
            return 1;
        else
            return 0;
    }
}


void imprimir_folhas(arvore *a)
{
    if(a!=NULL){   // uma arvore vazia é considerado uma folha ?
        if(a->esquerda == NULL && a->direita == NULL)
            printf("%d ", a->info);
        else{
            imprimir_folhas(a->direita);
            imprimir_folhas(a->esquerda);
        }
    }    
}

// função para desalocar memória da árvore

arvore* desalocar(arvore*a)
{
    if(a != NULL){
        desalocar(a->esquerda);
        desalocar(a->direita);
        free(a);
        return NULL;
    }
    return a;
}

// menu principal 


int main()
{
    int escolha;
    int escolha_ordem;
    arvore *a = NULL;
    FILE *arq = fopen("arq.txt", "rt");

    while(escolha!=9)
    {
        printf("\nBem vindo ao Menu . Qual opcao deseja escolher ?( leia a arvore primeiro )\n\n");
        printf("1- Ler uma arvore de um arquivo fornecido pelo usuario\n");
        printf("2- Imprimir arvore (pre-ordem, em-ordem, pos-ordem, em largura)\n");
        printf("3- Verificar se um elemento x existe na arvore\n");
        printf("4- Contar o numero de elementos na arvore\n");
        printf("5- Imprimir os nos folhas da arvore\n");
        printf("6- Verificar se uma arvore esta balanceada\n");
        printf("7- Verificar se uma arvore e cheia\n");
        printf("8- Imprimir o nivel de um no x\n");
        printf("9- Sair\n\n");
        escolha = 0;
        scanf("\n%d",&escolha);
        switch(escolha){

            case 1: 
                
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
            
            case 2:
                escolha_ordem = 0;
                while(escolha_ordem != 5){
                printf("\nComo deseja fazer?\n\n");
                printf("1- Pre-ordem\n");
                printf("2- Em-ordem\n");
                printf("3- Pos-ordem\n");
                printf("4- Em largura\n");
                printf("5- Sair\n\n");
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
                            printf("Largura: \n\n");
                            imprimir_largura(a);
                            break;
                        case 5:
                            printf("\nVoltando ao menu\n");
                            break;
                        default:
                            printf("\n numero invalido, tente outro ");
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
                printf("O total da arvore e de %d elementos\n\n",contar(a));
                break;
            case 5:
                imprimir_folhas(a);
                break;
            case 6: // balanceada
                balanceada(a);
                if(balanceada(a) == 1)
                    printf("A arvore esta balanceada !!!\n");
                else
                    printf("A arvore esta desbalanceada ......\n");
                break;
            case 7: // se é cheia ou nao
                if(cheia(a) == 1)
                    printf("a arvore esta cheia !");
                else
                    printf("a arvore nao esta cheia");
                break;
            case 8: // imprimir nivel de um nó x
                printf("Qual no quer saber o nivel ? ");
                int no = 0;
                scanf("%d",&no);
                if(imprimir_nivel_no(a, no, 0) == -1)
                    printf("Nao existe este no na arvore, tente outro");
                else
                    printf("o nivel do no %d e %d", no, imprimir_nivel_no(a,no, 0));
                break;
            case 9: // sair
                printf("Saindo do programa");
                break;
            default:
                printf("Numero invalido, tente de novo\n\n");
        }
    }
    desalocar(a);
    return 0;
}
