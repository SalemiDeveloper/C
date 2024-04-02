Implementar uma função que, dada uma lista L1
do tipo TLista, crie uma nova lista, L2 (de tipo
diferente de TLista), contendo, em cada nó, um
elemento de L1 e a quantidade de vezes que
este aparece em L1.
Exemplo:
Elementos de L1: 1 4 5 7 4 3 2 5 4 7 1 2
A lista L2 conterá os seguintes nós:
• Um nó contendo o valor 1 e a
quantidade 2 (pois o número 1
aparece 2 vezes em L1);
• Um nó contendo o valor 4 e a
quantidade 3;
• Um nó contendo o valor 5 e a
quantidade 2;
• Um nó contendo o valor 7 e a
quantidade 2;
• Um nó contendo o valor 3 e a
quantidade 1;
• Um nó contendo o valor 2 e a
quantidade 2.
Observação: não há ordem definida para os nós
de L2. Ou seja, o primeiro elemento da lista L1
não precisa estar na primeira posição de L2.
nota = 7/10

#include <stdio.h>
#include <stdlib.h>
//declaração de constantes
#define FALSE 0
#define TRUE 1
typedef struct No_quant{
int valor;
int quant;
struct No_quant *prox;
}TNo_quant;
typedef TNo_quant *TLista_quant;
typedef struct No{
int valor; //no caso uma lista de inteiros
struct No *prox;
}TNo;
typedef TNo* TLista;
//protótipo das funções
int inserir (TLista* L, int numero);
void exibir (TLista L);
void criar_lista_quantidade (TLista L1, TLista_quant *L2);
//main
int main()
{
//declaração de variáveis
TLista L1 = NULL; //lista inicialmente vazia
TLista_quant L2 = NULL; // lista L2 inicialmente vazia
inserir (&L1, 2);
inserir (&L1, 1);
inserir (&L1, 7);
inserir (&L1, 4);
inserir (&L1, 5);
inserir (&L1, 2);
inserir (&L1, 3);
inserir (&L1, 4);
inserir (&L1, 7);
inserir (&L1, 5);
inserir (&L1, 4);
inserir (&L1, 1);

exibir(L1);
criar_lista_quantidade(L1, &L2);
// exibir a lista L2
TLista_quant aux = L2;
while (aux != NULL)
{
printf("\nValor: %d Quantidade: %d", aux->valor, aux->quant);
aux = aux->prox;
}

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
void criar_lista_quantidade (TLista L1, TLista_quant *L2)
{
// Verificando se a lista L1 está vazia
if (L1 == NULL)
{
// L1 vazia, não faz nada
printf("\nLista vazia.");
}
else
{
// Declaração de variáveis
TLista_quant lista_temp = NULL;
TLista_quant temp = lista_temp;
TLista aux = L1;
*L2 = NULL;
// Percorrendo L1
while (aux != NULL)
{
// Reinicializando o ponteiro temp
temp = lista_temp;

// Verificando se o elemento já está na lista temporária
while (temp != NULL)
{
if (temp->valor == aux->valor)
{
temp->quant++;
break;
}
temp = temp->prox;
}
// Se o elemento não foi encontrado na lista temporária, cria um novo nó
if (temp == NULL)
{
// Alocando memória para o novo nó
TLista_quant novo = (TLista_quant)malloc(sizeof(TNo_quant));
novo->valor = aux->valor;
novo->quant = 1;
novo->prox = lista_temp;
lista_temp = novo;
}
aux = aux->prox;
}
// Copiando os elementos da lista temporária para a lista L2
while (lista_temp != NULL)
{
// Criando um novo nó para L2
TLista_quant novo = (TLista_quant)malloc(sizeof(TNo_quant));
novo->valor = lista_temp->valor;
novo->quant = lista_temp->quant;
novo->prox = *L2;
*L2 = novo;
lista_temp = lista_temp->prox;
}
// Liberando a memória da lista temporária
temp = lista_temp;
while (temp != NULL)
{
TLista_quant proximo = temp->prox;
free(temp);
temp = proximo;
}

}
}
