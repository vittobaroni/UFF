//Igual o ex1, mas que conte o numero de vezes que acontece

// dando erro na hora da impressão, perguntar para o igor --> corrigido, era só passar cont_total como global e não como local

#include <stdio.h>

int cont_total = 0;

int cont(char *vet, int pos, int n, char *vetaux) {

    
    if(pos == n){
        int cont_a = 0;
        int cont_e= 0;
        int cont_i = 0;
        for(int i = 0; i < n; i++){
            if(vet[i] == 'a')
                cont_a++;
            else if(vet[i] == 'e')
                cont_e++;
            else
                cont_i++;
        }
        if(cont_a >(cont_e + cont_i)){
            cont_total++;
        }
    }
    else{
        for(int i = 0; i <= n; i++){
            vet[pos] = vetaux[i];
            cont(vet, pos+1,n, vetaux);
        }
    }
    return cont_total;
}

int main(){
    int n = 3;  // basta mudar essa variavel pra mudar o tamanho das combinações
    char vet[n];
    char vetaux[] ={'a','e','i'};
    int total = cont(vet,0,n,vetaux);
    printf("Numero de vezes que existem mais a's do que e's e i's: %d \n",total);
}