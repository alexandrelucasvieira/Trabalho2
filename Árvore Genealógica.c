#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
 O programa nos pede para fazer uma arvore binaria simulando a arvore genealogica.
 A raiz da arvore seria uma suposta pessoa analisada, tendo assim seus pais avos e assim por diante.
 Como essa arvore é de filhos unicos ( enunciado ) e de elementos completos ( cada filho necessita de pais,
portanto ela é completa e simetrica ) podemos utilizar um metodo mais simples.
 O metodo escolhido sera utilizando array e alocação estatica.
*/



// ******** IMPORTANTE: O programa assume que voce nao insira dados falsos/inexistentes. **********



// O programa contara com uma entrada padrão das pessoas, e em um regime de 3 gerações.
// Optei por 5 gerações pois 4 seria muito pouco ( 14 elementos ) e 4 demais...
//***********OBS: O algoritmo eh generalizado, basta substituir o valor de n para as geracoes.
// A entrada padrão dos nomes é apenas para facilitar a entrada, ao inves de digitar 14 nommes.

/* Esquematica dos numeros:

                                          F0
                                         /  \
                                       P1    M2
                                      / \    / \
                                    P3  M4  P5  M6
                                    ...
*/

int main(void){

//declaração de variaveis
int aux, antepacado, antepacado2, para;
int g, geracao = 0, comp1, comp2, z=0;
int vetcomp[50];
double contador=0, pessoas=0;
double i=0;

double n=5; // NUMERO DE GERACOES

printf("\n Lista de pessoas por geracao: \n");

char vetor[50]; //inicia o vetor que vai alocar os parentes

// Inicio do algoritimo que vai definir os numeros e gerações dos familiares

// Também insere a lista de membros por geração

for (i=0;i<n;i++){

    contador = pow(2,i);
    //printf("\n%f\n", contador);
    aux = contador + pessoas;
    for(g=pessoas; g < aux ; g++){
            if (g == 0){vetor[g] = 'F'; }
            if ( g % 2 != 0){ vetor[g] = 'P'; }
            if (g % 2 == 0 && g != 0 ){ vetor[g] = 'M';}
            printf("\nNome: %c%d \ Geracao: %d \ Numero: %d\n ", vetor[g], g, geracao, g);
            vetcomp[g] = geracao;
    }
    geracao++;
    pessoas = aux;
    contador = 0;
}

// Parte do programa que vai verificar o parentesco entre 2 individuos

printf("\n Digite o numero das pessoas que deseja verificar o parentesco: ");
printf("\nPessoa 1: ");
scanf("%d", &comp1);
printf("\nPessoa 2: ");
scanf("%d", &comp2);

int parentesco;
// vetcomp[] esta alocando as geraçoes

parentesco = abs( vetcomp[comp1] - vetcomp[comp2]);

printf("\n O grau de parentesco eh: %d\n", parentesco);

aux = 0;

// Algoritmo que vai imprimir os antepaçados de um dado individuo.
// O numero de geracoes a ser consultado tambem sera impresso.

printf("\n Digite o numero do familiar que deseja imprimir os antepacados: ");
scanf("%d", &antepacado);
printf("\n Digite quantas geracoes que deseja consultar: ");
scanf("%d", &para);

if ( vetcomp[antepacado] == 0){printf(" \nTodos os membros da lista sao antepacados.\n");}

int armazena_antepassado[50];

printf(" \n Os antepassados sao: \n");

while ( aux < para && antepacado != 0 ){

    antepacado = (antepacado * 2);
    antepacado2 = antepacado;

    for (i=0; i<pow(2,aux+1); i++){

            armazena_antepassado[z]=antepacado2 + 1;
            if ( armazena_antepassado[z] % 2 != 0 ){ printf("P%d\n", armazena_antepassado[z]); }
            if ( armazena_antepassado[z] % 2 == 0 ){ printf("M%d\n", armazena_antepassado[z]); }
            z++;
            antepacado2++;

    }
    aux++;
    i=0;
    antepacado++;

}

system ("pause");
return 0;
}
