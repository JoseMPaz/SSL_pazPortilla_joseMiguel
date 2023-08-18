#include "lista_reales.h"

/*Funcion: obtener_parte_entera
Precondicion: La cadena que es pasada como argumento, debe representar un numero real decimal.
PostCondiciones: Ninguna.
Accion: 	Esta funcion conviente un numero real pasado en forma de cadena a un numero entero
			que representa la parte entera del numero real. Para ello utiliza la funcion strtol que espera
			una cadena que contenga un numero real decimal, como segundo argumento recibe
			un puntero doble a caracter que sirve para identificar en caso que la cadena no sea un numero
			el primer caracter que hace que no lo sea, en este caso se le asigna NULL ya que se supone que 
			la cadena si es un numero y como ultimo argumento se le asigna la base del numero, en este caso
			por ser un numero decimal entonces su base es 10.
			Por ultimo se castea a int, ya que esta funcion devuelve un long int.
			Ejm: Si se le pasa "-23.56", entonces devuelve -23*/
int obtener_parte_entera (char cadena[])
{
	return (int) strtol (cadena,NULL,10);
}

/*Funcion: obtener_mantisa
Precondicion: La cadena que es pasada como argumento, debe representar un numero real decimal.
PostCondiciones: Ninguna.
Accion: 	Esta funcion conviente un numero real pasado en forma de cadena a un numero flotante
			que representa la mantisa del numero real. Para ello utiliza la funcion strtod que espera
			una cadena que contenga un numero real decimal, como segundo argumento recibe
			un puntero doble a caracter que sirve para identificar en caso que la cadena no sea un numero
			el primer caracter que hace que no lo sea. Esto representa el numero real completo, asi que 
			se le resta la parte entera de este numero. Ademas como la mantisa es positiva se le multiplica por -1
			en caso que resulte la mantisa de un numero negativo.
			Por ultimo se castea a float, que que esa resta de un double y un int es un double
			Ejm: Si se le pasa "-23.56", entonces devuelve 0.56*/
float obtener_mantisa (char cadena[])
{
	float mantisa = (float) strtod(cadena,NULL) - obtener_parte_entera(cadena);
	//Antes de retornar la mantesa, verifica que sea positiva, caso contrario retorna la mantisa multiplicado por -1
	return (mantisa >= 0) ? mantisa : (-1)*mantisa;
}

/*Funcion: agregar_reales_al_final_con_repeticion
Precondicion: Si la lista esta vacia, antes de utilizar esta funcion se le debe asignar NULL
PostCondiciones: Ninguna.
Accion: 	Recibe una direccion del primer nodo de una lista y el elemento que sea agregado
			Entonces esta funcion crea un nodo auxiliar, agrega el elemento que sera agregado al info de este nodo nuevo_nodo
			nuevo y asigna NULL a la parte sig. Verifica si la lista esta vacio, en caso afirmativo asigna el nodo a la lista,
			caso contrario asigna la lista a un nodo auxilia para no perder la referencia y recorre la lista hasta el ultimo nodo,
			una vez ahi asigna a su sig que apunte al nuevo nodo.*/
void agregar_reales_al_final_con_repeticion (nodo_real_t ** lista, real_t real)
{
	nodo_real_t * ultimo_nodo, * nuevo_nodo;
	
	//Pide memoria para el nodo nuevo
	nuevo_nodo = (nodo_real_t *) malloc (sizeof(nodo_real_t));
	//Agrega el dato a info del nodo nuevo
	nuevo_nodo->info = real;
	//Agrega NULL al sig del nodo nuevo
	nuevo_nodo->sig = NULL;
	
	//Verifica si la lista viene vacia
	if(*lista == NULL)
	{
		//Asigna el nuevo nodo a la lista, ya que esta vacia
		*lista = nuevo_nodo;
	}
	else//La lista no esta vacia
	{
		//Recorre hasta el ultimo nodo de la lista, y no hace nada mientras recorre
		for (ultimo_nodo = *lista; ultimo_nodo->sig != NULL; ultimo_nodo = ultimo_nodo->sig)
			; 
		//Agrega el nuevo nodo al sig del ultimo nodo de la lista
		ultimo_nodo->sig = nuevo_nodo;
	}
	return;
}

void imprimir_reales (nodo_real_t * lista)
{
	nodo_real_t * temporal;

	 //Muestra por terminal el inicio de las constantes reales
	printf ("\n%-20s%-20s%s\n", "############### ", "CONSTANTES REALES"," ###############");

//Recorre toda la lista de reales y va mostrando su parte entera y su mantisa
	for (temporal = lista; temporal != NULL; temporal = temporal->sig)
		 printf ("%s%-20d%s%.3g\n","Parte Entera: ",temporal->info.parte_entera,"Mantisa: ", temporal->info.mantisa);
	
	return;
}

void eliminar_lista_reales (nodo_real_t * lista)
{
	nodo_real_t * nodo_actual = lista, * nodo_siguiente = NULL;

//Recorre toda la lista y va eliminado cada nodos desde el primero hasta el ultimo, utilizando un puntero auxiliar para no   perder las referencia
	while (nodo_actual != NULL)
	{
		nodo_siguiente = nodo_actual->sig;
		free(nodo_actual);
		nodo_actual = nodo_siguiente;	
	}
	return;
}

