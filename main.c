#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"

int main(int argc, char *argv[])
{
    printf("\nFicheiro de leitura: alunos.txt");
    FILE *fAlunos = fopen("alunos.txt", "r");

    char linha[tamLinha + 1];
    ALUNO *aluno;
    aluno = malloc(sizeof(aluno));
    
    int iAluno = 0;
    ALUNO *alunos[99];
    // alunos = malloc(sizeof(alunos));

    if (alunos != NULL)
    {
        printf("\nConteudo do Ficheiro:\n");
        while (fgets(linha, tamLinha, fAlunos) != 0)
        {
            aluno = displayAluno(linha, "2019-2020");
            alunos[iAluno] = aluno;            
            iAluno += 1;
        }

        printAlunos(alunos, iAluno);
    }

    fclose(fAlunos);
    return 0;
}