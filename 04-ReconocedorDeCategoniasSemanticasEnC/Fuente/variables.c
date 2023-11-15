#include "variables.h"

void agregar_variable_al_final (nodo_variable_t ** variables, variable_t variable)
{
	nodo_variable_t * nuevo_nodo, * ultimo_nodo;
	
	nuevo_nodo = (nodo_variable_t *) malloc (sizeof(nodo_variable_t));
	nuevo_nodo->info = variable;
	nuevo_nodo->sig = NULL;
	
	if(*variables == NULL)//Si la lista esta vacia
	{
		*variables = nuevo_nodo;
	}
	else
	{
		//Se recorre la lista hasta el utimo nodo
		for (ultimo_nodo = *variables; ultimo_nodo->sig != NULL; ultimo_nodo = ultimo_nodo->sig)
			; 
		ultimo_nodo->sig = nuevo_nodo;//El ultimo nodo apunta al nuevo nodo
	}
	return;
}

void imprimir_variables (nodo_variable_t * variables)
{
	nodo_variable_t * temporal;
	
	printf ("\n%-20s%-20s%s\n\n", "############### ", "VARIABLES", " ###############");
	
	for (temporal = variables; temporal != NULL; temporal = temporal->sig)
		printf ("%s%-10s\t%-3s%-10s\t%-3s%s\n",	"Nombre de variable: " ,temporal->info.nombre_variable, "Tipo dato de variable: ", 
														temporal->info.tipo_dato, "Ambito: ", temporal->info.ambito);	
	
	return;
}

void eliminar_variables (nodo_variable_t * valiables)
{
	nodo_variable_t * nodo_actual = valiables, * nodo_siguiente = NULL;

	while (nodo_actual != NULL)
	{
		nodo_siguiente = nodo_actual->sig;
		free(nodo_actual);
		nodo_actual = nodo_siguiente;	
	}
	
	return;
}

nodo_variable_t * buscar_variable (nodo_variable_t * variables, char nombre_variable[])
{
	nodo_variable_t * temporal = variables;
	
	//recorre la lista hasta el final, pero si el nombre de la variable ya fue agregada deja de recorrer
	for(	;temporal != NULL && strcmp ( temporal->info.nombre_variable,nombre_variable) != 0/*Son distintos*/; temporal = temporal->sig)
		;	
		
	if (temporal != NULL)
		return temporal;
		
	return NULL;
}


