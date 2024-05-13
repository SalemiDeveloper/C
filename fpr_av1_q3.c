QUESTÃO 3

//importação de bibliotecas
#include <stdio.h>
#include <string.h>
//protótipos das funções
void questao3 (char str1[], char str2[], char* substr3, char* substr4);
//main
void main ()
{
//declaração de variáveis
char string1[20],
string2[20],
string3[20],
string4[20];
//inicializando as duas strings
strcpy (string1, "PROGRAMACAO");
strcpy (string2, "ALGORITMOS");
//chamando a função e armazenando os resultados em 'string3' e 'string4'
questao3 (string1, string2, string3, string4);
//exibindo as novas strings
printf ("\n\nstring3: %s\n", string3);
printf ("string4: %s\n", string4);
}
//implementação das funções
void questao3 (char str1[], char str2[], char* substr3, char* substr4)
{
//declaração de variáveis
int i, j, k, l;
//for para a primeira string
for (i = 0, k = 0, l = 0; str1[i] != '\0'; i++)
{
//for para comparar cada char da str1 com todos da str2
for (j =0 ; str2[j] != '\0'; j++)
{
//criando str3
if (str1[i] == str2[j])

{
substr3[k] = str1[i];
k++;
break;
}
}
//criando str4
if (str2[j] == '\0')
{
substr4[l] = str1[i];
l++;
}
}
//adicionando \0 no final das strings criadas
substr3[k] = '\0';
substr4[l] = '\0';
}
