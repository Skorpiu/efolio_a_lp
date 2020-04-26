/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio A

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: alunos.h
*/

#ifndef ALUNOS_H_INCLUDED
#define ALUNOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamLinha 70 + 1
#define tamNome 30  + 1
#define tamPais 30  + 1

typedef struct t_aluno ALUNO;
struct t_aluno
{
    int aNum;
    char nome[tamNome];
    char pais[tamPais];
};

int readFileAlunos(ALUNO *alunos[]);
ALUNO *getAluno(char *linha);

char *pad(char *s, int length);

#endif // ALUNOS_H_INCLUDED

// Fim ficheiro "alunos.h"