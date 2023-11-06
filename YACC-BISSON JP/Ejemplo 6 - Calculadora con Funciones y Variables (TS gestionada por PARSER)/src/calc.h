#ifndef CALC_H
#define CALC_H

#define TYP_VAR 0
#define TYP_FNCT 1

//Definición de un tipo de dato denominado func_t que es de tipo puntero a función

typedef double (*puntero_a_funcion_t) (double);

//Definición de la estructura de los nodos de la TS, la denominamos symrec.

typedef struct simbolo_t
{
  char * nombre;
  int tipo; //Tenemos dos tipos: Variable (TYP_VAR) o Función (TYP_FNCT)
  union
  {
    double variable; //Si es una variable, se guarda su valor    
    puntero_a_funcion_t puntero_a_funcion; //Si es una función, se almacena un puntero a una función
  } valor;
  struct simbolo_t * next; //Puntero al siguiente nodo de la lista
}simbolo_t;

//Declaración de la variable sym_table que apunta a la TS
//Se utiliza para exponer variables pertenecientes a un archivo a uno o varios archivos adicionales. 

extern simbolo_t * tabla_de_simbolos;

//Declaración de la función putsym para agregar símbolo a la TS

simbolo_t * establecer_simbolo (char const *, int);

//Declaración de la función getsym para tomar un símbolo de la TS

simbolo_t * obtener_simbolo (char const *);
#endif
