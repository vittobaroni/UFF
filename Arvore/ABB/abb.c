/* QUESTÕES PEDIDAS :

1 - Ler uma árvore de um arquivo fornecido pelo usuário --> feito
2 - Imprimir a árvore (Pré-ordem, Em-Ordem, Pós-ordem, em largura)--> feito
3 - Verificar se um elemento x existe na árvore --> feito 
4 - Imprimir o nível de um nó x --> feito
5 - Imprimir as folhas menores que um valor x  --> feito 
6 - Inserir um nó x na árvore --> corrigir
7 - Remover um nó x da árvore --> corrigir
8 - Sair --> feito

Pedir ajuda para o monitor sobre 6 e 7

acontece a inserção / remoção , mas adiciona é como se adicionasse em uma nova variavel



OBSERVAÇÃO : FALTA IMPLEMENTAR NA MAIN A MAIORIA
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
{
    if(a!= NULL){
        emordem(a->esquerda);
        printf("%d ", a->info);
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

int altura(arvore *a)
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

int imprimir_nivel_no(arvore*a, int x, int cont)    // fiz uma versão melhor da mesma função da arvore binaria
{
    if(a == NULL)
        return -1;
    else{
        if(a->info == x)
            return cont;

        int nivel_esquerda = imprimir_nivel_no(a->esquerda, x , cont + 1);
        int nivel_direita = imprimir_nivel_no(a->direita, x , cont + 1 );

        if(nivel_esquerda != -1)
            return nivel_esquerda;
        else
            return nivel_direita;
    }
}

int imprimir_nivel(arvore*a, int cont, int nivel)
{
    if(a!= NULL){
        if(cont == nivel)
            printf("%d ",a->info);
        else{
            imprimir_nivel(a->esquerda, cont + 1, nivel);
            imprimir_nivel(a->direita, cont + 1, nivel);
        }
    }
}
void imprimir_largura(arvore*a)
{
    if(a!= NULL){
        for(int i = 0; i < altura(a); i++){
            imprimir_nivel(a,0,i);
            printf("\n");
        }
    }
}

int existe(arvore *a, int x)    // necessario tirar proveito da ordenação
{
    if(a == NULL)
        return 0;
    else{
        if(a->info == x)
            return 1;
        else if(x < a->info)
           return existe(a->esquerda,x);
        else
           return existe(a->direita,x);
    }
}

void folhas(arvore* a, int x)
{
    if (a != NULL) {
        if (a->esquerda == NULL && a->direita == NULL) {
            // é folha
            if (a->info < x)
                printf("%d ", a->info);
        } else {
            // não é folha, continua a busca
            folhas(a->esquerda, x);
            folhas(a->direita, x);
        }
    }
}


arvore* inserir(arvore*a, int x)
{
    if(a == NULL){
        a = (arvore*)malloc(sizeof(arvore));
        a->info = x;
        a->esquerda = NULL;
        a->direita = NULL;
    }
    else if(x <= a->info){
        a->esquerda = inserir(a->esquerda,x);
    } else{
        a->direita = inserir(a->direita,x);
    }
}

arvore* remover(arvore* a, int x) {
    if (a == NULL)
        return NULL;

    if (x < a->info) {
        a->esquerda = remover(a->esquerda, x);
    }
    else if (x > a->info) {
        a->direita = remover(a->direita, x);
    }
    else {
        // Achou o nó a remover
        if (a->esquerda == NULL && a->direita == NULL) {
            // Caso 1: folha
            free(a);
            return NULL;
        }
        else if (a->esquerda == NULL) {
            // Caso 2: só tem filho à direita
            arvore* aux = a->direita;
            free(a);
            return aux;
        }
        else if (a->direita == NULL) {
            // Caso 2: só tem filho à esquerda
            arvore* aux = a->esquerda;
            free(a);
            return aux;
        }
        else {
            // Caso 3: dois filhos
            arvore* aux = a->esquerda;
            while (aux->direita != NULL)
                aux = aux->direita;

            a->info = aux->info;
            a->esquerda = remover(a->esquerda, aux->info);
        }
    }

    return a;
}


// desalocar memoria da arvore

arvore* desalocar(arvore*a)
{
    if(a!= NULL){
        desalocar(a->esquerda);
        desalocar(a->direita);
        free(a);
        return NULL;
    }
    return a;
}


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
                escolha_ordem = 0;
                while(escolha_ordem != 5){
                    printf("Qual metodo deseja imprimir a arvore?\n\n");
                    printf("1- Pre-ordem\n");
                    printf("2- Em-ordem\n");
                    printf("3- Pos-ordem\n");
                    printf("4- Em largura\n");
                    printf("5- Voltar ao menu\n\n");
                    scanf("%d",&escolha_ordem);
                    switch(escolha_ordem){
                        case 1: // pre ordem
                            printf("Pre-ordem: ");
                            preordem(a);
                            break;
                        case 2 :    // em ordem
                            printf("Em-ordem: ");
                            emordem(a);
                            break;
                        case 3: // pos ordem
                            printf("Pos-ordem: ");
                            posordem(a);
                            break;
                        case 4: // em largura
                            printf("Em largura: \n");
                            imprimir_largura(a);
                            break;
                        case 5: // voltar ao menu
                            printf("\n Voltando ao menu\n");
                            break;
                        default:    // numero invalido
                            printf("Opcao invalida . Tente novamente");
                            break;
                    }
                }
                break;
            case 3:{ // verificar se um elemento x existe na arvore
                printf("\n\n Qual numero quer verificar ? ");
                int num;
                scanf("%d",&num);
                existe(a,num);
                if(existe(a,num) == 1)
                    printf("O numero existe !!\n");
                else
                    printf("O numero nao existe .....\n");
                break;
            }
            case 4:{ // imprimir o nivel de um no x
                printf("Qual no quer saber o nivel ? ");
                int no = 0;
                scanf("%d",&no);
                imprimir_nivel_no(a,no,0);
                if(imprimir_nivel_no(a,no,0) == -1)
                    printf("O numero nao existe na arvore .......");
                else
                    printf("O nivel do no %d e %d",no,imprimir_nivel_no(a,no,0));
                break;
            }
            case 5:{ // imprimir folhas menores que um valor x
                printf("Qual o valor que quer saber ? ");
                int x ;
                scanf("%d",&x);
                folhas(a,x);
                break;
            }
            case 6:{ // inserir um no x na arvore
                printf("Qual numero quer inserir ? ");
                int ins;
                scanf("%d",&ins);
                inserir(a,ins);
                printf("%d adicionado na arvore",ins);
                break;
            }
            case 7:{ // remover um no x da arvore
                printf("Qual numero quer remover ?");
                int rmv;
                scanf("%d",&rmv);
                remover(a,rmv);
                printf("%d removido da arvore",rmv);
                break;
            }
            case 8: // sair do programa
                printf("Saindo do menu");
                break;
            default:
                printf("Opcao invalida . Tente novamente");
                break;
        }
    }
    desalocar(a);
    return 0;
}
