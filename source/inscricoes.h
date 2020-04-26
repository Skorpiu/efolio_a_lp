/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio A

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: inscricoes.h
*/

#ifndef INSCRICOES_H_INCLUDED
#define INSCRICOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamLinhaInscricao 70 + 1
#define tamAno 9 + 1

typedef struct t_inscricao INSCRICAO;
struct t_inscricao
{
    int aNum;
    int uc;
    char ano[tamAno];
    int nota;
};

INSCRICAO *getInscricao(char *linha);
int readFileInscricoes(INSCRICAO *inscricoes[]);

#endif // INSCRICOES_H_INCLUDED

// Fim ficheiro "inscricoes.h"