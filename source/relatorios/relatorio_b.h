/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio A

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Relatório B:
"b) Lista de alunos que podem aceder à época de exame especial.
Considere que um aluno poderá fazer a época especial se já
frequentou todas as unidades curriculares, faltando-lhe apenas obter
aprovação a um máximo de 3 UCs."

Ficheiro: relatorio_b.h
*/

#ifndef RELATORIO_B_H_INCLUDED
#define RELATORIO_B_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../alunos.h"
#include "../inscricoes.h"
#include "../ucs.h"

void printAlunoB_Row(ALUNO *aluno, char *anoLectivo, int ectsTotal, int tamInscricoes);
void printRelatorioB_Table(char *anoLectivo, ALUNO *alunos[], INSCRICAO *inscricoes[], UCS *ucss[], int tamAlunos, int tamInscricoes, int tamUcss);

#endif // RELATORIO_B_H_INCLUDED

// Fim ficheiro "relatorio_b.h"