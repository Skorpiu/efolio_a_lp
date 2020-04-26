
#ifndef INSCRICOES_H_INCLUDED
#define INSCRICOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamLinha 70 + 1
#define tamAno 9 + 1

typedef struct t_inscricao INSCRICAO;
struct t_inscricao
{
    int aNum;
    int uc;
    char ano[tamAno];
    int nota;
};

void readFileInscricoes(char *aNum);
INSCRICAO* displayInscricao(char *linha);
INSCRICAO* getInscricoes(int aNum, char *ano);

#endif // INSCRICOES_H_INCLUDED