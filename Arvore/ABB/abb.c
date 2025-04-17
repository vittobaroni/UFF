/* QUESTÕES PEDIDAS :

1 - Ler uma árvore de um arquivo fornecido pelo usuário
2 - Imprimir a árvore (Pré-ordem, Em-Ordem, Pós-ordem, em largura)
3 - Verificar se um elemento x existe na árvore
4 - Imprimir o nível de um nó x
5 - Imprimir as folhas menores que um valor x
6 - Inserir um nó x na árvore
7 - Remover um nó x da árvore
8 - Sair


*/


#include <stdio.h>
#include <stdlib.h>

// criação da arvore

typedef struct Arvore{
    int info;
    struct Arvore* esquerda;
    struct Arvore* direita;
}arvore;


// Função para o arquivo txt

arvore *LerArvore(FILE *ABB) 
{
    char c;
    int num;

    fscanf(ABB,"%c",&c);    // ler '('
    fscanf(ABB,"%d",&num);  // ler numero

    if(num == -1){
        fscanf(ABB,"%c",&c); // se for null, vai fechar com )
        return NULL; 
    }
    else{
        arvore *a= (arvore*)malloc(sizeof(arvore));
        a->info = num;
        a->esquerda = LerArvore(ABB);
        a->direita = LerArvore(ABB);
        fscanf(ABB,"%c",&c);    // ler o ')'
        return a;
    }
}


// funções para imprimir a arvore

void preordem(arvore*a)
{
    if(a!=NULL){
        printf("%d ",a->info);
        preordem(a->esquerda);
        preordem(a->direita);
    }
}

void emordem(arvore *a)


// criação da main

int main()
{
    arvore *a = NULL;
    FILE *ABB = fopen("ABB.txt","rt");

    int escolha;
    int escolha_ordem;
    while(escolha!=8){
 
        printf("\n\nBem vindo ao Menu. Qual opcao deseja escolher ? (1 primeiro para ler a arvore) ");
        printf("\n\n1- Ler uma arvore");
        printf("\n2- Imprimir a arvore");
        printf("\n3- Verificar se um elemento x existe na arvore");
        printf("\n4- Imprimir o nivel de um no x");
        printf("\n5- Imprimir as folhas menores que um valor x");
        printf("\n6- Inserir um no x na arvore");
        printf("\n7- Remover um no x da arvore");
        printf("\n8- Sair\n\n");
        escolha = 0;
        scanf("\n%d",&escolha);

        switch(escolha){
            case 1: // ler arvore
            if(ABB == NULL)
                printf("Erro ao abrir o arquivo");
            else{
                a = LerArvore(ABB);
                fclose(ABB);
                if(a != NULL)
                    printf("Arvore lida com sucesso !!!");
                else
                    printf("Erro: arvore vazia ou mal formatada");
                break;
            }
                break;
            case 2: // imprimir a arvore
                while(escolha_ordem != 5){

                    printf("Qual metodo deseja imprimir a arvore?\n\n");
                    printf("1- Pre-ordem\n");
                    printf("2- Em-ordem\n");
                    printf("3- Pos-ordem\n");
                    printf("4- Em largura\n");
                    printf("5- Voltar ao menu\n\n");
                    escolha_ordem = 0;
                    scanf("%d",&escolha_ordem);
                    switch(escolha_ordem){
                        case 1: // pre ordem
                            break;
                        case 2 :    // em ordem
                            break;
                        case 3: // pos ordem
                            break;
                        case 4: // em largura
                            break;
                        case 5: // voltar ao menu
                            break;
                        default:    // numero invalido
                            printf("Opcao invalida . Tente novamente");
                            break;
                    }
                }
                break;
            case 3: // verificar se um elemento x existe na arvore
                printf("\n\n Qual numero quer verificar ? ");
                int num;
                scanf("%d",&num);
                break;
            case 4: // imprimir o nivel de um no x
                break;
            case 5: // imprimir folhas menores que um valor x
                break;
            case 6: // inserir um no x na arvore
                printf("Qual numero quer inserir ? ");
                int inserir;
                scanf("%d",&inserir);
                break;
            case 7: // remover um no x da arvore
                printf("Qual numero quer remover ?");
                int remover;
                scanf("%d",&remover);
                break;
            case 8: // sair do programa
                printf("Saindo do menu");
                break;
            default:
                printf("Opcao invalida . Tente novamente");
                break;
        }
    }
}
