#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no *esq;
    struct no *dir;
    int valor;
}no;
// ao final do programa h� a fun��o main, com exemplos usando a entrada-padr�o definida para o exerc�cio
void inserirNo(no **raiz, int elemento) // fun��o para inserir elementos na �rvore
{
    if(*raiz == NULL){ //verifica se a raiz est� vazia
        no *aux = (no *)malloc(sizeof(no)); // aloca��o de uma vari�vel auxiliar
        aux->valor = elemento; // atribui o valor elemento para a vari�vel auxiliar
        aux->dir = aux->esq = NULL; // atribui NULL aos n�s direito e esquerdo
        *raiz = aux; // atribui o valor dda vari�vel auxiliar para a raiz
        printf ("Elemento %d foi inserido com sucesso.\n", elemento);
        return;
    }

    if(elemento < (*raiz)->valor){ // verifica se o valor do elemento a ser inserido � menor que o da raiz
        inserirNo(&(*raiz)->esq,elemento); // se a condi��o acima for verificada, adiciona o novo elemento a esquerda da raiz
        return;
    }

    if(elemento > (*raiz)->valor){ // verifica se o elemento a ser inserido � maior que a raiz
        inserirNo(&(*raiz)->dir,elemento); // se a condi��o acima for verificada, adiciona o novo elemento a esquerda da raiz
        return;
    }
    printf ("Elemento %d ja existe na arvore.\n", elemento);
}

no *DoisFilhos(no *root){ // fun��o que atua em conjunto com a fun��o de remo��o
        if(root==NULL) // verifica se a raiz � igual a NULL
            return NULL;
        else if(root->esq == NULL) // verifica se a esquerda da raiz � NULL
            return root;
        else
            return DoisFilhos(root->esq); // retorna o numero a esquerda da raiz
}

void removerNo (no **raiz, int elemento) // nessa fun��o, assume-se que o elemento a ser removido j� se encontra na �rvore
{
    if(elemento < (*raiz)->valor){ // busca o elemento dentre os elementos com valor menor do que o da raiz
        removerNo(&(*raiz)->esq,elemento);
    }
    else if(elemento > (*raiz)->valor){ // busca o elemento dentre os elementos com valor maior do que o da raiz
        removerNo(&(*raiz)->dir,elemento);
    }
    else if((*raiz)->esq!=NULL && (*raiz)->dir!=NULL){ // verifica se as sub-�rvores esquerda e direita s�o diferentes de NULL
        no *aux= NULL; // defini��o do n� auxiliar
        aux = DoisFilhos((*raiz)->dir); // chama a fun��o DoisFilhos
        (*raiz)->valor = aux->valor; // associa o valor da raiz a uma vari�vel auxiliar
        removerNo(&(*raiz)->dir, (*raiz)->valor); //
    }
    else {
        no *aux = (*raiz); // copia o valor do elemento para uma vari�vel auxiliar
        if((*raiz)->esq==NULL){ // verifica se a sub-�rvore esquerda � igual a NULL
            (*raiz) = (*raiz)->dir; // caso tal condi��o seja verificada, copia-se o valor do elemento para a sub-�rvore direita
        }
        else {
            *raiz = (*raiz)->esq; //caso tal condi��o n�o seja verificada, copia-se o valor do elemento para a sub-�rvore esquerda
        }
        free(aux); // desaloca��o da vari�vel aux, que � o n�
    }
}

void pesquisaEmOrdem(no *raiz){ // fun��o de pesquisa em ordem
    if(raiz != NULL){
    pesquisaEmOrdem(raiz->esq); // chama a sub-�rvore esquerda
    printf("%d ",raiz->valor); // imprime o n�
    pesquisaEmOrdem(raiz->dir); // chama a sub-�rvore direita
    }
}

void pesquisaPosOrdem(no *raiz){ // fun��o de pesquisa em p�s ordem
    if(raiz != NULL){
    pesquisaPosOrdem(raiz->esq); // chama a sub-�rvore esquerda
    pesquisaPosOrdem(raiz->dir); // chama a sub-�rvore direita
    printf("%d ",raiz->valor); // imprime o n�
    }
}

void pesquisaPreOrdem(no *raiz){ // fun��o de pesquisa em pr� ordem
    if(raiz != NULL){
    printf("%d ",raiz->valor); // imprime o n�
    pesquisaPreOrdem(raiz->esq); // chama a sub-�rvore esquerda
    pesquisaPreOrdem(raiz->dir); // chama a sub-�rvore direita
    }
}

void LabeledBracketing(no *raiz){ // fun��o de pesquisa em pr� ordem
    printf("[");
 	if(raiz!=NULL){ // verifica se a raiz � diferente de NULL
 		printf("%d", raiz->valor); // se a condi��o for constatada, imprime-se o valor da raiz
 		LabeledBracketing(raiz->esq); // chama-se a fun��o novamente para a sub-�rvore esquerda
 		LabeledBracketing(raiz->dir); // chama-se a fun��o novamente para a sub-�rvore direita
 	}
	printf("]");
}

int main(){
no *raiz = NULL;
    inserirNo(&raiz, 4); // inser��o do n�mero 4
    inserirNo(&raiz, 75); // inser��o do n�mero 75
    inserirNo(&raiz, 19); // inser��o do n�mero 19
    inserirNo(&raiz, 77); // inser��o do n�mero 77
    inserirNo(&raiz, 14); // inser��o do n�mero 14
    removerNo(&raiz, 4); // remo��o do n�mero 4
    pesquisaEmOrdem(raiz); // percurso da �rvore em ordem
    printf ("\n");
    pesquisaPreOrdem(raiz); // percurso da �rvore em pr� ordem
    printf ("\n");
    pesquisaPosOrdem(raiz); // percurso da �rvore em p�s ordem
    printf ("\n");
    LabeledBracketing(raiz); // impress�o da �rvore em labelled bracketing
}

