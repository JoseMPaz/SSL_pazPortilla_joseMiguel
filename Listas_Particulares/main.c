#include "lista_cadena_entero.h"
#include "lista_enteros.h"
#include "lista_reales.h"

int main(void)
{
	nodo_enteros_t * lista_enteros = NULL;
	nodo_real_t * lista_reales = NULL;
	nodo_cadena_entero_t * lista_cadena_entero = NULL, * tmp, * l2 = NULL, * l3 = NULL;
	int (*criterio)(cadena_entero_t d1, cadena_entero_t d2);
	void (*accion)(nodo_cadena_entero_t * aux);
	int entero;
	float mantisa;
	real_t real;
	cadena_entero_t cadena_entero;
	
	agregar_enteros_al_final_con_repeticion (&lista_enteros,64);
	agregar_enteros_al_final_con_repeticion (&lista_enteros,'A');
	agregar_enteros_al_final_con_repeticion (&lista_enteros,66);
	agregar_enteros_al_final_con_repeticion (&lista_enteros,'C');
	agregar_enteros_al_final_con_repeticion (&lista_enteros,68);
	agregar_enteros_al_final_con_repeticion (&lista_enteros,69);
	agregar_enteros_al_final_con_repeticion (&lista_enteros,70);
	imprimir_caracteres(lista_enteros);
	entero = convertir_cadena_entera_a_entero ("-648");
	printf ("%d\n",entero);
	entero = convertir_cadena_octal_a_entero ("017");
	printf ("%d\n",entero);
	entero = convertir_cadena_hexadecimal_a_entero ("0XA");
	printf ("%d\n",entero);
	contar_enteros(lista_enteros);
	eliminar_lista_enteros(lista_enteros);
	real.parte_entera = obtener_parte_entera("25.98");
	real.mantisa = obtener_mantisa("25.98");
	agregar_reales_al_final_con_repeticion (&lista_reales,real);
	real.parte_entera = obtener_parte_entera("66.77");
	real.mantisa = obtener_mantisa("66.77");
	agregar_reales_al_final_con_repeticion (&lista_reales,real);
	imprimir_reales(lista_reales);
	eliminar_lista_reales(lista_reales);
	strcpy (cadena_entero.cadena,"void");
	cadena_entero.entero = 1;
	agregar_cadena_entero_al_final_con_repeticion (&lista_cadena_entero,cadena_entero);
	strcpy (cadena_entero.cadena,"main");
	cadena_entero.entero = 1;
	agregar_cadena_entero_al_final_con_repeticion (&lista_cadena_entero,cadena_entero);
	strcpy (cadena_entero.cadena,"double");
	cadena_entero.entero = 1;
	agregar_cadena_entero_al_final_con_repeticion (&lista_cadena_entero,cadena_entero);
	
	
	strcpy (cadena_entero.cadena,"main");
	cadena_entero.entero = 1;

	accion = agregar_uno_a_entero;
	agregar_cadena_entero_sin_repeticion (&lista_cadena_entero, cadena_entero, accion);
	
	strcpy (cadena_entero.cadena,"double");
	cadena_entero.entero = 1;
	accion = desechar;
	agregar_cadena_entero_sin_repeticion (&lista_cadena_entero, cadena_entero, accion);
	imprimir_cadena_entero(lista_cadena_entero, "Palabra Reservada: ", "Veces: ");
	eliminar_lista_cadena_entero(lista_cadena_entero);
	
	puts("AGRERO ORDENADO SIN REPETICION");
	criterio = criterio_alfabetico;
	accion = agregar_uno_a_entero;
	strcpy (cadena_entero.cadena,"main");
	cadena_entero.entero = 1;
	agregar_cadena_entero_ordenado_sin_repeticion (&l2, cadena_entero, accion, criterio);
	strcpy (cadena_entero.cadena,"char");
	cadena_entero.entero = 1;
	agregar_cadena_entero_ordenado_sin_repeticion (&l2, cadena_entero, accion, criterio);
	strcpy (cadena_entero.cadena,"void");
	cadena_entero.entero = 1;
	agregar_cadena_entero_ordenado_sin_repeticion (&l2, cadena_entero, accion, criterio);
	strcpy (cadena_entero.cadena,"void");
	cadena_entero.entero = 1;
	agregar_cadena_entero_ordenado_sin_repeticion (&l2, cadena_entero, accion, criterio);
	imprimir_cadena_entero(l2, "Palabra Reservada: ", "Veces: ");
	eliminar_lista_cadena_entero(l2);
	
	puts("AGRERO ORDENADO SIN REPETICION 2");
	criterio = criterio_longitud;
	accion = desechar;
	strcpy (cadena_entero.cadena,"main");
	cadena_entero.entero = strlen("main");
	agregar_cadena_entero_ordenado_sin_repeticion (&l3, cadena_entero, accion, criterio);
	strcpy (cadena_entero.cadena,"int");
	cadena_entero.entero = strlen("int");
	agregar_cadena_entero_ordenado_sin_repeticion (&l3, cadena_entero, accion, criterio);
	strcpy (cadena_entero.cadena,"realloc");
	cadena_entero.entero = strlen("realloc");
	agregar_cadena_entero_ordenado_sin_repeticion (&l3, cadena_entero, accion, criterio);
	strcpy (cadena_entero.cadena,"realloc");
	cadena_entero.entero = strlen("realloc");
	agregar_cadena_entero_ordenado_sin_repeticion (&l3, cadena_entero, accion, criterio);
	
	imprimir_cadena_entero(l3, "Cadena: ", "Longitud: ");
	eliminar_lista_cadena_entero(l3);
	return 0;
}
