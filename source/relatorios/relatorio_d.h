/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio A

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Relatório D:
"d) Número de alunos por ano letivo. Apresente a lista com o ano
letivo, nº de alunos inscritos nesse ano e percentagem de variação
relativamente ao anterior (sinal positivo se for aumento, sinal
negativo se decréscimo)."

Ficheiro: relatorio_d.h
*/

#ifndef RELATORIO_D_H_INCLUDED
#define RELATORIO_D_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../alunos.h"
#include "../inscricoes.h"
#include "../ucs.h"

typedef struct t_anosLectivos ANOSLECTIVOS;
struct t_anosLectivos
{
    int aNum;
    char ano[tamAno];
};

typedef struct t_anosLectivosTotal ANOSLECTIVOSTOTAL;
struct t_anosLectivosTotal
{
    char ano[tamAno];
    int total;
    char *variacao; // "-14" "+25.43"
};

void printAlunoD_Row(ALUNO *aluno, char *anoLectivo, int ectsTotal);
void printRelatorioD_Table(char *anoLectivo, ALUNO *alunos[], INSCRICAO *inscricoes[], UCS *ucss[], int tamAlunos, int tamInscricoes, int tamUcss);

ANOSLECTIVOSTOTAL *fillAnoLectivoTotal(char *ano);
ANOSLECTIVOS *fillAnoLectivo(int aNum, char *ano);

#endif // RELATORIO_D_H_INCLUDED

// Fim ficheiro "relatorio_d.h"