
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"
// #include "inscricoes.h"

ALUNO *displayAluno(char *linha, char *ano)
{
    const char delimitar[2] = ";";
    ALUNO *aluno;
    aluno = malloc(500);
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
            aluno->aNum = atoi(token);
            break;
        case 1:
            strcpy(aluno->nome, token);
            break;
        case 2:
            token[strcspn(token, "\r\n")] = '\0'; // retira caracter de nova linha
            strcpy(aluno->pais, token);

            // append INSCRICOES
            // aluno->inscricoes = getInscricoes(aluno->aNum, ano);
            break;

        default:
            break;
        }

        // get next line
        token = strtok(NULL, delimitar);
        i++;
    }

    return aluno;
}

char *pad(char *s, int length)
{
    int l = strlen(s); /* its length */

    while (l < length)
    {
        s[l] = ' '; /* insert a space */
        l++;
    }
    s[l - 1] = '\0'; /* strings need to be terminated in a null */
    return s;
}

void printAluno(ALUNO *aluno)
{
    char strNumero[tamNome] = "";
    sprintf(strNumero, "%d", aluno->aNum);

    // https://www.rapidtables.com/code/text/ascii-table.html
    char s;
    printf("\n╔═══════════════════════════════════════════╗");
    printf("\n║                A L U N O                  ║");
    printf("\n╟───────────────────────────────────────────╢");
    printf("\n║  Numero:    %s%s", pad(strNumero, tamNome), "║");
    printf("\n║  Nome:      %s%s", pad(aluno->nome, tamNome), "║");
    // printf("\n║  Reside em: %s%s", pad(aluno.pais, tamPais), "║");
    //printf("\n║  ETCS: %s%s", pad(aluno.inscricoes., tamPais), "║");
    printf("\n╚═══════════════════════════════════════════╝\n");
}

void printAlunos(ALUNO *alunos[], int iAluno)
{
    for (size_t i = 0; i < iAluno; i++)
    {
        printAluno(alunos[i]);
    }    
}