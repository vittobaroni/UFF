// avl = ordenada e balanceada

// contar quantas vezes aparece um numero

#include<stdio.h>
#include<stdlib.h>

typedef struct avl{
    int info;
    struct avl* esq;
    struct avl* dir;
} AVL;

