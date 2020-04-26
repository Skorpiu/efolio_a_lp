#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"
#include "inscricoes.h"

int main(int argc, char *argv[])
{
    INSCRICAO *inscricoes[299];
    int numInscricoes = readFileInscricoes(inscricoes);

    ALUNO *alunos[99];
    int numAlunos = readFileAlunos(alunos);

    printAlunos(alunos, numAlunos);

    return 0;
}