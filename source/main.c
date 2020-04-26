/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio A

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"
#include "inscricoes.h"
#include "relatorios/relatorio_a.h"
#include "relatorios/relatorio_b.h"
#include "relatorios/relatorio_c.h"
#include "relatorios/relatorio_d.h"
#include "ucs.h"

int main(int argc, char *argv[])
{
    // seleccao
    char *anoLectivo = "2019-2020";
    char relatorio = 0;
    printf("\nEscolha o tipo de relatório (A, B, C, D): ");
    scanf("%c", &relatorio);

    // ler ficheiros
    INSCRICAO *inscricoes[299];
    int numInscricoes = readFileInscricoes(inscricoes);

    ALUNO *alunos[99];
    int numAlunos = readFileAlunos(alunos);

    UCS *uscs[99];
    int numUcss = readFileUcss(uscs);

    // imprime relatorio escolhido
    switch (relatorio)
    {
    case 'A':
    case 'a':
        printRelatorioA_Table(anoLectivo, alunos, inscricoes, uscs, numAlunos, numInscricoes, numUcss);
        break;
    case 'B':
    case 'b':
        printRelatorioB_Table(anoLectivo, alunos, inscricoes, uscs, numAlunos, numInscricoes, numUcss);
        break;
    case 'C':
    case 'c':
        printRelatorioC_Table(anoLectivo, alunos, inscricoes, uscs, numAlunos, numInscricoes, numUcss);
        break;
    case 'D':
    case 'd':
        printRelatorioD_Table(anoLectivo, alunos, inscricoes, uscs, numAlunos, numInscricoes, numUcss);
        break;

    default:
        perror("Relatório não especificado, ou inexistente!");
        break;
    }

    return 0;
}

// Fim ficheiro "main.c"