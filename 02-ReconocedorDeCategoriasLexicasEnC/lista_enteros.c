#include "lista_enteros.h"

void agregar_enteros_al_final_con_repeticion (nodo_enteros_t ** lista, int informacion)
{
	nodo_enteros_t * ultimo_nodo;
	nodo_enteros_t * nuevo_nodo;
	
	nuevo_nodo = (nodo_enteros_t *) malloc (sizeof(nodo_enteros_t));
	nuevo_nodo->info = informacion;
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

int suma_total(nodo_enteros_t * lista)
{
	nodo_enteros_t * temporal;
	int total = 0;
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		total += temporal->info;

	return total;
}

void imprimir_enteros(nodo_enteros_t * lista, char cabecera[])
{
	nodo_enteros_t * temporal;
	
	printf ("\n%-20s%-20s%s\n", "############### ", cabecera," ###############");
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		printf ("%s%d\n","Numero: ", temporal->info);
	if (strcmp(cabecera,"CONSTANTES DECIMALES") == 0)
		printf ("%s%d\n","La suma total es: ", suma_total(lista));
	return;
}

void imprimir_caracteres (nodo_enteros_t * lista)
{
	nodo_enteros_t * temporal;
	
	printf ("\n%-20s%-20s%s\n", "############### ", "CONSTANTES CARACTERES"," ###############");
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		 printf ("%s%c\n","Caracter: ",temporal->info);
	
	return;
}

int convertir_cadena_entera_a_entero (char cadena[])
{
	return (int) strtol (cadena,NULL,10);
}

int convertir_cadena_octal_a_entero (char cadena[])
{
	return (int) strtol (cadena,NULL,8);
}

int convertir_cadena_hexadecimal_a_entero (char cadena[])
{
	return (int) strtol (cadena,NULL,16);
}

void contar_enteros (nodo_enteros_t * lista)
{
	nodo_enteros_t * temporal;
	int acumulador = 0;
	
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		 acumulador += temporal->info;
	
	printf ("%s%d\n","La suma de enteros es: ", acumulador);
	
	return;
}

void eliminar_lista_enteros (nodo_enteros_t * lista)
{
	nodo_enteros_t * nodo_actual = lista, * nodo_siguiente = NULL;

	while (nodo_actual != NULL)
	{
		nodo_siguiente = nodo_actual->sig;
		free(nodo_actual);
		nodo_actual = nodo_siguiente;	
	}
	return;
}


