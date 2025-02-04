// backtracking --> tecnica de recursividade
// nas arvores, voce so trabalhava com dois caminhos possiveis . Em backtracking
// voce pode trabalhar com inumeros caminhos possiveis, de acordo ccom o problema

// muito comum questoes do tipos de combinação

// ex: buscar em uma arvore binaria

int busca(arvore*a, int x){
    if(a == NULL)
        return 0;
    else{
        if(a -> info == x){
            return 1;
        }
        else if(busca(a->esq, x) == 1)
            return 1;
        else
            return busca(a->dir, x);
    }
}

// backracking com vetor --> gerar combinações de {0,1} de 3 elementos
// inclui o vetor todo com Zero --> [0,0,0] --> volta recursivamente em cada posição do vetor
// e testar tambem o valor de 1

// uso da variavel pos, pra dizer onde que tem q preencher ( pos = 0);

void Combinacoes(int *vet, int pos){
    if(pos == 3){    // caso base de parada
        int i;
        for(i = 0; i<3; i++)    // vai imprimir cada combinacao
            printf("%d",vet[i]);
        printf("\n");   // pular linha apos cada combinacao
    }
    else{
        vet[pos] = 0;
        Combinacao(vet,pos + 1);    // agora, ele vai pegar a proxima pos e começar com pos = 1
        vet[pos] = 1;
        Combinacao(vet, pos + 1);   // mesma coisa, mas como vet[pos] == 1, ele vai pra 2
        
    }
}

// dica --> a condição de parada vai ser testar as caracteristicas da combinação
// na formula recursiva, precisa garantir que os elementos sejam inseridos em vet

void combinacoesN(int *vet, int pos, int n){    // combinacao com um tamanho generico
    if(pos == n){
        int i;
        for(i = 0; i < n; i++)
            printf("%d ", vet[pos]);
        printf("\n");
    }
    // para evitar usar vet[pos] de cada um, é mais simples usar um for
    else{
        for(i = 0; i <= 1; i++){    // aqui é garantir que os elementos vao estar aqui. Ex: {5,6,7}
            vet[pos] = i;   // altera o i = 0 por i = 5, indo ate 7
            combinacoesN(vet, pos + 1, n);
        }
    }
    // o resultado é o mesmo do que do primeiro caso
}

// imprimir as combinacoes de {0,1} de tamanho N, que tenham mais 0's que 1's

void comb(int *vet, int pos, int n){
    if(pos == n){
        int cont0 = 0;
        for(int i = 0; i < n; i++){
            if(vet[i] == 0)
                cont++;
        }
        if(cont0 > n/2){    // se o contador de zero for maior que a metade do vetor, entao significa que tem mais zeros do que uns
            for(i = 0; i< n; i++)   
                printf("%d",vet[i]);    // imprime todas as vezes que isso acontece
            printf("\n");
        }
    }
    else{
        for(i = 0; i <= 1; i++){
            vet[pos] = i;
            comb(vet, pos + 1, n);
        }
    }
}

// e se os numeros nao forem sequencia ?
// usar um vetor auxiliar, pra preencher os numeros que deseja
// ex: vetaux = {1,7,9}

void nao_sequencia(int *vet, int pos, int n, int *vetaux){
    int i;
    if(pos == n){
        for(i = 0; i < n; i++)
            printf("%d ",vet[i]);
        printf("\n");
    }
    else{
        for(i = 0; i <= 2; i++){
            vet[pos] = vetaux[i];
            nao_sequencia(vet, pos + 1, n, vetaux);
        }
    }
}


// {15,31,55,44} de tamanho n, todas as combninações cuja soma dos elementos é par

void combpar(int *vet, int pos, int n, int *vetaux){
    int i;
    if(pos == n){
        int soma = 0;
        for(i = 0; i < n; i++)
            soma +=vet[i];
        if(soma % 2 == 0){
            printf("\n");
            for(i = 0; i < n; i++)
                printf("\n",vet[i]);
        }
    }
    else{
        for(i = 0; i < 4; i++){
            vet[pos] = vetaux[i];
            combpar(vet, pos + 1, n, vetaux);
        }
    }
}


// questao das moedas --> moedas 1, 5, 10, 25, 50

void moedas(int *vet, int pos, int n, int*vetaux, int x){
    int i;
    if(pos == n){   // caso base
        int soma = 0;
        for(i = 0; i < n; i++){
            soma += (vet[i] *vetaux[i]);
        }
        if(soma == x){
            for(i = 0; i < n; i++)
                printf("%d ", vet[i]);
        }
    }
    else{   // recursao
        for(i = 0; i <= x; i++){
            vet[pos] = i;
            moedas(vet, pos + 1, n, vetaux, x);
        }
    }
}

// questao da prova :
// dadas as moedas 0,50, 0,10, 0,01 , e dois valores n e x
// verifique se é possivel ter n moedas cuja soma totalize x

void verifica(int *vet, int pos, int n, int x, int *moedas){
    int = 0;
    if(pos == 3){ // tres tipos de moedas
        int soma = 0;
        float valor = 0;
        for(i = 0; i < 3; i++){
            soma += vet[i];
            valor += (vet[i] * moedas[i]);
        }
        if(soma == n && valor == x){
            return 1;
        }
        return 0;
    }
    else{
        int max = (int) x/ moedas[i];
        for(i = 0; i <= max; i++){
            vet[pos] = i;
            if(verifica(vet, pos + 1, n, x, moedas) == 1)
                return 1;
        }
        return 0;
    }
}
