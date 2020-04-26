#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"

int main(int argc, char *argv[])
{
    FILE *alunos = NULL;

    printf("\nFicheiro de leitura: alunos.txt");
    alunos = fopen("alunos.txt", "r");

    char linha[tamLinha + 1];
    Aluno aluno;

    if (alunos != NULL)
    {
        printf("\nConteudo do Ficheiro:\n");
        while (fgets(linha, tamLinha, alunos) != NULL)
        {
            aluno = displayAluno(linha);
            printAluno(aluno);
        }
    }

    fclose(alunos);

    return 0;
}