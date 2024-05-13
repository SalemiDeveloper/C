2.5/2.5

//importação de biblioteca
#include <stdio.h>
#include <stdlib.h>
//protótipo da função
int inverter (int numero1, int invertido);
//main
int main ()
{
//declaração de variáveis
int n1, n2;
printf("Insira um numero inteiro:\t");
scanf("%i", &n1);
//chamando a função
n2 = inverter(n1, 0);
printf("O numero invertido e:\t%i", n2);

return 0;
}
int inverter (int numero1, int invertido)
{
if (numero1 == 0)
{
return invertido;
} else {
//declaração de variáveis
int ultimo_digito = numero1 % 10;
invertido = (invertido * 10) + ultimo_digito;
return inverter (numero1 / 10, invertido);
}
}
