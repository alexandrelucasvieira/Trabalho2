#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no *esq;
    struct no *dir;
    int valor;
}no;
// ao final do programa há a função main, com exemplos usando a entrada-padrão definida para o exercício
void inserirNo(no **raiz, int elemento) // função para inserir elementos na árvore
{
    if(*raiz == NULL){ //verifica se a raiz está vazia
        no *aux = (no *)malloc(sizeof(no)); // alocação de uma variável auxiliar
        aux->valor = elemento; // atribui o valor elemento para a variável auxiliar
        aux->dir = aux->esq = NULL; // atribui NULL aos nós direito e esquerdo
        *raiz = aux; // atribui o valor dda variável auxiliar para a raiz
        printf ("Elemento %d foi inserido com sucesso.\n", elemento);
        return;
    }

    if(elemento < (*raiz)->valor){ // verifica se o valor do elemento a ser inserido é menor que o da raiz
        inserirNo(&(*raiz)->esq,elemento); // se a condição acima for verificada, adiciona o novo elemento a esquerda da raiz
        return;
    }

    if(elemento > (*raiz)->valor){ // verifica se o elemento a ser inserido é maior que a raiz
        inserirNo(&(*raiz)->dir,elemento); // se a condição acima for verificada, adiciona o novo elemento a esquerda da raiz
        return;
    }
    printf ("Elemento %d ja existe na arvore.\n", elemento);
}

no *DoisFilhos(no *root){ // função que atua em conjunto com a função de remoção
        if(root==NULL) // verifica se a raiz é igual a NULL
            return NULL;
        else if(root->esq == NULL) // verifica se a esquerda da raiz é NULL
            return root;
        else
            return DoisFilhos(root->esq); // retorna o numero a esquerda da raiz
}

void removerNo (no **raiz, int elemento) // nessa função, assume-se que o elemento a ser removido já se encontra na árvore
{
    if(elemento < (*raiz)->valor){ // busca o elemento dentre os elementos com valor menor do que o da raiz
        removerNo(&(*raiz)->esq,elemento);
    }
    else if(elemento > (*raiz)->valor){ // busca o elemento dentre os elementos com valor maior do que o da raiz
        removerNo(&(*raiz)->dir,elemento);
    }
    else if((*raiz)->esq!=NULL && (*raiz)->dir!=NULL){ // verifica se as sub-árvores esquerda e direita são diferentes de NULL
        no *aux= NULL; // definição do nó auxiliar
        aux = DoisFilhos((*raiz)->dir); // chama a função DoisFilhos
        (*raiz)->valor = aux->valor; // associa o valor da raiz a uma variável auxiliar
        removerNo(&(*raiz)->dir, (*raiz)->valor); //
    }
    else {
        no *aux = (*raiz); // copia o valor do elemento para uma variável auxiliar
        if((*raiz)->esq==NULL){ // verifica se a sub-árvore esquerda é igual a NULL
            (*raiz) = (*raiz)->dir; // caso tal condição seja verificada, copia-se o valor do elemento para a sub-árvore direita
        }
        else {
            *raiz = (*raiz)->esq; //caso tal condição não seja verificada, copia-se o valor do elemento para a sub-árvore esquerda
        }
        free(aux); // desalocação da variável aux, que é o nó
    }
}

void pesquisaEmOrdem(no *raiz){ // função de pesquisa em ordem
    if(raiz != NULL){
    pesquisaEmOrdem(raiz->esq); // chama a sub-árvore esquerda
    printf("%d ",raiz->valor); // imprime o nó
    pesquisaEmOrdem(raiz->dir); // chama a sub-árvore direita
    }
}

void pesquisaPosOrdem(no *raiz){ // função de pesquisa em pós ordem
    if(raiz != NULL){
    pesquisaPosOrdem(raiz->esq); // chama a sub-árvore esquerda
    pesquisaPosOrdem(raiz->dir); // chama a sub-árvore direita
    printf("%d ",raiz->valor); // imprime o nó
    }
}

void pesquisaPreOrdem(no *raiz){ // função de pesquisa em pré ordem
    if(raiz != NULL){
    printf("%d ",raiz->valor); // imprime o nó
    pesquisaPreOrdem(raiz->esq); // chama a sub-árvore esquerda
    pesquisaPreOrdem(raiz->dir); // chama a sub-árvore direita
    }
}

void LabeledBracketing(no *raiz){ // função de pesquisa em pré ordem
    printf("[");
 	if(raiz!=NULL){ // verifica se a raiz é diferente de NULL
 		printf("%d", raiz->valor); // se a condição for constatada, imprime-se o valor da raiz
 		LabeledBracketing(raiz->esq); // chama-se a função novamente para a sub-àrvore esquerda
 		LabeledBracketing(raiz->dir); // chama-se a função novamente para a sub-àrvore direita
 	}
	printf("]");
}

int main(){
no *raiz = NULL;
    inserirNo(&raiz, 4); // inserção do número 4
    inserirNo(&raiz, 75); // inserção do número 75
    inserirNo(&raiz, 19); // inserção do número 19
    inserirNo(&raiz, 77); // inserção do número 77
    inserirNo(&raiz, 14); // inserção do número 14
    removerNo(&raiz, 4); // remoção do número 4
    pesquisaEmOrdem(raiz); // percurso da árvore em ordem
    printf ("\n");
    pesquisaPreOrdem(raiz); // percurso da árvore em pré ordem
    printf ("\n");
    pesquisaPosOrdem(raiz); // percurso da árvore em pós ordem
    printf ("\n");
    LabeledBracketing(raiz); // impressão da árvore em labelled bracketing
}

