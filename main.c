#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"
#include "inscricoes.h"
#include "relatorios.h"
#include "ucs.h"

int main(int argc, char *argv[])
{
    INSCRICAO *inscricoes[299];
    int numInscricoes = readFileInscricoes(inscricoes);

    ALUNO *alunos[99];
    int numAlunos = readFileAlunos(alunos);

    UCS *uscs[99];
    int numUcss = readFileUcss(uscs);

    printRelatorioTable("2019-2020", alunos, inscricoes, uscs, numAlunos, numInscricoes, numUcss);

    return 0;
}