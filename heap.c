#include <stdio.h>
#include <locale.h>
#include <math.h> // Para o uso de floor()

// Implementar uma minheap --> para todo nó não raiz, o valor do nó pai é menor ou igual ao valor do nó i

int totalElementos = 0; // armazenará a quantidade de elementos no heap

// Retorna o índice do filho esquerdo de um nó
int IndiceFilhoEsquerda(int x) {
    int indice = (2 * x) + 1;
    if (x >= totalElementos || indice >= totalElementos)
        return -1; // Se o nó não tem filho esquerdo
    else
        return indice;
}

// Retorna o índice do filho direito de um nó
int IndiceFilhoDireita(int x) {
    int indice = (2 * x) + 2;
    if (x >= totalElementos || indice >= totalElementos)
        return -1; // Se o nó não tem filho direito
    else
        return indice;
}

// Retorna o índice do pai de um nó
int IndicePai(int x) {
    int indice = (int)floor((x - 1) / 2); // Calcula o índice do pai
    if (x <= 0 || x >= totalElementos)
        return -1; // Se o nó não tem pai
    else
        return indice;
}

// Ajusta a posição de um elemento subindo no heap
void AjustarSubindo(int *heap, int pos) {
    int pai = IndicePai(pos); // Calcula o índice do pai
    if (pai != -1 && heap[pos] < heap[pai]) { // Se o nó atual for menor que o pai
        int aux = heap[pos];
        heap[pos] = heap[pai]; // Troca os valores
        heap[pai] = aux;
        AjustarSubindo(heap, pai); // Continua ajustando no nível superior
    }
}

// Adiciona um novo elemento no heap
void Inserir(int *heap, int x) {
    if (totalElementos >= 12) { // Limite máximo do heap
        printf("Erro: Heap está cheio. Não é possível inserir mais elementos.\n");
        return;
    }
    heap[totalElementos] = x;   // Adiciona x no final do heap
    totalElementos++;           // Incrementa o contador de elementos no heap
    AjustarSubindo(heap, totalElementos - 1); // Ajusta a posição do novo elemento
}

// Ajusta a posição de um elemento descendo no heap
void AjustarDescendo(int *heap, int pos) {
    if (pos != -1 && IndiceFilhoEsquerda(pos) != -1) { // Descobrindo o menor filho
        int IndiceMenorFilho = IndiceFilhoEsquerda(pos);
        if (IndiceFilhoDireita(pos) != -1 && heap[IndiceFilhoDireita(pos)] < heap[IndiceMenorFilho])
            IndiceMenorFilho = IndiceFilhoDireita(pos);

        // Verificando se existe filho menor que o nó atual
        if (heap[IndiceMenorFilho] < heap[pos]) {
            int aux = heap[pos];
            heap[pos] = heap[IndiceMenorFilho];
            heap[IndiceMenorFilho] = aux;
            AjustarDescendo(heap, IndiceMenorFilho);
        }
    }
}


// Remove o menor elemento (raiz) do heap
int Remover(int *heap) {
    if (totalElementos == 0)
        return -1; // Indicação de erro, heap vazio
    int retorno = heap[0]; // Salva a raiz (primeiro elemento)
    heap[0] = heap[totalElementos - 1]; // Substitui a raiz pelo último elemento
    totalElementos--;                   // Reduz o número de elementos no heap
    AjustarDescendo(heap, 0);           // Ajusta o heap para restaurar a propriedade
    return retorno;                     // Retorna o valor removido
}


// Imprime todos os elementos do heap
void ImprimirHeap(int *heap) {
    if (totalElementos == 0) {
        printf("A heap está vazia.\n");
        return;
    }

    printf("Heap: ");
    for (int i = 0; i < totalElementos; i++) {
        printf("%d ", heap[i]); // Imprime os elementos
    }
    printf("\n");
}

// ---------------------------------------------- // ---------------

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    int heap[12]; // Vetor para armazenar os elementos do heap
    int escolha;  // Opção do usuário

    while (1) {
        printf("Digite uma opção para escolher o que deseja realizar:\n\n");
        printf("1 - Inserir um elemento x na heap\n");
        printf("2 - Remover um elemento\n");
        printf("3 - Imprimir a heap\n");
        printf("4 - Sair\n\n");

        scanf("%d", &escolha);

        switch (escolha) {
        case 1: {
            // Inserção de um elemento no heap
            printf("Qual valor deseja colocar? ");
            int x;
            scanf("%d", &x);
            Inserir(heap, x);
            printf("Elemento %d inserido com sucesso!!\n\n", x);
            break;
        }
        case 2: {
            // Remoção de um elemento do heap
            int removido = Remover(heap);
            if (removido == -1)
                printf("Heap vazia!! Não há elementos para remover.\n\n");
            else
                printf("Elemento %d removido com sucesso.\n\n", removido);
            break;
        }
        case 3: {
            // Impressão da heap
            ImprimirHeap(heap);
            break;
        }
        case 4:
            // Finaliza o programa
            printf("Saindo do programa\n");
            return 0;
        default:
            // Opção inválida
            printf("Opção inválida!! Tente novamente.\n\n");
        }
    }
}


