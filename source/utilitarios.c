/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio A

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: utilitarios.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ucs.h"
#include "inscricoes.h"
#include "./relatorios/relatorio_d.h"

// Função de cálculo dos ECTS
int countECTS(INSCRICAO *inscricoes[], UCS *uscs[], int tamInscricoes, int tamUcss, int aNum, char *anoLectivo)
{
    int countUc = 0;
    int countUcNota = 0;
    int countECTS = 0;
    for (size_t i = 0; i < tamInscricoes; i++)
    {
        INSCRICAO *inscricao = inscricoes[i];
        
        if (inscricao->aNum == aNum && strcmp(inscricao->ano, anoLectivo) == 0)
        {
            if (inscricao->nota >= 10) countUc++;

            countUcNota += inscricao->nota;

            for (size_t z = 0; z < tamUcss; z++) {
                UCS *ucs = uscs[z];
                if(inscricao->uc == ucs->uc) {
                    countECTS += ucs->ects;
                    break;
                }
            }
        }
    }
    return countECTS;
}

size_t FindInscricoesIndex(ANOSLECTIVOS *a[], size_t size, int aNum, char *anoLectivo)
{
    if (size == 0) return -1;

    size_t index = 0;

    while ( index < size ) {
        if (a[index]->aNum == aNum && strcmp(a[index]->ano, anoLectivo) == 0)
            break;
        else 
            ++index;
    } 

    return ( index == size ? -1 : index );
}

size_t FindAnosLectivosIndex(ANOSLECTIVOSTOTAL *a[], size_t size, char *anoLectivo)
{
    if (size == 0) return -1;

    size_t index = 0;

    while ( index < size ) {
        if (strcmp(a[index]->ano, anoLectivo) == 0)
            break;
        else 
            ++index;
    } 

    return ( index == size ? -1 : index );
}

static int myCompare(const void* a, const void* b) 
{ 
  
    // setting up rules for comparison 
    return strcmp(*(const char**)a, *(const char**)b); 
} 
  
// Function to sort the array 
void sort(ANOSLECTIVOSTOTAL *arr[], int n) 
{ 
    // calling qsort function to sort the array 
    // with the help of Comparator 
    qsort(arr, n, sizeof(const char*), myCompare); 
}

// Fim ficheiro "utilitarios.c"