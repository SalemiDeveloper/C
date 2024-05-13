2.5/2.5

#include <stdio.h>
#include <stdlib.h>
//declaração de constantes
#define FALSE 0
#define TRUE 1

typedef struct No {
int valor;
struct No* prox;
} TNo;
typedef TNo* TLista;
// Protótipo das funções
int inserir(TLista* L, int numero);
void exibir(TLista L);
void remover_maiores(TLista* L, int n);
// Main
int main() {
TLista L1 = NULL; // Lista inicialmente vazia
int n;
printf("Insira um numero inteiro: ");
scanf("%i", &n);
inserir(&L1, 1);
inserir(&L1, 5);
inserir(&L1, 10);
inserir(&L1, 15);
inserir(&L1, 20);
inserir(&L1, 25);
inserir(&L1, 30);
printf("Lista original: ");
exibir(L1);
remover_maiores(&L1, n);
printf("\nLista apos remocao: ");
exibir(L1);
return 0;
}
//implementações das funções

int inserir (TLista* L, int numero)
{
//declaração de variáveis
TLista aux;
//passo 1: alocar memória para o novo elemento
aux = (TLista) malloc (sizeof(TNo));
//testar se a memória foi alocada
if (aux == NULL)
{
return FALSE;
} else {
//passo 2: Armazenar na memória alocada o novo valor
aux->valor = numero;
//passo 3: Fazer o prox do novo nó apontar para o antigo primeiro elemento
aux->prox = *L;
//passo 4: Mandar L apontar para o novo nó
*L = aux;
//retornando sucesso
return TRUE;
}
}
void exibir (TLista L)
{
//declaração de variáveis
TLista aux;
//verificando se a lista está vazia
if (L == NULL)
{
printf("Lista vazia.\n");
} else {
printf("Lista: ");
//iniciando aux com o endereço do primeiro nó
aux = L; //ponteiro recebendo ponteiro
//percorrendo a lista até o seu final
while (aux) // while (aux != NULL)
{
//exibindo cada elemento da lista
printf("%i ", aux->valor);

//andando com 'aux' para o próximo nó
aux = aux->prox;
}
}
}

void remover_maiores(TLista* L, int n)
{
//verificando se a lista está vazia
if (*L == NULL)
{
return;
}
//verificando se o valor do nó atual é maior que o numero inserido pelo usuário
if ((*L)->valor > n)
{
TLista temp = *L;
*L = (*L)->prox;
free(temp);
remover_maiores(L, n);
} else {
remover_maiores(&((*L)->prox), n);
}
}
