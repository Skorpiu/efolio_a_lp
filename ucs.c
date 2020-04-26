
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ucs.h"

UCS *getUcs(char *linha)
{
    UCS *output;
    output = malloc(500);

    const char delimitar[2] = ";";
    int i = 0;
    char *token = strtok(linha, delimitar);

    /*
        token[0] = 21046
        token[1] = Estruturas_de_Dados_e_Algoritmos_Fundamentais
        token[2] = 2o_Ano
        token[3] = 2o_Sem
        token[4] = 6
    */

    while (token != NULL)
    {
        switch (i)
        {
        case 0:
            output->uc = atoi(token);
            break;
        case 1:
            strcpy(output->nome, token);
            break;
        case 2:
            strcpy(output->ano, token);
            break;
        case 3:
            strcpy(output->semestre, token);
            break;
        case 4:
            output->ects = atoi(token);
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

int readFileUcss(UCS *ucss[])
{
    printf("\nFicheiro de leitura: ucs.txt");
    FILE *ficheiro = fopen("ucs.txt", "r");

    int count = 0;
    char linha[tamLinhaUcs];
    
    UCS *output;
    output = malloc(sizeof(output));

    if (ficheiro != NULL)
    {
        while (fgets(linha, tamLinhaUcs, ficheiro) != 0)
        {
            output = getUcs(linha);
            ucss[count++] = output;
        }
    }

    fclose(ficheiro);
    return count;
}
