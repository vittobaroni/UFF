//imprimir todas as combinações de {15,31,55,54} , de tamanho N, cuja soma dos elementos da combinação é par
#include <stdio.h>

void comb(int *vet, int pos, int n, int *vetaux){
    if(pos == n){
        int soma = 0;
        for(int i = 0; i < n; i++){
            soma = soma + vet[i];
        }
        if(soma % 2 == 0){
            for(int i = 0; i < n; i++)
                printf("%d ",vet[i]);
        printf("\n");
        }
    } else{
        for(int i = 0; i <= n ; i++){
            vet[pos] = vetaux[i];
            comb(vet,pos+1,n,vetaux);
        }
    }       
}

int main(){

    int n = 4;     // pra mudar o tamanho, só mudar aqui;
    int vet[n];
    int vetaux[] = {15,31,55,54};
    comb(vet,0,n,vetaux);
    
}