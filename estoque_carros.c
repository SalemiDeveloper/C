#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 15
//#define ESTOQUE 2

typedef struct {
	int ano_modelo;
	int ano_fabricacao;
	
} Tano;

typedef struct {
	char placa[8];
	char modelo[TAM];
	char marca[TAM];
	char cor[TAM];
	float km;
	Tano modelo_fab;
	float valor;
	char tipo[TAM];
	
} TDados;

//protótipo da função
void leitura_dados (TDados carro[], int estoque);
void exibir_dados (TDados carro[], int estoque);
void buscar_carro (TDados carro[], int estoque, char mbusca[], int tamanho, int ano_fabricado, int a1, int a2, float preco);
void reajustando_valor (TDados carro[], int estoque);
void retirando_veiculo (TDados carro[], int estoque);

//main
int main() 
{
	//declaração de variáveis
	int quant_estoque = 1, ano_fabricacao_busca, a1, a2, acao, i;
	float valor_busca;
	char modelo_busca[TAM];
	TDados carro[quant_estoque];
	
	//inserindo quantidade de carros do estoque
	printf("Insira a quantidade de carros no estoque:\t");
	scanf("%i", &quant_estoque);
	
	//chamando a função que vai LER OS DADOS
	leitura_dados (carro, quant_estoque);
	
	for (i=0; acao != 4; i++)
	{
		printf("\n\nInsira um numero para a acao desejada:");
		printf("\n1 - Exibir os dados dos carros do estoque.");
		printf("\n2 - Buscar um carro dado o seu modelo, intervalos entre anos de fabricacao e valor maximo (EM REAIS)");
		printf("\n3 - Retirar um veiculo do estoque dado a sua placa.");
		printf("\n4 - Encerrar programa.\n\n");
		scanf("%i", &acao);
		
		if (acao == 1)
		{
			//FUNÇÃO PARA TESTAR A EXIBIÇÃO
			exibir_dados (carro, quant_estoque);
		} else {
			if (acao == 2)
			{
				fflush (stdin);
				printf("\nInsira o modelo de carro que busca:");
				gets (modelo_busca);
				
				printf("\nInsira um intervalo de tempo para o ano de fabricacao:\t");
				scanf("%i %i", &a1, &a2);
				
				printf("\nAte quanto (EM REAIS) o valor do carro:\t");
				scanf("%f", &valor_busca);
				
				buscar_carro(carro, quant_estoque, modelo_busca, TAM, ano_fabricacao_busca, a1, a2, valor_busca);
				
			} else {
				if (acao == 3)
				{
					retirando_veiculo (carro, quant_estoque);
					
				} else {
					if (acao == 4)
					{
						printf("Programa ENCERRADO");
					} else {
						printf("Numero invalido");
					}
				}
			}
		}
	}

}


//lendo os dados
void leitura_dados (TDados carro[], int estoque)
{
	//declaração de variáveis
	int i;
	
	for (i=0; i<estoque; i++)
	{
		fflush (stdin);
		printf("\nInsira a placa do carro:\t");
		gets (carro[i].placa);
		
		fflush (stdin);
		printf("\nInsira o modelo do carro:\t");
		gets (carro[i].modelo);
		
		fflush (stdin);
		printf("\nInsira a marca do carro:\t");
		gets (carro[i].marca);
		
		fflush (stdin);
		printf("\nInsira a cor do carro:\t");
		gets (carro[i].cor);
		
		printf("\nInsira a quilometragem:\t");
		scanf("%f", &carro[i].km);
		
		printf("\nInsira o ano modelo do carro:\t");
			scanf("%i", &carro[i].modelo_fab.ano_modelo);
			
		printf("\nInsira o ano de fabricacao do carro:\t");
			scanf("%i", &carro[i].modelo_fab.ano_fabricacao);
		
		
		printf("\nInsira (em REAIS) o valor do carro:\t");
		scanf("%f", &carro[i].valor);
		
		if (carro[i].km == 0)
		{
			strcpy (carro[i].tipo, "0km");
		} else {
			strcpy (carro[i].tipo, "USADO");
		}
	}
}

void exibir_dados (TDados carro[], int estoque)
{
	//declaração de variáveis
	int i;
	
	for (i=0; i<estoque; i++)
	{
		printf("\nCarro %i:", i+1);
		printf("\nPlaca:\t%s", carro[i].placa);
		printf("\nModelo:\t%s", carro[i].modelo);
		printf("\nMarca:\t%s", carro[i].marca);
		printf("\nCor:\t%s", carro[i].cor);
		printf("\nQuilometragem:\t%f", carro[i].km);
		printf("\nAno Modelo do carro:\t%i", carro[i].modelo_fab.ano_modelo);
		printf("\nAno de Fabricação do carro:\t%i", carro[i].modelo_fab.ano_fabricacao);
		printf("\nValor (EM REAIS) do carro:\t%f", carro[i].valor);
		printf("\nTipo do carro:\t%s", carro[i].tipo);
	}
}

void buscar_carro (TDados carro[], int estoque, char mbusca[], int tamanho, int ano_fabricado, int a1, int a2, float preco)
{
	//declaração de variáveis
	int i, j = 0;
	
	for (i=0; i<estoque; i++)
	{
		if (strcasecmp (carro[i].modelo, mbusca) == 0 && carro[i].modelo_fab.ano_fabricacao >= a1 && carro[i].modelo_fab.ano_fabricacao <= a2 && carro[i].valor <= preco)
		{
			printf("\nCarro %i:", i+1);
			printf("\nPlaca:\t%s", carro[i].placa);
			printf("\nModelo:\t%s", carro[i].modelo);
			printf("\nMarca:\t%s", carro[i].marca);
			printf("\nCor:\t%s", carro[i].cor);
			printf("\nQuilometragem:\t%f", carro[i].km);
			printf("\nAno Modelo do carro:\t%i", carro[i].modelo_fab.ano_modelo);
			printf("\nAno de Fabricacao do carro:\t%i", carro[i].modelo_fab.ano_fabricacao);
			printf("\nValor (EM REAIS) do carro:\t%f", carro[i].valor);
			printf("\nTipo do carro:\t%s\n", carro[i].tipo);
			
			mbusca[j] = i;
			j++;
		}
	}
}

void reajustando_valor (TDados carro[], int estoque)
{
	int i;
	
	for (i=0; i<estoque; i++)
	{
		if (strcasecmp (carro[i].tipo, "0km") == 0)
		{
			carro[i].valor = carro[i].valor + (carro[i].valor * (2.5/100));
		}
	}
}

void retirando_veiculo (TDados carro[], int estoque)
{
	//declaração de variáveis
	int i, j;
	char placa[8];
	
	fflush (stdin);
	printf("Insira a placa do veiculo que deseja retirar do estoque:\t");
	gets (placa);
	
	for (i=0; i<estoque; i++)
	{
		if (strcasecmp (carro[i].placa, placa) == 0)
		{
			printf("\nVeiculo encontrado no estoque.");
			
			for (j=i; j<estoque - 1; j++)
			{
				carro[j] = carro[j + 1];
			}
			
			estoque--;
			
			printf("\nVeiculo removido do estoque!");
			break;
		} else {
			printf("\nVeiculo NAO ENCONTRADO no estoque.");
		}
	}
}
