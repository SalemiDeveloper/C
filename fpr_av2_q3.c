2.2/2.5

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
// Main
int main()
{
TLista L1 = NULL; // Lista inicialmente vazia
int n, res;
printf("Insira um numero inteiro: ");
scanf("%i", &n);
inserir(&L1, 30);
inserir(&L1, 26);
inserir(&L1, 20);
inserir(&L1, 15);
inserir(&L1, 10);
inserir(&L1, 5);
inserir(&L1, 1);
exibir(L1);
res = verificar_ordem(L1, n);
printf("\n%i", res);

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

int verificar_ordem(TLista L, int n)
{
//declaração de variáveis
TLista aux = L;
int menor_igual = TRUE;
int maior = FALSE;
//percorrendo a lista
while (aux != NULL)
{
//verificando se algum valor menor ou igual será encontrado após um valor

maior que n
if (aux->valor <= n && maior)
{
menor_igual = FALSE;
//se achou, sai do loop
break;
} else {
//verificando se um valor maior que n foi encontrado
if (aux->valor > n)
{
maior = TRUE;
}

}
//move o ponteiro auxiliar para o próximo nó da lista
aux = aux->prox;
}
if (menor_igual || !maior)
{
return TRUE;
} else {
return FALSE;
}
}
