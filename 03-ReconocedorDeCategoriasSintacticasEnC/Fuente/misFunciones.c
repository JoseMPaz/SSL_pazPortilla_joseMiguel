#include "misFunciones.h"


// AGREGO LA CADENA A LA LISTA AL FINAL, PASO POR PARAMETROS LA LISTA Y EL DATO A AGREGAR 
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


// AGREGO LA CADENA A LISTA Y VEO SI TIENE CARECTERES NO RECONOCIDOS 
void agregar_cadena_entero_al_final_con_repeticion_y_bandera (nodo_cadena_entero_t ** lista, cadena_entero_t cadena_entero, 
																					bool_t * hay_un_caracter_no_reconocido)
{
	nodo_cadena_entero_t * nuevo_nodo, * ultimo_nodo;
	

	// REVISO SI ESTA VACIA
	if(*lista == NULL)
	{
		nuevo_nodo = (nodo_cadena_entero_t *) malloc (sizeof(nodo_cadena_entero_t));
		nuevo_nodo->info = cadena_entero;
		nuevo_nodo->sig = NULL;
		*lista = nuevo_nodo;
	}
	else
	{	// SI NO ESTA VACIA REVISO SI CARACTER ANTERIOR ES NO RECONCIDO Y LO CONCATENO CON EL CARACTER DEL NODO SGTE
		if (*hay_un_caracter_no_reconocido == TRUE)
		{
			for (ultimo_nodo = *lista; ultimo_nodo->sig != NULL; ultimo_nodo = ultimo_nodo->sig)
				; 
			strcat (ultimo_nodo->info.cadena,cadena_entero.cadena);
		}
		else //  SI ES RECONOCIDO SIMPLEMENTE LO AGREGO AL FINAL DE LA LISTA 
		{
			nuevo_nodo = (nodo_cadena_entero_t *) malloc (sizeof(nodo_cadena_entero_t));
			nuevo_nodo->info = cadena_entero;
			nuevo_nodo->sig = NULL;
			for (ultimo_nodo = *lista; ultimo_nodo->sig != NULL; ultimo_nodo = ultimo_nodo->sig)
				; 
			ultimo_nodo->sig = nuevo_nodo;
		}
	}
	return;
}


// IMPRIMO TODA LA LISTA CON SU INFO, PARA ESO LA RECORRO 
void imprimir_cadena_entero (nodo_cadena_entero_t * lista, char etiqueta_cadena[], char etiqueta_entero[], char cabecera[])
{
	nodo_cadena_entero_t * temporal;
	
	printf ("\n%-20s%-20s%s\n", "############### ", cabecera," ###############");
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		 printf ("%s%-20s\t%-3s%d\n",etiqueta_cadena ,temporal->info.cadena, etiqueta_entero, temporal->info.entero);
	
	return;
}


//TAMBIEN LE PASO LA LISTA,  PARA ESTE CASO HAGO USO DEL ENUM CATEGORIA, EN DONDE CADA VALOR CORRESPONDE
// A UNA POSICION EN UNA LISTA QUE INDICA LA CATEGORIA , USO EL INFO.ENTERO
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


// MISMA LOGICA QUE ANTERIOR FUNCION SOLO QUE ACA LA POSICION MARCA SI ES UN COMENTARIO DE UNA LINEA
// O DE MUCHAS LINEAS , USO EL INFO.ENTERO
void imprimir_comentarios (nodo_cadena_entero_t * lista)
{
	nodo_cadena_entero_t * temporal;
		char * categorias[] = {"Comentario de una Linea","Comentario Multilineas"};
	
	printf ("\n%-20s%-20s%s\n", "############### ", "COMENTARIOS"," ###############");
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		 printf ("%s%-35s\n%s%s\n","Comentario: " ,temporal->info.cadena, "Tipo: ", categorias[(int)temporal->info.entero]);
	
	return;
}


// ELIMINO LA LISTA PARA LIBERAR MEMORIA, USO 2 PUNTEROS AUX
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


