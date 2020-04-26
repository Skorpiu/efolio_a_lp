#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"

int main(int argc, char *argv[])
{
    printf("\nFicheiro de leitura: alunos.txt");
    FILE *alunos = fopen("alunos.txt", "r");

    char linha[tamLinha + 1];
    ALUNO *aluno;
    aluno = malloc(sizeof(aluno));

    if (alunos != NULL)
    {
        printf("\nConteudo do Ficheiro:\n");
        while (fgets(linha, tamLinha, alunos) != 0)
        {
            aluno = displayAluno(linha, "2019-2020");
            printAluno(aluno);
        }
    }

    fclose(alunos);

    return 0;
}