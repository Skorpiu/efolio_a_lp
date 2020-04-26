#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ucs.h"
#include "inscricoes.h"

int countECTS(INSCRICAO *inscricoes[], UCS *uscs[], int tamInscricoes, int tamUcss, int aNum, char *anoLectivo)
{
    int count = 0;
    for (size_t i = 0; i < tamInscricoes; i++)
    {
        INSCRICAO *inscricao = inscricoes[i];
        
        if (inscricao->aNum == aNum && strcmp(inscricao->ano, anoLectivo) == 0)
        {
            // printf("ALUNO (%d) ECTS (%d) >%s< == >%s<\n", inscricao->aNum, inscricao->nota, inscricao->ano, anoLectivo);
            
            for (size_t z = 0; z < tamUcss; z++) {
                UCS *ucs = uscs[z];
                if(inscricao->uc == ucs->uc) {
                    count += ucs->ects;
                    break;
                }
            }
        }
    }

    return count;
}