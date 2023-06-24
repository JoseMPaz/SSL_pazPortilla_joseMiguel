#Makefile: Permite no compilar todos los archivos fuente si solo se modifican algunos de ello
#Ademas se puede ver las dependencias de bibliotecas entre los fuentes

#Etiqueto a CC con el nombre del compilador, es decir gcc
CC = gcc

#Etiqueto a CFLAGS con algunas bandera utiles como 
#-ansi para validar que se este compilando segun su estandar
#-pedantic hace que las validaciones sean rigurosas
#-02 optimiza la compilacion
#-Wall o Warning all muestra todas las advertencias que se establecio con los otras banderas
CFLAGS = -ansi -pedantic -O2 -Wall

#Esto permite decirle que se ejecuten todas las instrucciones del makefile
#para ello se debe escribir make all en lugar se solo makefile
all: tp1

#Indica los objetos a enlazar
tp1: main.o validacion.o afd.o
	$(CC) $(CFLAGS) -o tp1 main.o validacion.o afd.o

#Creacion del archivo objeto de main
main.o: main.c
	$(CC) $(CFLAGS) -o main.o -c main.c
	
#Creacion del archivo objeto de validacion
validacion.o: validacion.c validacion.h idioma.h
	$(CC) $(CFLAGS) -o validacion.o -c validacion.c
	
#Creacion del archivo objeto de adf
afd.o: afd.c afd.h idioma.h
	$(CC) $(CFLAGS) -o afd.o -c afd.c

#Esto permite ejecutar la instruccion make clean remover todos los archivos .o
#Para ello se debe escribir make clean
.PHONY:clean
clean:
	rm *.o
