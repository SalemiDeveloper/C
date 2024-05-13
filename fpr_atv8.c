Fazer uma função que, dada uma Fila F, do tipo
TLista, e dois valores inteiros num1 e num2,
remova da fila todos os valores pertencentes ao
intervalo definido por num1 e num2, inclusive.
nota = 10/10

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
//definição de constantes
#define TRUE 1
#define FALSE 0
//definição de tipos
typedef struct No {
int valor;
struct No* prox;
} TNo;
typedef TNo* TLista;
//protótipos das funções
int enfilar (TLista *F, TLista *U, int numero);
int desenfilar (TLista *F, TLista *U, int *numero);
int primeiro (TLista F, int *p);
void remover_intervalo(TLista *F, int num1, int num2);
void exibir_fila(TLista F);

int menu ();
//main
void main ()
{
//declaração de variáveis
TLista F = NULL, U = NULL; //representando a pilha inicialmente vazia
int numero, op;
int num1, num2;
do
{
system ("CLS"); //limpar tela clrscr();
//exibindo o meu ao usuário
op = menu ();
//verificando a opção escolhida
switch (op)
{
//Enfilar
case 1: printf ("\nEntre com o valor a ser enfilado: ");
scanf ("%d", &numero);

//chamando a função
if (enfilar (&F, &U, numero) == TRUE)
{
printf ("\n\tInsercao realizada com sucesso na fila!\n");
}
else
{
printf ("\n\tERRO: insercao nao realizada na

fila!\n");

}
break;
//Desenfilar
case 2: //chamando a função
if (desenfilar (&F, &U, &numero) == TRUE)
{
printf ("\n\tO numero %d foi desenfilado\n", numero);
}
else
{
printf ("\n\tERRO: Fila vazia!");
}
break;

//Primeiro
case 3: //chamando a função
if (primeiro (F, &numero) == TRUE)
{
printf ("\n\tPrimeiro elemento da fila: %d\n", numero);
}
else
{
printf ("\n\tERRO: Fila vazia!");
}
break;
// Remover intervalo

case 4:

printf("\nEntre com o valor do primeiro numero do intervalo: ");
scanf("%d", &num1);
printf("Entre com o valor do segundo numero do intervalo: ");
scanf("%d", &num2);
// Chamar a função para remover o intervalo
remover_intervalo(&F, num1, num2);
printf("\nIntervalo removido da fila com sucesso!\n");
break;

// Exibir fila
case 5:
exibir_fila(F);
break;
//Saída
case 6: printf ("\n\nPrograma finalizado!");
break;
default: printf ("\n\nOpcao invalida! Tente novamente.");
}
system ("PAUSE");
}
while (op != 6);
}
//implementação das funções
//inserindo no início da lista
int enfilar (TLista *F, TLista *U, int numero)
{
//declaração de variáveis
TLista aux;
//Passo 1: alocar memória para o novo valor
aux = malloc (sizeof(TNo));
//verificar se a memória foi alocada
if (!aux)
{
return FALSE;
}
else
{
//Passo 2: inserir o novo valor no campo 'valor' da memória recém-alocada
aux->valor = numero;
//Passo 3: fazer o campo 'prox' do novo nó apontar para NULL
aux->prox = NULL;
//Passo 4: fazer o 'antigo último elemento' apontar para o novo nó
if (*U)
{
(*U)->prox = aux;
}
else

{
*F = aux;
}
//Passo 5: atualizar o ponteiro 'U'
*U = aux; //ou *U = (*U)->prox;
return TRUE;
}
}
int desenfilar (TLista *F, TLista *U, int *numero)
{
//declaração de variáveis
TLista aux;
//verificando se a fila está vazia
//if (*F == NULL)
if (!(*F))
{
return FALSE;
}
else
{
aux = *F;
*F = aux->prox; //ou *F = (*F)->prox;
//verificando se a fila se tornou nula. Ou seja,
//foi removido o seu último elemento
if (!(*F))
{
*U = NULL;
}
//salvando em 'numero' o valor que era o primeiro da fila
*numero = aux->valor;
free (aux);
return TRUE;
}
}
int primeiro (TLista F, int *p)
{
//verificando se a fila está vazia
if (!F)
{

return FALSE;
}
else
{
*p = F->valor;
return TRUE;
}
}
void remover_intervalo(TLista *F, int n1, int n2)
{
//declaração de variáveis
TLista atual = *F;
TLista anterior = NULL;
// Percorrer a fila
while (atual != NULL) {
//verificar se o valor atual está dentro do intervalo
if (atual->valor >= n1 && atual->valor <= n2) {
//remover o nó da fila
if (anterior == NULL) {
//caso seja o primeiro nó da fila
*F = atual->prox;
free(atual);
atual = *F;
} else {
//caso seja um nó no meio ou no final da fila
anterior->prox = atual->prox;
free(atual);
atual = anterior->prox;
}
} else {
//caso o valor atual não esteja no intervalo, avançar para o próximo nó
anterior = atual;
atual = atual->prox;
}
}
}
void exibir_fila(TLista F)
{
//verificando se a fila está vazia
if (F == NULL) {
printf("\nFila vazia.\n");
return;
}

printf("\nFila: ");
//percorrendo a fila
while (F != NULL) {
printf("%d ", F->valor);
F = F->prox;
}
printf("\n");
}

int menu ()
{
//declaração de variáveis
int opcao;
//exibindo o meu ao usuário
printf ("Menu de Operacoes:\n\n");
printf ("(1) Enfilar\n");
printf ("(2) Desenfilar\n");
printf ("(3) Primeiro\n");
printf ("(4) Remocao do Intervalo\n");
printf ("(5) Exibir\n");
printf ("(6) Sair\n\n");
//lendo a opção do usuário
printf ("Entre com a sua opcao: ");
scanf ("%d", &opcao);
//retornando a opção escolhida
return opcao;
}
