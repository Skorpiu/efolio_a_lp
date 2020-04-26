
#ifndef RELATORIOS_H_INCLUDED
#define RELATORIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"
#include "inscricoes.h"
#include "ucs.h"

char *pad(char *s, int length);

void printAlunoA_Row(ALUNO *aluno, char *anoLectivo, int ectsTotal, int tamInscricoes);
void printRelatorioA_Table(char *anoLectivo, ALUNO *alunos[], INSCRICAO *inscricoes[], UCS *ucss[], int tamAlunos, int tamInscricoes, int tamUcss);

#endif // RELATORIOS_H_INCLUDED