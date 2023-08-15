#include "lista_cadena_entero.h"

void agregar_cadena_entero_al_final_con_repeticion (nodo_cadena_entero_t ** lista, cadena_entero_t cadena_entero)
{
	nodo_cadena_entero_t * nuevo_nodo, * ultimo_nodo;
	
	nuevo_nodo = (nodo_cadena_entero_t *) malloc (sizeof(nodo_cadena_entero_t));
	nuevo_nodo->info = cadena_entero;
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

void imprimir_cadena_entero (nodo_cadena_entero_t * lista, char etiqueta_cadena[], char etiqueta_entero[], char cabecera[])
{
	nodo_cadena_entero_t * temporal;
	
	printf ("\n%-20s%-20s%s\n", "############### ", cabecera," ###############");
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		 printf ("%s%-20s%s%d\n",etiqueta_cadena ,temporal->info.cadena, etiqueta_entero, temporal->info.entero);
	
	return;
}

void imprimir_palabra_reservada (nodo_cadena_entero_t * lista)
{
	nodo_cadena_entero_t * temporal;
		char * categorias[] = {"TIPO DE DATO SIMPLE", "ESTRUCTURA DE CONTROL", "DIRECTIVA DE PREPROCESAMIENTO",
									"PUNTO DE ENTRADA AL PROGRAMA", "MODIFICADOR DE ALMACENAMIENTO", "MODIFICADOR DE TIPO DE DATO",
									"MODIFICADOR DE VARIABLE NUMERICA", "TIPO DE DATO COMPUESTO"};
	
	printf ("\n%-20s%-20s%s\n", "############### ", "PALABRAS_RESERVADAS"," ###############");
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		 printf ("%s%-35s%s%s\n","Palabra Reservada: " ,temporal->info.cadena, "Tipo: ", categorias[(int)temporal->info.entero]);
	
	return;
}

void eliminar_lista_cadena_entero (nodo_cadena_entero_t * lista)
{
	nodo_cadena_entero_t * nodo_actual = lista, * nodo_siguiente = NULL;

	while (nodo_actual != NULL)
	{
		nodo_siguiente = nodo_actual->sig;
		free(nodo_actual);
		nodo_actual = nodo_siguiente;	
	}
	return;
}

nodo_cadena_entero_t * buscar (nodo_cadena_entero_t * lista, cadena_entero_t cadena_entero)
{
	nodo_cadena_entero_t * temporal;
	for (temporal = lista; temporal != NULL && strcmp(temporal->info.cadena,cadena_entero.cadena) != 0; temporal = temporal->sig)
		;	
	return temporal;
}


void agregar_cadena_entero_sin_repeticion (nodo_cadena_entero_t ** lista, cadena_entero_t cadena_entero, void (*accion)(nodo_cadena_entero_t * aux))
{
	nodo_cadena_entero_t * temporal = buscar (*lista,cadena_entero);
	
	if (temporal == NULL)
		agregar_cadena_entero_al_final_con_repeticion (lista,cadena_entero);
	else
		(*accion)(temporal);

	return;
}

int criterio_longitud (cadena_entero_t dato1, cadena_entero_t dato2)
{
	return dato1.entero - dato2.entero;
}

int criterio_alfabetico(cadena_entero_t dato1, cadena_entero_t dato2)
{
	return strcmp_insensible (dato1.cadena,dato2.cadena);
}

void agregar_uno_a_entero(nodo_cadena_entero_t * nodo)
{
	nodo->info.entero = nodo->info.entero + 1;
	return;
}

void desechar(nodo_cadena_entero_t * nodo)
{
	return;
}

void agregar_ordenado (nodo_cadena_entero_t ** lista, cadena_entero_t dato,
							int (*criterio)(cadena_entero_t dato1,cadena_entero_t dato2))
{
	nodo_cadena_entero_t * anterior = NULL, * actual = *lista;
	
	while (actual != NULL && (*criterio)(actual->info,dato) < 0)
	{
		anterior = actual;
		actual = actual->sig;
	}
	if (actual != *lista)
	{
		anterior->sig = (nodo_cadena_entero_t *) malloc (sizeof (nodo_cadena_entero_t));
		anterior->sig->info = dato;
		anterior->sig->sig = actual;
	}
	else
	{
		*lista = (nodo_cadena_entero_t *) malloc (sizeof (nodo_cadena_entero_t));
		(*lista)->info = dato;
		(*lista)->sig = actual;
	}

	return;
}

void agregar_cadena_entero_ordenado_sin_repeticion (nodo_cadena_entero_t ** lista, cadena_entero_t cadena_entero, 
																	void (*accion)(nodo_cadena_entero_t * aux), 
																	int (*criterio)(cadena_entero_t dato1,cadena_entero_t dato2))
{
	nodo_cadena_entero_t * temporal = buscar (*lista,cadena_entero);
	
	if (temporal == NULL)
		agregar_ordenado (lista,cadena_entero,criterio);
	else
		(*accion)(temporal);

	return;
}

int strcmp_insensible (const char *s1, const char *s2) 
{
    while (*s1 != '\0' && *s2 != '\0') {
        int diff = tolower(*s1) - tolower(*s2);
        if (diff != 0) {
            return (diff > 0) ? 1 : -1;
        }
        s1++;
        s2++;
    }
    
    if (*s1 == *s2) {
        return 0;
    } else {
        return (*s1 > *s2) ? 1 : -1;
    }
}

