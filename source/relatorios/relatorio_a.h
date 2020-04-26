/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio A

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Relatório A:
"a) Número total de ECTS das UCs a que cada aluno está inscrito no
ano letivo corrente. Apresente a lista com código e nome do aluno e
nº de ECTS. No caso de o nº de inscrições de um aluno ultrapassar o
valor máximo 60 ECTS, acrescentar uma observação, para que os
serviços validem a exceção."

Ficheiro: relatorio_a.h
*/

#ifndef RELATORIO_A_H_INCLUDED
#define RELATORIO_A_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../alunos.h"
#include "../inscricoes.h"
#include "../ucs.h"

void printAlunoA_Row(ALUNO *aluno, char *anoLectivo, int ectsTotal, int tamInscricoes);
void printRelatorioA_Table(char *anoLectivo, ALUNO *alunos[], INSCRICAO *inscricoes[], UCS *ucss[], int tamAlunos, int tamInscricoes, int tamUcss);

#endif // RELATORIO_A_H_INCLUDED

// Fim ficheiro "relatorio_a.h"