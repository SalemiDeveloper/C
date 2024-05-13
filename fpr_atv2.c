Desenvolver uma função que, dada uma string
str, substitua uma substring s1 de str (definida
pelas posições inicial e final) por outra string,
s2. 
nota = 8/10

#include <stdio.h>
#include <string.h>
#define TAM 30
//protótipo da função
void substituir_string (char str[], int tamanho, int posicao_inicial, int posicao_final, char
subst[]);
//main
int main ()
{
//declaração de variáveis
char string[TAM];
int posInicial, posFinal, tam = 20, quant, i;
char substituta[tam];
fflush(stdin);
printf("Insira a string original:\t");
gets (string);
printf("\nEntre com a posicao inicial da alteracao:\t");
scanf("%i", &posInicial);
printf("\nEntre com a posicao final da alteracao:\t");
scanf("%i", &posFinal);
fflush(stdin);
printf("\nEntre com a alteracao:\t");
gets(substituta);
for (i=0; string[i] != '\0'; i++)
{
quant++;
}
tam = quant+1;
substituir_string (string, TAM, posInicial, posFinal, substituta);
}
//implementação da função
void substituir_string (char str[], int tamanho, int posicao_inicial, int posicao_final, char
subst[])
{
//declaração de variáveis
int tamanho_substituta = strlen (subst), tamanho_string = strlen (str),
tamanho_substring = posicao_final - posicao_inicial + 1;

int deslocamento = tamanho_substituta - tamanho_substring, novo_tamanho_str =
tamanho_string + deslocamento;
int i;
//deslocando os caracteres
if (deslocamento > 0)
{
for (i = novo_tamanho_str; i >= posicao_final + 1 + deslocamento; i--)
{
str[i] = str[i - deslocamento];
}
} else {
if (deslocamento < 0)
{
for (i = posicao_final + 1; i <= tamanho_string; i++)
{
str[i + deslocamento] = str[i];
}
}
}
//substitui a substring
for (i = 0; i < tamanho_substituta; i++)
{
str[posicao_inicial + i] = subst[i];
}
printf("\nString apos a substituicao:\t%s", str);
}
