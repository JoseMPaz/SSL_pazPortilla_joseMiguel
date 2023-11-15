#ifndef _OPERACIONES_H_
#define _OPERACIONES_H_

#include "variables.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    char sval[200];
    int tipo;
    double dval;
}operacion_t;

void validar_operacion (operacion_t elem1, operacion_t elem2, nodo_variable_t ** variables, int yylineno);

#endif
