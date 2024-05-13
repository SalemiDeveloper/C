AV1- QUESTÃO 1
//importação de bibliotecas
#include <stdio.h>
//definição de constantes
#define N 5
//protótipos das funções
int questao1 (int matriz[N][N]);
void exibirMatriz (int m[N][N]);
//main
void main ()
{
//declaração de variáveis
int resp;
int m1[N][N] = {{6, 3, 1, 2, 6},
{1, 3, 5, 4, 2},
{3, 4, 4, 2, 2},
{5, 9, 1, 9, 3},
{4, 0, 2, 1, 8}};
int m2[N][N] = {{1, 8, 5, 9, 4},
{2, 5, 4, 6, 5},
{4, 1, 2, 3, 6},
{4, 5, 5, 8, 7},
{4, 2, 5, 6, 9}};
//exibindo a matriz m1 antes da chamada à função
exibirMatriz (m1);
//chamando a função com m1 e atribuindo o retorno à variável 'resp'
resp = questao1 (m1);
//testando o valor retornado
if (resp == 1)
{
printf ("\n\nA matriz m1 atende ao especificado!");
}
else
{
printf ("\n\nA matriz m1 NAO atende ao especificado!");
}
//exibindo a matriz m2 antes da chamada à função

exibirMatriz (m2);
//chamando a função com m2 e atribuindo o retorno à variável 'resp'
resp = questao1 (m2);
//testando o valor retornado
if (resp == 1)
{
printf ("\n\nA matriz m2 atende ao especificado!");
}
else
{
printf ("\n\nA matriz m2 NAO atende ao especificado!");
}
}
//implementação das funções
int questao1 (int matriz[N][N])
{
//declaração de variáveis
int i, j;
int soma_diagonal = 0, soma_partebaixo = 0, soma_partecima = 0;
for (i=0; i<N; i++)
{
for (j=0; j<N; j++)
{
if (i == j)
{
soma_diagonal = soma_diagonal + matriz[i][j];
} else {
if (i > j)
{
soma_partebaixo = soma_partebaixo + matriz[i][j];
} else {
soma_partecima = soma_partecima + matriz[i][j];
}
}
}
}
//verificação dos resultados
if (soma_diagonal == soma_partebaixo && soma_diagonal == soma_partecima)
{
return 1;
} else {
return 0;
}

}
void exibirMatriz (int m[N][N])
{
//declaração de variáveis
int i, j;
printf ("Elementos da matriz:\n\n");
for (i=0;i<N;i++)
{
for (j=0;j<N;j++)
{
printf ("%3d ", m[i][j]);
}
printf ("\n");
}
printf ("\n\n");
}
