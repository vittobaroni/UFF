//Dado um valor em centavos, imprimir todas as maneiras de representa-lo
// utilizando moedas de 1, 5, 10, 25, 50

#include <stdio.h>

void moedas(int *vet, int pos, int valor){
    int soma = 0;
    int centavos[]={1,5,10,25,50};
    if(pos == 5){
        for(int i = 0; i < 5; i++)
            soma = soma + vet[i] * centavos[i];
        if(soma == valor ){
            for(int i = 0; i < 5; i++){
                if(vet[i] != 0) // para não mostrar moedas que tenham 0 moedas do tipo
                    printf("    %d moedas de %d centavos",vet[i],centavos[i]);
            }printf("\n");   
        }
    }
    else{
        for(int i = 0; i <= valor/centavos[pos]; i++){
            vet[pos] = i;
            moedas(vet, pos + 1, valor);
        }
    }
}

int main(){
    int vet[5];
    int n = 20; // pra testar os valores, só mudar o valor de n
    moedas(vet,0,20);
}

