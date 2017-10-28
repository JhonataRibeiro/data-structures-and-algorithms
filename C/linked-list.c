/**
 * => Não há limitação de tamanho de memória
 * => Aproveira os recurso de ponteiros
 * => nó: composto por info e next(ponteiros)
 */

int insercao();
int remocao();

#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct reg {
    int conteudo;
    struct reg *prox;
};

/**
 * @description: recebe um nó de uma lista encadeada e imprime todos os nós subsequentes
 * @param: struct reg *le: recebe o nó de uma lista encadeada
 */ 
void imprime(struct reg *le){
   struct reg *p;
   for(p = le; p != NULL; p = p->prox)
       printf("%d\n", p->conteudo);
};

struct reg* busca(int x, struct reg *le){
   struct reg *p;
   p = le;
   while(p != NULL && p->conteudo != x)
       p = p->prox;
   return p;
}

/**
 * @description: O parâmetro *p recebe um ponteiro de uma lista. Se acessarmos *p, então estaremos acessando o endereço enviado.
 *               dessa forma, para conseguirmos acessar a estrutura do ponteiro recebido, utilizamos a notação com **p, também 
 *               chamada de ponteiro de ponteiro.
 */
void insereInicio(int x, struct reg **p){
    /**
     * @description: declara um ponteiro para um novo registro
     */
   struct reg *nova;

   /**
    * @description: malloc aloca um bloco bytes na memória ram de forma consecutiva e retorna o endereço do bloco para 
    *               o ponteiro nova declarado acima.
    */
   nova = malloc(sizeof(struct reg));

   /**
    *@description: acessa a variável que representa o conteúdo do registro nova e atrubui o valor passado na função
    *               a esta variável. Ela representará o conteúdo desse nó.
    */
   nova -> conteudo = x;

   /**
    * @description: acessa a variável prox que representa o próximo elemento da lista encadeada que receberá
    *               o endereço do novo nó, como este é o último nó, o próx dele é ele mesmo. 
    */ 
   nova -> prox = *p;
   *p = nova;
}

void insereFinal(int x, struct reg **p){
    struct reg *p_Novo;
    struct reg *e_atual;
    p_Novo = (struct reg *) malloc(sizeof(struct reg));
    p_Novo -> conteudo = x;
    p_Novo -> prox = NULL;

    if(*p == NULL) //Lista Vazia
       *p = p_Novo;
   else{
       e_atual = *p;
       while (e_atual->prox != NULL){
           e_atual = e_atual->prox;
       }
       e_atual->prox = p_Novo;
   }
}

void removeInicio(struct reg **p){
   struct reg *lixo;
   lixo = *p;
   int valor = lixo->conteudo;
   *p = (*p)->prox;
   free(lixo);
   return valor;
}

void removeFinal(struct reg **p){
   int valor = 0;
   if(*p == NULL)
       printf("\nA lista já está vazia");
   else{
       struct reg *p_atual, *p_anterior;
       p_atual = *p;
       while(p_atual->prox != NULL){
           p_anterior = p_atual;
           p_atual = p_atual->prox;
       }
       p_anterior->prox = NULL;
       valor = p_atual->conteudo;
       free(p_atual);
   }
   return valor;
}

int main(){
   struct reg *lista = NULL;
   /**
    * @description: Nesta função está sendo passado o endereço de um registro chamado lista;
    */ 
   insereInicio(5,&lista);
   insereInicio(6,&lista);
   insereInicio(7,&lista);
   imprime(lista);
   insereInicio(8,&lista);
   removeInicio(&lista);
   imprime(lista);

   return 0;
}

