#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"
#include "inscricoes.h"

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

void printAlunoBoxUnit(ALUNO *aluno, INSCRICAO *inscricoes[], int tamInscricoes)
{
    char nAlun[tamNome] = "";
    sprintf(nAlun, "%d", aluno->aNum);

    // https://www.rapidtables.com/code/text/ascii-table.html
    char s;
    printf("\n╔═══════════════════════════════════════════╗");
    printf("\n║                A L U N O                  ║");
    printf("\n╟───────────────────────────────────────────╢");
    printf("\n║  Numero:    %s%s", pad(nAlun, tamNome), "║");
    printf("\n║  Nome:      %s%s", pad(aluno->nome, tamNome), "║");
    printf("\n║  Reside em: %s%s", pad(aluno->pais, tamPais), "║");
    // printf("\n║  ETCS: %s%s", pad(aluno.inscricoes., tamPais), "║");
    printf("\n╚═══════════════════════════════════════════╝\n");
}

void printRelatorioBoxes(ALUNO *alunos[], INSCRICAO *inscricoes[], int tamAlunos, int tamInscricoes)
{
    for (size_t i = 0; i < tamAlunos; i++)
    {
        ALUNO *aluno = alunos[i];
        printAlunoBoxUnit(aluno, inscricoes, tamInscricoes);
    }
}

void printAlunoRow(ALUNO *aluno, char *anoLectivo, int ectsTotal, int tamInscricoes)
{
    char nAlun[tamNome] = "";
    sprintf(nAlun, "%d", aluno->aNum);
    char nECTS[tamNome] = "";
    sprintf(nECTS, "%d", ectsTotal);

    char *obs = " ";
    if(ectsTotal > 60) {
        obs = "*";
    }

    printf("\n║ %s │ %s │ %s │    %s    │    %s │    %s     ║",
           pad(nAlun, 11),
           pad(aluno->nome, 19),
           pad(aluno->pais, 13),
           anoLectivo,
           pad(nECTS, 6),
           obs);
}

int countECTS(INSCRICAO *inscricoes[], int tamInscricoes, int aNum, char *anoLectivo)
{
    int count = 0;
    for (size_t i = 0; i < tamInscricoes; i++)
    {
        INSCRICAO *inscricao = inscricoes[i];
        
        if (inscricao->aNum == aNum && strcmp(inscricao->ano, anoLectivo) == 0)
        {
            // printf("ALUNO (%d) ECTS (%d) >%s< == >%s<\n", inscricao->aNum, inscricao->nota, inscricao->ano, anoLectivo);
            count += inscricao->nota;
        }
    }

    return count;
}

void printRelatorioTable(char *anoLectivo, ALUNO *alunos[], INSCRICAO *inscricoes[], int tamAlunos, int tamInscricoes)
{
    printf("\n╔════════════╤════════════════════╤══════════════╤═════════════════╤══════════╤══════════╗");
    printf("\n╟── Número ──┼─────── Nome ───────┼──── País ────┼── Ano Lectivo ──┼── ECTS ──┼── Obs. ──╢");
    printf("\n╠════════════╪════════════════════╪══════════════╪═════════════════╪══════════╪══════════╣");
    for (size_t i = 0; i < tamAlunos; i++)
    {
        ALUNO *aluno = alunos[i];
        int ectsCount = countECTS(inscricoes, tamInscricoes, aluno->aNum, anoLectivo);
        printAlunoRow(aluno, anoLectivo, ectsCount, tamInscricoes);
    }
    printf("\n╠════════════╧════════════════════╧══════════════╧═════════════════╧══════════╧══════════╣");
    printf("\n║ * Nº de inscrições deste um aluno ultrapassa o valor máximo 60 ECTS!                   ║");
    printf("\n╚════════════════════════════════════════════════════════════════════════════════════════╝\n");
}