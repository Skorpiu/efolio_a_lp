#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilitarios.h"
#include "alunos.h"
#include "inscricoes.h"
#include "ucs.h"

void printAlunoA_Row(ALUNO *aluno, char *anoLectivo, int ectsTotal)
{
    char nAlun[tamNome] = "";
    sprintf(nAlun, "%d", aluno->aNum);
    char nECTS[tamNome] = "";
    sprintf(nECTS, "%d", ectsTotal);

    char *obs = "  ";
    if(ectsTotal > 60) obs = "* ";
    if(ectsTotal == 0) obs = "**";

    printf("\n║ %s │ %s │ %s │    %s    │    %s │    %s    ║",
           pad(nAlun, 11),
           pad(aluno->nome, 19),
           pad(aluno->pais, 13),
           anoLectivo,
           pad(nECTS, 6),
           obs);
}

void printRelatorioA_Table(char *anoLectivo, ALUNO *alunos[], INSCRICAO *inscricoes[], UCS *ucss[], int tamAlunos, int tamInscricoes, int tamUcss)
{
    printf("\n╔═════════════════════════════════╕");
    printf("\n║ * Relatório A                   │");
    printf("\n╠════════════╤════════════════════╪══════════════╤═════════════════╤══════════╤══════════╗");
    printf("\n╟── Número ──┼─────── Nome ───────┼──── País ────┼── Ano Lectivo ──┼── ECTS ──┼── Obs. ──╢");
    printf("\n╠════════════╪════════════════════╪══════════════╪═════════════════╪══════════╪══════════╣");
    for (size_t i = 0; i < tamAlunos; i++)
    {
        ALUNO *aluno = alunos[i];
        int ectsCount = countECTS(inscricoes, ucss, tamInscricoes, tamUcss, aluno->aNum, anoLectivo);
        printAlunoA_Row(aluno, anoLectivo, ectsCount);
    }
    printf("\n╠════════════╧════════════════════╧══════════════╧═════════════════╧══════════╧══════════╣");
    printf("\n║ *  Nº de inscrições deste um aluno ultrapassa o valor máximo 60 ECTS!                  ║");
    printf("\n║ ** Aluno não matriculano neste Ano Lectivo                                             ║");
    printf("\n╚════════════════════════════════════════════════════════════════════════════════════════╝\n");
}