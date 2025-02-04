// int heap[N] == declaração do vetor 
// int total = 0 --> variavel global


int indiceFilhoEsq(int x){
    int indice = (2*x) + 1;
    if(x >= total || indice >= total)
        return -1;
    else
        return indice;
}

// pra direita, so fazer + 2 em vez de +1

int indicepai(int x){
    int indice = (int)floor((x-1)/2);   // arredonda pra baixo
    if(x<= 0 || x>= total)
        return -1;
    else
        return indice;
}

//inserir um elemento
void Inserir(int *heap, int x){
    heap[total] = x;
    total++;
    
    Ajustar(heap, total -1);
}

void Ajustar(int *heap, int pos){
    if(pos != -1)   // NULL
        int pai = indicepai(pos);
        if(pai != -1){
            if(heap[pos] > heap[pai]){  // no maior que o pai ?
                int aux = heap[pos];
                heap[pos] = heap[pai];
                heap[pai] = aux;
                Ajustar(heap, pai);
            }
        }
}

void remover(int *heap){    // sempre remove a raiz
    if(total == 0)  // nao tem o que remover
        return -1;
    else{
        int retorno = heap[0];
        heap[0] = heap[total -1];
        total--;
        ajustar2(heap, 0);
        return retorno;
    }
}


