//Igual o ex1, mas que conte o numero de vezes que acontece

// dando erro na hora da impressão, perguntar para o professor

#include <stdio.h>

int cont(char *vet, int pos, int n, char *vetaux) {
    int cont_total = 0;
    if(pos == n){
        int cont_a = 0;
        int cont_e= 0;
        int cont_i = 0;
        for(int i = 0; i < n; i++){
            if(vet[i] = 'a')
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
            vet[pos] == vetaux[i];
            cont(vet, pos+1,n, vetaux);
        }
    }
    return cont_total;
}

int main(){
    int n = 3;
    char vet[n];
    char vetaux[] ={'a','e','i'};
    int total = cont(vet,0,n,vetaux);
    printf("Numero de vezes que isso acontece: %d",total);
}