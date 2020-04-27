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
#include "ucs.h"
#include "relatorios/relatorio_a.h"

int main(int argc, char *argv[])
{
    // seleccao
    char *anoLectivo = "2019-2020"; // ano lectivo corrente
    
    // ler ficheiros
    INSCRICAO *inscricoes[299];
    int numInscricoes = readFileInscricoes(inscricoes);

    ALUNO *alunos[99];
    int numAlunos = readFileAlunos(alunos);

    UCS *uscs[99];
    int numUcss = readFileUcss(uscs);

    // mostra relatorio A
    printRelatorioA_Table(anoLectivo, alunos, inscricoes, uscs, numAlunos, numInscricoes, numUcss);

    return 0;
}

// Fim ficheiro "main.c"