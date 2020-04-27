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

#include "relatorio_d.h"
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


ANOSLECTIVOS *fillAnoLectivo(int aNum, char *ano) {
    ANOSLECTIVOS *output;
    output = malloc(500);

    output->aNum = aNum;
    strcpy(output->ano, ano);

    return output;
}

ANOSLECTIVOSTOTAL *fillAnoLectivoTotal(char *ano) {
    ANOSLECTIVOSTOTAL *output;
    output = malloc(500);

    strcpy(output->ano, ano);
    output->total = 1;

    return output;
}

int calculaRelatorio(ANOSLECTIVOSTOTAL *anosLectivosTotal[], INSCRICAO *inscricoes[], int tamInscricoes) {
    
    ANOSLECTIVOS *anosLectivos[299];
    int iAnosLectivos = 0;
    /*
        {
            "nAlun": 2001700,
            "anoLectivo": "2019-2020",
        }
    */
    for (size_t i = 0; i < tamInscricoes; i++)
    {
        INSCRICAO *inscricao = inscricoes[i];

        int index = (int)FindInscricoesIndex(anosLectivos, (size_t)iAnosLectivos, inscricao->aNum, inscricao->ano);
        if (index == -1) {
            // new
            anosLectivos[iAnosLectivos] = fillAnoLectivo(inscricao->aNum, inscricao->ano);
            iAnosLectivos += 1;
        }
    }

    /*
        {
            "anoLectivo": "2019-2020",
            "total": 12
        }
    */
    int iAnosLectivosTotal = 0;

    for (size_t i = 0; i < iAnosLectivos; i++)
    {
        ANOSLECTIVOS *anoLectivo = anosLectivos[i];

        int index = (int)FindAnosLectivosIndex(anosLectivosTotal, (size_t)iAnosLectivosTotal, anoLectivo->ano);
       
printf("\n ANOSLECTIVOS [%ld] %d %s", i, index, anoLectivo->ano);
        if (index == -1) {
            // new
            anosLectivosTotal[iAnosLectivosTotal] = fillAnoLectivoTotal(anoLectivo->ano);
            printf("\n [%d] %s", iAnosLectivosTotal, anosLectivosTotal[iAnosLectivosTotal]->ano);
            iAnosLectivosTotal += 1;
        } else {
            anosLectivosTotal[index]->total += 1;
        }    
    }

printf("\n SORT START");
    // ordernar anos lectivos
    sort(anosLectivosTotal, iAnosLectivosTotal);
printf("\n SORT END");
    
    // calcular variacao
    int valorAnterior = 0;   // guarda o valor total do ano lectivo anterior 
    for (size_t i = 0; i < iAnosLectivosTotal; i++) {
        ANOSLECTIVOSTOTAL *output = anosLectivosTotal[i];

        if (valorAnterior == 0) {
            output->variacao = "?";
        } else {

            // printf("\n VARIACAO %s - %d / %d * 100", output->ano, output->total, valorAnterior);

            // float variacao = ((output->total - valorAnterior) / valorAnterior) * 100;
            // ( (7-8) / 8 ) * 100 = -12.5 
            // "float variacao" diz que é zero!
            
            output->variacao = "+/- ??";

            // printf("\n VARIACAO t %d | va %f  | variacao %d = (%s)", output->total, valorAnterior, variacao, sVariacao);
        }
    
        // assigna o valor currente
        valorAnterior = output->total;
    }

    return iAnosLectivosTotal;
}

void printRelatorioD_Table(char *anoLectivo, 
    ALUNO *alunos[], INSCRICAO *inscricoes[], UCS *ucss[],
    int tamAlunos, int tamInscricoes, int tamUcss)
{
    ANOSLECTIVOSTOTAL *anosLectivosTotal[299];
    int iAnosLectivosTotal = calculaRelatorio(anosLectivosTotal, inscricoes, tamInscricoes);
    
    printf("\n╔═════════════════════════════════╕");
    printf("\n║ • Relatório D                   │");
    printf("\n╠═════════════════╤═══════════════╪═══════════════════╗");
    printf("\n╟── Ano Lectivo ──┼── N. Alunos ──┼── Variacao (%%) ───╢");
    printf("\n╠═════════════════╪═══════════════╪═══════════════════╣");

    for (size_t i = 0; i < iAnosLectivosTotal; i++) {
        ANOSLECTIVOSTOTAL *output = anosLectivosTotal[i];
        printf("\n SORT %s = %d (%s)", output->ano, output->total, output->variacao);
        // printf("\n║   %-8s │ %-18s │ %-12s │    %s    │  %5s   │    %s    ║",
    }

    printf("\n╠════════════╧════════════════════╧══════════════╧═════════════════╧══════════╧══════════╣");
    printf("\n║ *  Nº de inscrições deste um aluno ultrapassa o valor máximo 60 ECTS!                  ║");
    printf("\n║ ** Aluno não matriculano neste Ano Lectivo                                             ║");
    printf("\n╚════════════════════════════════════════════════════════════════════════════════════════╝\n");
}

// Fim ficheiro "relatorio_d.c"