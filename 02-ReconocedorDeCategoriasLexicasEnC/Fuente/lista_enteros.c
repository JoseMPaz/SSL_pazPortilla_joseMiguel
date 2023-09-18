#include "lista_enteros.h"

/*Precondicion: Las listas vacias deben apuntar a NULL e informacion debe tener sus campos completos
Agrega un nuevo nodo con su informacion al final de la lista de enteros. */
void agregar_enteros_al_final_con_repeticion (nodo_enteros_t ** lista, int informacion)
{
	nodo_enteros_t * ultimo_nodo;
	nodo_enteros_t * nuevo_nodo;
	
	// Pide memoria para el nuevo nodo
	nuevo_nodo = (nodo_enteros_t *) malloc (sizeof(nodo_enteros_t));
	// Agrega la informacion a info en el nuevo nodo
	nuevo_nodo->info = informacion;
	// Apunta a NULL para el siguiente nodo
	nuevo_nodo->sig = NULL;
	
	// Verifica si la lista esta vacia
	if(*lista == NULL)
	{ 	// La lista esta vacia
		// Asigna el nuevo nodo a la lista
		*lista = nuevo_nodo;
	}
	else 
	{	// La lista no esta vacia
		// Recorre la lista hasta el final sin hacer nada
		for (ultimo_nodo = *lista; ultimo_nodo->sig != NULL; ultimo_nodo = ultimo_nodo->sig)
			; 
		// Agrega al nuevo nodo al final de la lista
		ultimo_nodo->sig = nuevo_nodo;
	}
	return;
}

/* Suma el total de los valores guardados en la info de cada nodo de la lista de enteros */
int suma_total (nodo_enteros_t * lista)
{
	nodo_enteros_t * temporal;
	int total = 0;
	// Recorre la lista sumando el valor de la info a total
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		total += temporal->info;

	return total;
}

/* Imprime en la terminal el reporte de la lista de los enteros. */
void imprimir_enteros (nodo_enteros_t * lista, char cabecera[])
{
	nodo_enteros_t * temporal;
	
	// Imprime en pantalla una cabecera para el informe, dependiendo del tipo de constante
	printf ("\n%-20s%-20s%s\n", "############### ", cabecera," ###############");
	
	// Recorre toda la lista de los enteros imprimiendo la info de cada nodo
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		printf ("%s%d\n","Numero: ", temporal->info);
	// Verifica si la cabecera es de las constantes decimales 
	if (strcmp(cabecera,"CONSTANTES DECIMALES") == 0)
		// Imprime la suma total de la info de cada nodo
		printf ("%s%d\n","La suma total es: ", suma_total(lista));
	return;
}

/* Imprime en la terminal el reporte de la lista de las constantes caracter */
void imprimir_caracteres (nodo_enteros_t * lista)
{
	nodo_enteros_t * temporal;
	// Imprime en pantalla una cabecera para el informe de las constantes caracter
	printf ("\n%-20s%-20s%s\n", "############### ", "CONSTANTES CARACTERES"," ###############");
	// Recorre toda la lista imprimiendo la info de cada nodo
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		 printf ("%s\'%c\'\n","Caracter: ",temporal->info);
	
	return;
}

/* Convierte una cadena que representa un numero entero a un entero */
int convertir_cadena_entera_a_entero (char cadena[])
{
	return (int) strtol (cadena,NULL,10);
}

/* Convierte una cadena que representa un numero octal a un entero */
int convertir_cadena_octal_a_entero (char cadena[])
{
	return (int) strtol (cadena,NULL,8);
}

/* Convierte una cadena que representa un numero hexadecimal a un entero */
int convertir_cadena_hexadecimal_a_entero (char cadena[])
{
	return (int) strtol (cadena,NULL,16);
}

/* Elimina todos los nodos de la lista */
void eliminar_lista_enteros (nodo_enteros_t * lista)
{
	nodo_enteros_t * nodo_actual = lista, * nodo_siguiente = NULL;
	
	//Recorre la lista y elimina cada nodo hasta el final
	while (nodo_actual != NULL)
	{
		nodo_siguiente = nodo_actual->sig;
		free(nodo_actual);
		nodo_actual = nodo_siguiente;	
	}
	return;
}
