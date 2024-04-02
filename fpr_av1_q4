--nota baixa--

//importação de biblioteca
#include <stdio.h>
#include <string.h>
//definição de tipo
typedef struct {
char nome[10];
char codigo[10];
float av1, av2;
}TAluno;
typedef struct {
char situacao[10];
int quant;
}TSQ;;
typedef struct {
char codigo[10];
TSQ sq;
}TDisciplinas;
//protótipo da função
void exibir (TAluno aluno[], TDisciplinas disc[]);
void questao4 (TAluno aluno[], TDisciplinas disc[]);
//main
int main ()
{
TAluno vet_alunos[10] = {{"JOAO", "FAC", 10, 8},
{"PEDRO", "ESD", 6, 7},
{"MARIA", "FPR", 10, 5},
{"ANA", "FAC", 8, 3},
{"CARLOS", "FAC", 7, 7},
{"PAULO", "FPR", 5, 2},
{"KATIA", "ESD", 5, 9},
{"SILVIA", "FAC", 2, 4},
{"GLORIA", "FPR", 4, 1},
{"ANTONIO", "ESD", 3, 4}};

TDisciplinas vet_disc[10];
exibir (vet_alunos, vet_disc);
questao4 (vet_alunos, vet_disc);

}
void exibir (TAluno aluno[], TDisciplinas disc[])
{
int i;
for (i=0; i<10; i++)
{
printf("%s\n%s\n%.1f\n%.1f\n\n", aluno[i].nome, aluno[i].codigo, aluno[i].av1,

aluno[i].av2);
}
}
void questao4 (TAluno aluno[], TDisciplinas disc[])
{
//declaração de variáveis
int i, j;
float media;
//iniciando quant = 0
for (i=0; i<10; i++)
{
disc[i].sq.quant = 0;
}
//verificando medias
for (i=0, j=0; i<10; i++)
{
media = (aluno[i].av1 + aluno[i].av2) / 2;
if (media >=6)
{
strcpy (disc[i].codigo, aluno[i].codigo);
strcpy (disc[i].sq.situacao, "aprovado");
disc[j].sq.quant++;
j++;
} else {
if (media < 4)
{
strcpy (disc[i].codigo, aluno[i].codigo);
strcpy (disc[i].sq.situacao, "reprovado");
disc[j].sq.quant++;
j++;
} else {
strcpy (disc[i].codigo, aluno[i].codigo);

strcpy (disc[i].sq.situacao, "em AVF");
disc[j].sq.quant++;
j++;
}
}
}
for (j=0; j<10; j++)
{
printf("\n%s\n%s", disc[j].codigo, disc[j].sq.situacao);
if (strcmp (disc[j].sq.situacao, "aprovado") == 0)
{
printf("\n%i\n", disc[j].sq.quant);
}
if ((strcmp (disc[j].sq.situacao, "em AVF") == 0))
{
printf("\n%i\n", disc[j].sq.quant);
}
if ((strcmp (disc[j].sq.situacao, "reprovados") == 0))
{
printf("\n%i\n", disc[j].sq.quant);
}
}
}
