#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"
#include "inscricoes.h"
#include "relatorios.h"

int main(int argc, char *argv[])
{
    INSCRICAO *inscricoes[299];
    int numInscricoes = readFileInscricoes(inscricoes);

    ALUNO *alunos[99];
    int numAlunos = readFileAlunos(alunos);

    printRelatorioTable("2019-2020", alunos, inscricoes, numAlunos, numInscricoes);

    return 0;
}