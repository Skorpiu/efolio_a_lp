#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"
#include "inscricoes.h"
#include "relatorio_a.h"
#include "ucs.h"

int main(int argc, char *argv[])
{
    // seleccao
    char *anoLectivo = "2018-2019";
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
        printRelatorioA_Table(anoLectivo, alunos, inscricoes, uscs, numAlunos, numInscricoes, numUcss);
        break;
    case 'C':
    case 'c':
        printRelatorioA_Table(anoLectivo, alunos, inscricoes, uscs, numAlunos, numInscricoes, numUcss);
        break;
    case 'D':
    case 'd':
        printRelatorioA_Table(anoLectivo, alunos, inscricoes, uscs, numAlunos, numInscricoes, numUcss);
        break;

    default:
        perror("Relatório não especificado, ou inexistente!");
        break;
    }

    return 0;
}