/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio A

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: alunos.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"

// Recolha dos dados existentes no ficheiro "alunos.txt"
ALUNO *getAluno(char *linha)
{
    ALUNO *output;
    output = malloc(500);

    const char delimitar[2] = ";";
    int i = 0;
    char *token = strtok(linha, delimitar);

    /*
        token[0] = 2001700
        token[1] = Artur Cruz
        token[2] = Cabo Verde
        token[3] = NULL
    */

    while (token != NULL)
    {
        switch (i)
        {
            // [0] 2001700; [1] Artur Cruz; [2] Cabo Verde
        case 0:
            output->aNum = atoi(token);
            break;
        case 1:
            strcpy(output->nome, token);
            break;
        case 2:
            token[strcspn(token, "\r\n")] = '\0'; // retira caracter de nova linha
            strcpy(output->pais, token);
            break;

        default:
            break;
        }

        // linha seguinte
        token = strtok(NULL, delimitar);
        i++;
    }

    return output;
}

int readFileAlunos(ALUNO *alunos[])
{
    printf("\nFicheiro de leitura: alunos.txt");
    FILE *ficheiro = fopen("./files/alunos.txt", "r");

    int count = 0;
    char linha[tamLinha];
    
    ALUNO *output;
    output = malloc(sizeof(output));

    if (ficheiro != NULL)
    {
        while (fgets(linha, tamLinha, ficheiro) != 0)
        {
            output = getAluno(linha);
            alunos[count++] = output;
        }
    }

    fclose(ficheiro);
    return count;
}

// Fim ficheiro "alunos.c"