// BUSCO SI EXISTE LA CADENA EN LA LISTA Y ME RETORNA EL NODO DONDE LO ENCUENTRA, CASO CONTRARIO RETORNA NULL
nodo_cadena_entero_t * buscar (nodo_cadena_entero_t * lista, cadena_entero_t cadena_entero)
{
	nodo_cadena_entero_t * temporal;
	
	for (temporal = lista; temporal != NULL && strcmp(temporal->info.cadena,cadena_entero.cadena) != 0; temporal = temporal->sig)
		;	
	return temporal;
}


// RECORRE LA LISTA BUSCANDO UNA COINCIDENCIA CON LA CADENA PASADA, SI LA NO HAY COINCIDENCIA LO AGREGA AL FINAL DE LA LISTA
// CASO CONTRARIO Y ENCUENTRA QUE SE REPITE EJECUTA UNA ACCION QUE SE PASA TAMBIEN POR REFERENCIA
void agregar_cadena_entero_sin_repeticion (nodo_cadena_entero_t ** lista, cadena_entero_t cadena_entero, void (*accion)(nodo_cadena_entero_t * aux))
{
	nodo_cadena_entero_t * temporal = buscar (*lista,cadena_entero);
	
	if (temporal == NULL)
		agregar_cadena_entero_al_final_con_repeticion (lista,cadena_entero);
	else
		(*accion)(temporal);

	return;
}

// COMPARA 2 STRUCTUS Y DEVUELVO LA RESTA DE SUS ENTEROS (PARECIDO AL STRING COMPARE)
// POSITIVO SI EL PRIMERO ES MAYOR, NEGATIVO SI LO ES EL SEGUNDO, Y 0 SI SON IGUALES
int criterio_longitud (cadena_entero_t dato1, cadena_entero_t dato2)
{
	return dato1.entero - dato2.entero;
}

// USO DE LA FUNCION STRCMP 
int criterio_alfabetico(cadena_entero_t dato1, cadena_entero_t dato2)
{
	return strcmp_insensible (dato1.cadena,dato2.cadena);
}

// UNA FUNCION QUE PUEDE SER UNA ACCION Y QUE SE USA EN LA FUNCION "AGREGAR SIN REPETICION"
void agregar_uno_a_entero (nodo_cadena_entero_t * nodo)
{
	nodo->info.entero = nodo->info.entero + 1;
	return;
}
// UNA FUNCION QUE PUEDE SER UNA ACCION Y QUE SE USA EN LA FUNCION "AGREGAR SIN REPETICION"
void desechar (nodo_cadena_entero_t * nodo)
{
	return;
}

//YA SE SUPONE QUE LA LISTA ESTA ORDENADA
// ESTA FUNCION AGREGA UNA NUEVA CADENA A LA LISTA DE FORMA ORDENADA
// PUEDE SER AL INICIO, AL FINAL O EN EL MEDIO DE LA LISTA
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


//MISMA SITUACION QUE LA FUNCION ANTERIOR SOLO QUE ANTES DE AGREGAR CUALQUIER CADENA A LA LISTA
// SE VERIFICA QUE NO ESTE REPETIDA, SI NO LO ESTA, SE AGREGA EN LA LISTA
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



// FUNCION QUE RETORNA SI LA LONGITUD DE UNA CADENA ES MAYOR A OTRA
//RECIBE 2 LISTAS DE CADENAS, LAS PASA A MINUSCULA Y LAS RECORRE HASTA ACABAR 1 O AMBAS PARA DESPUES COMPARAR LONGITUD
int strcmp_insensible (const char *s1, const char *s2) 
{
	while (*s1 != '\0' && *s2 != '\0') 
   {
		int diff = tolower(*s1) - tolower(*s2);
		if (diff != 0) 
      {
			return (diff > 0) ? 1 : -1;
      }
      s1++;
      s2++;
	}
    
	if (*s1 == *s2) 
	{
		return 0;
	}
    
	return (*s1 > *s2) ? 1 : -1;

}


