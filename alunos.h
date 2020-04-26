
#ifndef ALUNOS_H_INCLUDED
#define ALUNOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamLinha 70 + 1
#define tamNome 30  + 1
#define tamPais 30  + 1

typedef struct
{
    int aNum;
    char nome[tamNome];
    char pais[tamPais];
} Aluno;

Aluno displayAluno(char *linha);
void printAluno(Aluno aluno);

#endif // ALUNOS_H_INCLUDED