// imprimir todas as combinações de {a,e,i} de tamanho N, que o número de a's
// é maior que a soma dos totais de e's e de i's

#include <stdio.h>

void comb(char *vet, int pos, int n, char *vetaux){

    if(pos == n){
        int cont_a = 0;
        int cont_e = 0;
        int cont_i = 0;

        for(int i = 0; i < n ; i++){
            if(vet[i] == 'a')
                cont_a++;
            else if(vet[i] == 'e')
                cont_e++;
            else
                cont_i++;
        }
        if(cont_a > (cont_e + cont_i)){
            for(int i = 0; i < n; i++)
                printf("%c ", vet[i]);
        printf("\n");
        }
    }
    else{
        for(int i = 0; i <= n; i++){
            vet[pos] = vetaux[i];
            comb(vet,pos+1,n,vetaux);
        }
    }
}

int main(){
    int n = 3;  // se quiser mudar o tamanho de n, basta mudar aqui 
    char vetaux[] ={'a','e','i'};
    char vet[n];
    comb(vet,0,n,vetaux);
}
 