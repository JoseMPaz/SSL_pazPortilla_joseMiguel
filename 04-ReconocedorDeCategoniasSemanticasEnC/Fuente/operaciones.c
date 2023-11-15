#include "operaciones.h"

void validar_operacion (operacion_t elem1, operacion_t elem2 , nodo_variable_t ** variables, int yylineno)
{
    nodo_variable_t * aux;

    if(elem1.sval != "-"){
        aux = buscar_variable(*variables, elem1.sval);
        // printf("%f valor de %s %s", aux->info.valor, aux->info.nombre_variable, elem1.sval);
        if(aux == NULL){
           printf("Error semantico: La variable %s no fue inicializada, linea: %d\n", elem1.sval, yylineno);
           return;
        }else{
            elem1.dval = aux->info.valor;
        }
    }    
    if(elem2.sval != "-"){
        aux = buscar_variable(*variables, elem2.sval);
        // printf("%f valor de %s %s", aux->info.valor, aux->info.nombre_variable, elem1.sval);
        if(aux == NULL){
           printf("Error semantico: La variable %s no fue inicializada, linea: %d\n", elem2.sval, yylineno);
           return;
        }else{
            elem2.dval = aux->info.valor;
        }
    }    

    if(elem1.tipo == 1 && elem2.tipo == 1 ){ 
        printf("Hay una SUMA: %.2f + %.2f = %.2f\n", elem1.dval, elem2.dval, elem1.dval+elem2.dval); 
    } else if(elem1.tipo == 2 && elem2.tipo == 1 ){
        printf("Hay una SUMA: %s: %.2f + %.2f = %.2f\n", elem1.sval, elem1.dval, elem2.dval, elem1.dval+elem2.dval); 
    } else if(elem1.tipo == 1 && elem2.tipo == 2 ){
        printf("Hay una SUMA: %.2f + %s: %.2f = %.2f\n", elem1.dval, elem2.sval, elem2.dval, elem1.dval+elem2.dval); 
    } else if(elem1.tipo == 2 && elem2.tipo == 2 ){
        printf("Hay una SUMA: %s: %.2f + %s: %.2f = %.2f\n", elem1.sval, elem1.dval, elem2.sval, elem2.dval, elem1.dval+elem2.dval); 
    } else printf("Los elementos en la linea: %d no son operables \n", yylineno);

    return;
}
