
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