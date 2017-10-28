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
    inserir(&arvore_A, 5);
    inserir(&arvore_A, 4);
    inserir(&arvore_A, 3);
    inserir(&arvore_A, 10);
    inserir(&arvore_A, 9);
    inserir(&arvore_A, 12);
    inserir(&arvore_A, 14);
    inserir(&arvore_A, 17);
    inserir(&arvore_A, 20);
    exibirEmOrdem(arvore_A);
    exit(1);
}

/**
 * A função criarArvore, recebe como parâmetro um ponteiro para o ponteiro do nosso No criado acima. 
 * Por que um ponteiro para um ponteiro? Porque eu preciso de um ponteiro para manipular o ponteiro que aponta para o
 * No criado  
 */
void criarArvore(No **pRaiz)
{
    printf("Endereço da Raiz ==>  %d", *pRaiz);
    *pRaiz = NULL;
    printf("\n Atribui NULL ao endereço da Raiz ==> %d", *pRaiz);
}

void inserir(No **pRaiz, int numero)
{
    /**
     * Se pRaiz for null, minha arvore está vazia
     */
    printf("\n  É null? %d", *pRaiz);
    if (*pRaiz == NULL)
    {
        printf("\n É nulo, inserir valor %d", numero);
        *pRaiz = (No *)malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero;
    }
    else
    {
        if (numero < (*pRaiz)->numero)
        {
            printf("\n Inserir %d a esquerda", numero);
            inserir(&(*pRaiz)->esquerda, numero);
        }
        else
        {
            printf("\n Inserir %d a direita", numero);
            inserir(&(*pRaiz)->direita, numero);
        }
    }
}

void exibirEmOrdem(No *pRaiz){  
    printf("%d\n",pRaiz != NULL);  
    if(pRaiz != NULL){
        printf("1\n");
        exibirEmOrdem(pRaiz->esquerda);
        printf("2\n");
        printf("\n%d", pRaiz -> numero);
        printf("3\n");
        exibirEmOrdem(pRaiz->direita);
    }
}
