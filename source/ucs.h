/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio A

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: ucs.h
*/

#ifndef UCSS_H_INCLUDED
#define UCSS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamLinhaUcs 70 + 1
#define tamNomeUcs 70 + 1
#define tamAnoUcs 6 + 1
#define tamSemestre 6 + 1

typedef struct t_ucs UCS;
struct t_ucs
{
    int uc;
    char nome[tamNomeUcs];
    char ano[tamAnoUcs];
    char semestre[tamSemestre];
    int ects;
};

UCS *getUcs(char *linha);
int readFileUcss(UCS *ucss[]);

#endif // UCSS_H_INCLUDED

// Fim ficheiro "ucs.h"