#include "lista.h"
#include "palabra_entero.h"
#include "entero.h"
#include "real.h"
#include "caracter.h"

int main (void)
{
	nodo_t * lista = NULL;
	void (*pf_imprimir) (void * info);
	palabra_entero_t * palabra_reservada;
	
	crear_palabra_entero(&palabra_reservada,"void",(int)TIPO_DE_DATO);
	agregar_al_final(&lista,palabra_reservada);
	crear_palabra_entero(&palabra_reservada,"for",(int)ESTRUCTURA_DE_CONTROL);
	agregar_al_final(&lista,palabra_reservada);
	crear_palabra_entero(&palabra_reservada,"include",(int)DIRECTIVA_DE_PREPROCESAMIENTO);
	agregar_al_final(&lista,palabra_reservada);
	
	pf_imprimir = imprimir_palabra_reservada;
	imprimir (lista, pf_imprimir);
	
	eliminar (lista);
	return 0;
}
