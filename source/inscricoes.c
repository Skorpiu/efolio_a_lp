
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inscricoes.h"

INSCRICAO *getInscricao(char *linha)
{
    INSCRICAO *output;
    output = malloc(500);

    const char delimitar[2] = ";";
    int i = 0;
    char *token = strtok(linha, delimitar);

    /*
        token[0] = 2001700
        token[1] = 21002
        token[2] = 2019-2020
        token[3] = 10
        token[4] = NULL
    */

    while (token != NULL)
    {
        switch (i)
        {
        case 0:
            output->aNum = atoi(token);
            break;
        case 1:
            output->uc = atoi(token);
            break;
        case 2:
            strcpy(output->ano, token);
            break;
        case 3:
            output->nota = atoi(token);
            break;

        default:
            break;
        }

        // get next line
        token = strtok(NULL, delimitar);
        i++;
    }

    return output;
}

int readFileInscricoes(INSCRICAO *inscricoes[])
{
    printf("\nFicheiro de leitura: inscricoes.txt");
    FILE *ficheiro = fopen("./files/inscricoes.txt", "r");

    int count = 0;
    char linha[tamLinhaInscricao];
    
    INSCRICAO *output;
    output = malloc(sizeof(output));

    if (ficheiro != NULL)
    {
        while (fgets(linha, tamLinhaInscricao, ficheiro) != 0)
        {
            output = getInscricao(linha);
            inscricoes[count++] = output;
        }
    }

    fclose(ficheiro);
    return count;
}
