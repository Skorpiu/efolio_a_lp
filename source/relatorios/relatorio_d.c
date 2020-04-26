/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio A

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Relatório D:
"d) Número de alunos por ano letivo. Apresente a lista com o ano
letivo, nº de alunos inscritos nesse ano e percentagem de variação
relativamente ao anterior (sinal positivo se for aumento, sinal
negativo se decréscimo)."

Ficheiro: relatorio_d.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utilitarios.h"
#include "../alunos.h"
#include "../inscricoes.h"
#include "../ucs.h"

void printAlunoD_Row(ALUNO *aluno, char *anoLectivo, int ectsTotal)
{
    char nAlun[tamNome] = "";
    sprintf(nAlun, "%d", aluno->aNum);
    char nECTS[tamNome] = "";
    sprintf(nECTS, "%d", ectsTotal);

    char *obs = "  ";
    if(ectsTotal > 60) obs = "* ";
    if(ectsTotal == 0) obs = "**";

    printf("\n║ %-10s │ %-18s │ %-12s │    %s    │  %5s   │    %s    ║",
           nAlun,
           aluno->nome,
           aluno->pais,
           anoLectivo,
           nECTS,
           obs);
}

void printRelatorioD_Table(char *anoLectivo, ALUNO *alunos[], INSCRICAO *inscricoes[], UCS *ucss[], int tamAlunos, int tamInscricoes, int tamUcss)
{
    printf("\n╔═════════════════════════════════╕");
    printf("\n║ • Relatório D                   │");
    printf("\n╠════════════╤════════════════════╪══════════════╤═════════════════╤══════════╤══════════╗");
    printf("\n╟── Número ──┼─────── Nome ───────┼──── País ────┼── Ano Lectivo ──┼── ECTS ──┼── Obs. ──╢");
    printf("\n╠════════════╪════════════════════╪══════════════╪═════════════════╪══════════╪══════════╣");
    for (size_t i = 0; i < tamAlunos; i++)
    {
        ALUNO *aluno = alunos[i];
        int ectsCount = countECTS(inscricoes, ucss, tamInscricoes, tamUcss, aluno->aNum, anoLectivo);
        printAlunoD_Row(aluno, anoLectivo, ectsCount);
    }
    printf("\n╠════════════╧════════════════════╧══════════════╧═════════════════╧══════════╧══════════╣");
    printf("\n║ *  Nº de inscrições deste um aluno ultrapassa o valor máximo 60 ECTS!                  ║");
    printf("\n║ ** Aluno não matriculano neste Ano Lectivo                                             ║");
    printf("\n╚════════════════════════════════════════════════════════════════════════════════════════╝\n");
}

// Fim ficheiro "relatorio_d.c"