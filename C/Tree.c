/**
 * Implementação de um TAD do tipo árvore
 */

#include <stdio.h>
#include <stdlib.h>

struct No
{
    int numero;
    struct No *esquerda;
    struct No *direita;
};

typedef struct No No;

int main()
{
    No *arvore_A = NULL;
    criarArvore(&arvore_A);
    inserir(&arvore_A, 10);
    inserir(&arvore_A, 8);
    inserir(&arvore_A, 14);
    inserir(&arvore_A, 15);
    inserir(&arvore_A, 11);
    inserir(&arvore_A, 7);
    inserir(&arvore_A, 9);
    inserir(&arvore_A, 6);
    printf("Em ordem: ");
    exibirEmOrdem(arvore_A);
    printf("Em pré ordem: ");
    exibirEmPreOrdem(arvore_A);
    printf("Em pos ordem: ");
    exibirEmPosOrdem(arvore_A);
    exit(1);
}

/**
 * A função criarArvore, recebe como parâmetro um ponteiro para o ponteiro do nosso No criado acima. 
 * Por que um ponteiro para um ponteiro? Porque eu preciso de um ponteiro para manipular o ponteiro que aponta para o
 * No criado  
 */
void criarArvore(No **pRaiz)
{
    *pRaiz = NULL;
}

void inserir(No **pRaiz, int numero)
{
    /**
     * Se pRaiz for null, minha arvore está vazia
     */
    if (*pRaiz == NULL)
    {
        *pRaiz = (No *)malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero;
    }
    else
    {
        if (numero < (*pRaiz)->numero)
        {
            inserir(&(*pRaiz)->esquerda, numero);
        }
        else
        {
            inserir(&(*pRaiz)->direita, numero);
        }
    }
}

void exibirEmOrdem(No *pRaiz){  
    if(pRaiz != NULL){
        exibirEmOrdem(pRaiz->esquerda);
        printf("\n%d\n", pRaiz -> numero);
        exibirEmOrdem(pRaiz->direita);
    }
}

void exibirEmPreOrdem(No *pRaiz){
    if(pRaiz != NULL){
        printf("\n%d\n", pRaiz -> numero);
        exibirEmPreOrdem(pRaiz->esquerda);
        exibirEmPreOrdem(pRaiz->direita);
    }
}

void exibirEmPosOrdem(No *pRaiz){
    if(pRaiz != NULL){
        exibirEmPosOrdem(pRaiz->esquerda);
        exibirEmPosOrdem(pRaiz->direita);
        printf("\n%d\n", pRaiz -> numero);
    }
}
