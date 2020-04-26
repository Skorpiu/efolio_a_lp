
#ifndef RELATORIOS_H_INCLUDED
#define RELATORIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"
#include "inscricoes.h"

char *pad(char *s, int length);

void printAlunoBoxUnit(ALUNO *aluno, INSCRICAO *inscricoes[], int tamInscricoes);
void printRelatorioBoxes(ALUNO *alunos[], INSCRICAO *inscricoes[], int tamAlunos, int tamInscricoes);

void printAlunoRow(ALUNO *aluno, char *anoLectivo, int ectsTotal, int tamInscricoes);
void printRelatorioTable(char *anoLectivo, ALUNO *alunos[], INSCRICAO *inscricoes[], int tamAlunos, int tamInscricoes);

#endif // RELATORIOS_H_INCLUDED