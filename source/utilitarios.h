/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio A

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: utilitarios.h
*/

#ifndef UTILITARIOS_H_INCLUDED
#define UTILITARIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ucs.h"
#include "inscricoes.h"

int countECTS(INSCRICAO *inscricoes[], UCS *uscs[], int tamInscricoes, int tamUcss, int aNum, char *anoLectivo);

#endif // UTILITARIOS_H_INCLUDED

// Fim ficheiro "utilitarios.h"