Dada uma matriz MLINHAxCOLUNA, onde LINHA e
COLUNA são constantes, e uma coluna C,
desenvolver uma função que desloque todos os
elementos da coluna C para a última coluna da
matriz.
Consequentemente, as colunas C+1 à última
deverão serão deslocadas uma posição para a
esquerda.
nota = 10/10

#include <stdio.h>
#define LINHA 5
#define COLUNA 6
//protótipo da função
int deslocar_coluna(int matriz[LINHA][COLUNA], int coluna);
void exibir_matriz(int matriz[LINHA][COLUNA]);
//main
int main ()
{
//declaração de variáveis
int c;
int matriz[LINHA][COLUNA] = {{1, 5, 7, 1, 4, 6},

{6, 2, 1, 4, 7, 7},
{3, 6, 9, 7, 0, 1},
{2, 4 ,5, 7, 2, 4},
{2, 4, 8, 9, 1, 2 }};

//entrada
printf("Insira a coluna (sem ser a ultima) que deseja deslocar para o final:\t");
scanf("%i", &c);
deslocar_coluna (matriz, c);
exibir_matriz (matriz);

}
//implementação da função
int deslocar_coluna(int matriz[LINHA][COLUNA], int coluna)
{
//declaração de variáveis
int i, j, elemento;
if (coluna < 0 || coluna >= COLUNA)
{
return 0;
}
//deslocando
for (i = 0; i < LINHA; i++)
{
elemento = matriz[i][coluna];
for (j = coluna; j < COLUNA - 1; j++)

{
matriz[i][j] = matriz[i][j+1];
}
matriz[i][COLUNA - 1] = elemento;
}
return 1;
}
void exibir_matriz(int matriz[LINHA][COLUNA])
{
//declaração de variáveis
int i, j;
//exibindo
for (i = 0; i < LINHA; i++)
{
for (j = 0; j < COLUNA; j++)
{
printf("%i ", matriz[i][j]);
}
printf("\n");
}
}
