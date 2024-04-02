Desenvolver uma função recursiva que, dado
um número inteiro n, determine a quantidade
de divisores deste número.
nota = 9.5/10

#include <stdio.h>
#include <stdlib.h>
//protótipo da função

//main
int main ()
{
//declaração de variáveis
int n, n_divisores;
printf("Insira um numero inteiro:\t");
scanf("%i", &n);
//chamando a função
n_divisores = divisores(n, n);
printf("\nQuantidade de divisores:\t%i", n_divisores);
return 0;
}
//implementação da função
int divisores (int numero, int divisor)
{
//caso base
if (divisor == 1)
{
return 1;
}
if (numero % divisor == 0)
{
return divisores (numero, divisor - 1) + 1;
}
return divisores (numero, divisor - 1);
}
