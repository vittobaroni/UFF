// hashing --> tabela de dispersao
int hash(int key, int size){
    return key % size;
}    


void inserir(int *vet, int x){
    int pos = hash(x, n);
    while(vet[pos] != -1){  // se a posição nao for vazia
        pos = (pos + 1) % N;    // vai pular pra proxima casa
    }
    vet[pos] = x;       // vai atualizar o valor dela
}


int buscar(int *vet, int*ret){  // para se encontra ou encontra -1
    int pos = hash(x);
    while(vet[pos] != -1 && vet[pos] != x){
        pos = (pos + 1) %N;
    }
    if( vet[pos] == -1)
        return 0;
    else{
        *ret = pos; // variavel de retorno para dizer que achou o elemento
        return 1;
    }
}

// em vex de fazer com +1, voce calcula o hash2, que é o deslocamento
// ai voce cria uma variavel chamada deslocalmento que recebe hash2, e onde tem +1, tu troca export
// por deslocamento


// hash que tem uma lista encadeada

void inserir(lista *vet, int x){
    int pos = hash(x, n);
    lista *no = (lista*)malloc(sizeof(lista));
    no->info = x;
    no->prox = vet[pos];
    vet[pos] = no;  // insere o elemento no inicio da lista
}

int buscar(lista *vet, int x, lista*ret){
    int pos = hash(x);
    lista *p = vet[pos];
    while(p!= NULL){
        if(p->info == x){
            *ret = p;
            return 1;
        }
        p = p-> prox;
    }
    return 0;   // nao achou
}


