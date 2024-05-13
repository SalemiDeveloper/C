//importação de bibliotecas
#include <stdio.h>
#include <string.h>
//protótipos das funções
int questao2 (char nome_arqA[], char nome_arqB[]);
//main
void main ()
{
//declaração de variáveis
char nomeArqOriginal[20], nomeArqNovo[20];
int retorno;
//associando o arquivo "teste.txt" à variável 'nomeArqOriginal'
strcpy (nomeArqOriginal, "teste.txt");
//associando o arquivo "novo.txt" à variável 'nomeArqNovo'
strcpy (nomeArqNovo, "novo.txt");
//chamando a função e armazenando o retorno na variável 'retorno'
retorno = questao2 (nomeArqOriginal, nomeArqNovo);
//testando o retorno
if (retorno == 1)
{
printf ("\nO arquivo %s foi gerado com sucesso!", nomeArqNovo);
}
else
{
printf ("\nErro na geracao do arquivo %s.", nomeArqNovo);
}
}
//implementação das funções
int questao2 (char nome_arqA[], char nome_arqB[])
{
//declaração de variáveis
FILE *arqA, *arqB;
int i, j, numero;
//abrindo os arquivos
arqA = fopen (nome_arqA, "r"); // r - READ
arqB = fopen (nome_arqB, "w"); // w - WRITE
//verificando se houve erro na abertura dos arquivos
if ((!arqA) || (!arqB))
{

return 0;
} else {
//lendo os numeros do arqA e escrevendo os divisores em arB
while (fscanf (arqA, "%i", &numero) != EOF)
{
for (i=1; i<=numero; i++)
{
for (j=0; j<20; j++)
{
if (j == numero)
{
}
}
if (numero % i == 0)
{
fprintf(arqB, "%i ", i);
}

}

fprintf(arqB, "\n");
}
//fechando os arquivos
fclose (arqA);
fclose (arqB);
return 1;
}
}
