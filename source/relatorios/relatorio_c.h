/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio A

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Relatório C:
"c) Listagem das situações de potencial abandono no ano letivo
corrente. Considere que um aluno está em potencial situação de
abandono se não efetuou inscrições no 2º semestre, tendo estado
inscrito a duas ou mais UCs no 1º semestre."

Ficheiro: relatorio_c.h
*/

#ifndef RELATORIO_C_H_INCLUDED
#define RELATORIO_C_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../alunos.h"
#include "../inscricoes.h"
#include "../ucs.h"

void printAlunoC_Row(ALUNO *aluno, char *anoLectivo, int ectsTotal, int tamInscricoes);
void printRelatorioC_Table(char *anoLectivo, ALUNO *alunos[], INSCRICAO *inscricoes[], UCS *ucss[], int tamAlunos, int tamInscricoes, int tamUcss);

#endif // RELATORIO_C_H_INCLUDED

// Fim ficheiro "relatorio_c.h"