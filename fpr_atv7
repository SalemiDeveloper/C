Pede-se a implementação de uma função
recursiva que, dada uma lista do tipo TLista,
ordenada crescentemente, determine a
quantidade de valores distintos na lista.
nota = 9/10

#include <stdio.h>
#include <stdlib.h>
typedef struct No{
int valor; //no caso uma lista de inteiros
struct No *prox;
}TNo;
typedef TNo* TLista;
//protótipo das funções
int inserir (TLista* L, int numero);
void exibir (TLista L);
int contar_valores_distintos(TLista L);
//main
int main ()
{

//declaração de variáveis
TLista L1 = NULL; //lista inicialmente vazia
int quant_distintos;
inserir (&L1, 1);
inserir (&L1, 2);
inserir (&L1, 2);
inserir (&L1, 3);
inserir (&L1, 3);
inserir (&L1, 3);
inserir (&L1, 5);
quant_distintos = contar_valores_distintos(L1);
printf("Quantidade de valores distintos: %d\n", quant_distintos);
exibir(L1);
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
int contar_valores_distintos_recursivo(TLista L)
{

// caso base: lista vazia ou apenas um elemento. Nesse caso não há elementos distintos
if (L == NULL || L->prox == NULL)
{
return 0;
}
// caso recursivo: comparar o valor atual com o próximo valor da lista
if (L->valor != L->prox->valor)
{
// se forem diferentes, incrementar 1 e chamar a função recursivamente com o próximo
elemento
return 1 + contar_valores_distintos_recursivo(L->prox);
} else {
// se forem iguais, chamar a função recursivamente com o próximo elemento
return contar_valores_distintos_recursivo(L->prox);
}
}
int contar_valores_distintos(TLista L)
{
// chamando a função recursiva e retornando o resultado
return contar_valores_distintos_recursivo(L) + 1; // Adicionar 1 para contar o primeiro
valor também
}
