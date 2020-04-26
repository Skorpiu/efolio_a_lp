
#ifndef RELATORIOS_H_INCLUDED
#define RELATORIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"
#include "inscricoes.h"
#include "ucs.h"

char *pad(char *s, int length);

void printAlunoBoxUnit(ALUNO *aluno, INSCRICAO *inscricoes[], int tamInscricoes);
void printRelatorioBoxes(ALUNO *alunos[], INSCRICAO *inscricoes[], int tamAlunos, int tamInscricoes);

int countECTS(INSCRICAO *inscricoes[], UCS *uscs[], int tamInscricoes, int tamUcss, int aNum, char *anoLectivo);
void printAlunoRow(ALUNO *aluno, char *anoLectivo, int ectsTotal, int tamInscricoes);
void printRelatorioTable(char *anoLectivo, ALUNO *alunos[], INSCRICAO *inscricoes[], UCS *ucss[], int tamAlunos, int tamInscricoes, int tamUcss);

#endif // RELATORIOS_H_INCLUDED