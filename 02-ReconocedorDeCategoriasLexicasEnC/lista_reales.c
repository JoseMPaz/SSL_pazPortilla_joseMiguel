#include "lista_reales.h"

int obtener_parte_entera (char cadena[])
{
	return (int) strtod(cadena,NULL);
}

float obtener_mantisa (char cadena[])
{
	return (float) strtod(cadena,NULL) - (int) strtod(cadena,NULL);
}

void imprimir_reales (nodo_real_t * lista)
{
	nodo_real_t * temporal;
	
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		 printf ("%s%-20d%s%.3g\n","La parte entera es: ",temporal->info.parte_entera,"La mantisa es: ", temporal->info.mantisa);
	
	return;
}

void agregar_reales_al_final_con_repeticion (nodo_real_t ** lista, real_t real)
{
	nodo_real_t * ultimo_nodo, * nuevo_nodo;
	
	nuevo_nodo = (nodo_real_t *) malloc (sizeof(nodo_real_t));
	nuevo_nodo->info = real;
	nuevo_nodo->sig = NULL;
	
	if(*lista == NULL)
	{
		*lista = nuevo_nodo;
	}
	else
	{
		for (ultimo_nodo = *lista; ultimo_nodo->sig != NULL; ultimo_nodo = ultimo_nodo->sig)
			; 
		ultimo_nodo->sig = nuevo_nodo;
	}
	return;
}

void eliminar_lista_reales (nodo_real_t * lista)
{
	nodo_real_t * nodo_actual = lista, * nodo_siguiente = NULL;

	while (nodo_actual != NULL)
	{
		nodo_siguiente = nodo_actual->sig;
		free(nodo_actual);
		nodo_actual = nodo_siguiente;	
	}
	return;
}
