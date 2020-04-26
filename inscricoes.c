
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inscricoes.h"

void readFileInscricoes(char *aNum, char *ano)
{
    FILE *fInscricoes = fopen("inscricoes.txt", "r");

    int iInscricao = 0
    char linha[tamLinha];
    INSCRICAO *inscricao;
    INSCRICAO[100] *inscricoes;

    if (inscricoes != NULL)
    {
        while (fgets(linha, tamLinha, fInscricoes) != 0)
        {
            inscricao = displayInscricao(linha);
            // is the aNum and ano?
            if(inscricao->aNum == aNum && inscricao->ano == ano) {
                // only append to list if "aNum" & "ano"
                inscricoes[iInscricao++] = inscricao;
            }
        }
    }

    fclose(inscricoes);
    return inscricoes;
}

INSCRICAO *displayInscricao(char *linha)
{
    const char delimitar[2] = ";";
    INSCRICAO *inscricao;
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
            inscricao->aNum = atoi(token);
            break;
        case 1:
            inscricao->uc = atoi(token);
            break;
        case 2:
            strcpy(inscricao->ano, token);
            break;
        case 3:
            inscricao->nota = atoi(token);
            break;

        default:
            break;
        }

        // get next line
        token = strtok(NULL, delimitar);
        i++;
    }

    return inscricao;
}

INSCRICAO *getInscricoes(int aNum, char *ano) {
    // return readFileInscricoes(aNum, ano);
}
