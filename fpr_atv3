Uma Clínica Veterinária mantém um vetor de
structs, do qual cada posição armazena as
seguintes informações: código do cadastro,
nome do pet, nome do tutor, e-mail de contato,
data da última vacina.
Desenvolver uma função que, dado um vetor
com esta estrutura, gere um arquivo texto com
os dados dos pets com vacina vencida (mais de
um ano da última).
Cada linha do arquivo terá a seguinte sintaxe:

email|mensagem

E a mensagem terá o formato apresentado
abaixo:
Prezado <nome_tutor>, a vacina do pet
<nome_pet> venceu no dia dd/mm/aaaa.
Podemos agendar a nova dose?
nota = 9/10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 30
#define TAM_EMAIL 100
typedef struct {
int dia;
int mes;
int ano;
} TData;
typedef struct {
char codigo[TAM];
char nome_pet[TAM];
char nome_tutor[TAM];
char email[TAM_EMAIL];
TData ult_vacina;
} TClinica;
// protótipo da função
int gerar_arquivo(TClinica vet[], int tam, int tam_email, TData d_atual);
// main
int main()
{
//declaração de variáveis
TData atual;
time_t currentTime;
struct tm *localTime;
//data do sistema
currentTime = time(NULL);
localTime = localtime(&currentTime);
//atribuindo as informações de data atual
atual.dia = localTime->tm_mday;
atual.mes = localTime->tm_mon + 1;
atual.ano = localTime->tm_year + 1900;
TClinica vetor[2] = {
{"COD001", "Bigu", "Pedro", "pedro.2210478300021@faeterj-rio.edu.br", {22, 6, 2022}},
{"COD002", "Lola", "Fulano", "fulano.exemplo20@gmail.com", {6, 10, 2021}}
};

int resultado;
resultado = gerar_arquivo(vetor, 2, TAM_EMAIL, atual);
if (resultado == 0)
{
printf("Erro na geracao do arquivo");
} else {
printf("Arquivo gerado com sucesso.");
}
return 0;
}
// implementação da função
int gerar_arquivo(TClinica vet[], int tam, int tam_email, TData d_atual) {
// declaração de variáveis
FILE *arq;
int i, dif_anos;
// abrindo arquivo
arq = fopen("vacinas_vencidas.txt", "w");
if (!arq)
{
return 0;
} else {
for (i = 0; i < tam; i++)
{
dif_anos = d_atual.ano - vet[i].ult_vacina.ano;
if ((dif_anos > 1) || (dif_anos == 1 && d_atual.mes > vet[i].ult_vacina.mes) || dif_anos
== 1 && d_atual.mes == vet[i].ult_vacina.mes && d_atual.dia > vet[i].ult_vacina.dia)

{

fprintf(arq, "%s | Prezado %s, a vacina do pet %s venceu no dia %i/ %i/ %i.
Podemos agendar nova dose?\n",

vet[i].email, vet[i].nome_tutor, vet[i].nome_pet, vet[i].ult_vacina.dia,

vet[i].ult_vacina.mes, vet[i].ult_vacina.ano + 1);
}
}
}
fclose(arq);
return 1;
}
