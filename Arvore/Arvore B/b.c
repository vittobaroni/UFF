// arvore b = parecida com avl, mas sem limite de filhos

// A raiz é uma folha ou tem no minimo dois filhos
// cada no tem no maximo b filhos e no minimo b/2 filhos
// todas as folhas estao no mesmo nivel


// o numero de chaves é igual ao numero de filhos -1
// as chaves sao posicionadas ordenadamente nos nos da arvore
// a ordem b da arvore "deve" ser impar

// busca na arvore b:
// se o no é folha, verifica se existe nesse no . Se sim, retorna o no atual
// se nao, retorna null, informando que a chave x nao existe na arvore


// se o no nao é folha, verifica se x está no no atual . Se sim, retorna o atual. Senao, verifica em qual filho f a busca
// deve ser recursviamente prosseguida . Retorna- se o resultado obtido na busca no filho f

