// estrutura generica --> uso de uma mesma estrutura de dados em situações diferentes

// componente chave --> tipo de dado void* --> podemos converter pra qualquer tipo

// ex : criar um exemplo que armazene veiculos - motos (paca, modelo, cor e ano)
// e carros ( renavam, nome e ano)

typedef struct moto{
    char placa[10];
    char modelo[50];
    char cor[25];
    int ano;
} moto;

typedef struct carro{
    char renavam[50];
    char nome;
    int ano;
} carro;

typedef struct veiculo{
    int tipo;   // 1 para moto e 2 para carro
    void*item;  // armazena ou moto ou carro
} veiculo;

//declaração do vetor

veiculo vet[100];   // declaracao estatica

void inserir(Veiculo *vet, int pos, void* info, int tipo){
    vet[pos].tipo = tipo ;
    vet[pos].item = item ;
    
// se quiser inserir, como faz ?
// 1-> inserir uma moto na posição 0
// 2-> declara um ponteiro
//3 -> aponta para onde esta apontando em item
// 4 -> ler quais informações deseja agora

}
// com carro nao mudaria quase nada, apenas o ponteiro e os parametros depois
// quando fosse chamar a função na main, o tipo seria chamado em 1 ou 2

// qualquer estrutura que for trabalhar, inicializar ela

void inicializar(Veiculo *vet, int tam){
    int i;
    for(i = 0; i < tam, i ++){
        vet[i].tipo = 0;
        vet[i].item = NULL;
    }
}

void imprimirCarros(veiculo*vet, int tam){
    int i;
    for(i = 0; i < tam; i++){
        if(vet[i].tipo == 2){ // 2, pois é o carro
        
            carro*c = (carro*)vet[i].item;
            printf("%c %c %d", c-> renavam, c->nome, c->ano );
        }
    }    
}

int Contar2010(veiculo *vet, int tam){
    
    int i;
    int cont = 0;
    for(i = 0; i < tam; i++){
        if(vet[i].tipo == 1){    // significa que é moto
            moto*m = (moto*)vet[i].tipo
            if(m->ano > 2010)
                cont++;
        }
        else if(vet[i].tipo == 2){
            carro*c = (carro*)vet[i].item;
            if(c->ano > 2010)
                cont++;
        }
    }
    return cont;
}

int placamoto(veiculo *vet, int tam, char *placa){
    int i;
    for(i = 0; i < tam; i++){
        if(vet[i].tipo == 1){   // significa que é moto
            moto*m=(moto*)vet[i].tipo;
            if(strcmp(placa, m->placa) == 0)
                return 1;
        }
    }
    return 0;
}

// pra remover, teria que criar um ponteiro aux que vai receber o renavam, e dar free no renavam

void removercarro(veiculo *vet, int tam, char*renavam){
    int i;
    for(i = 0; i < tam; i ++){
        if(vet[i].tipo == 2){
            carro*c(carro*)vet[i].item;
            if(strcmp(renavam, c->renavam) == 0){
                vet[i].tipo = 0;    // remover o tipo botando o tipo dele igual a zero
                free(vet[i].item);  // pois quando alocou espaço para o carro e/ou moto, é necessario dar um free nele
                vet[i].item = NULL;     // precisa ser null, pois como é im ponteiro, precisa apontar para agum lugar
            }
        }
    }
}



/////////////////////////

// questao 4 p2

typedef struct refeicao{
    int id;
    char nome[50];
    int calorias;
    char tipo[30];
    float custo;
} refeicao

typedef struct sobremesa{
    int id;
    char nome [50];
    int calorias;
    char sabor[50];
    float custo;
} sobremesa

typedef struct generico{
    int tipo;   // 1 pra refeicao e 2 pra sobremesa
    void*item;
} generico;


int contar_menos_250(generico *vet, int tam){
    int i;
    for(i = 0; i < tam; i++){
        int cont;
        if(vet[i].tipo == 1){
            refeicao *r = (refeicao*)vet[i].item;
            if(r-> calorias < 250)
                cont++;
        }
        else if(vet[i].tipo == 2){
            sobremesa *r = (sobremesa*)vet[i].item;
            if(r-> calorias < 250)
                cont ++;
        }
    }
    return cont;
}

void remover(generico *vet, int tam, char*nome){
    int i;
    for(i = 0; i < tam; i++){
        if(vet[i].tipo == 1){
            refeicao*r = (refeicao*)vet[i].item;
            if(strcmp(nome, r->nome) == 0){
                vet[i].tipo = 0;    //anula o valor do tipo
                free(vet[i].item);
                vet[i].item = NULL;
            }
        }
        else if(vet[i].tipo == 2){
            sobremesa*s = (sobremesa*)vet[i].item;
            if(strcmp(nome, s->nome) == 0){
                vet[i].tipo = 0;
                free(vet[i].item);
                vet[i].item = NULL;
            }
        }
    }
}

