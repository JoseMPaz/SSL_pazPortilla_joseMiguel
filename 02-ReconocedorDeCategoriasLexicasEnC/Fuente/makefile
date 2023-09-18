# Archivos Fuente
SRCS = escaner.l lista_reales.c lista_enteros.c lista_cadena_entero.c validacion.c

# Archivos Objetos: Generados por el compilador durante la compilacion
OBJS = lex.yy.o lista_reales.o lista_enteros.o lista_cadena_entero.o validacion.o

# Opciones de compilacion
LEX = flex
CC = gcc
CFLAGS = -g

# Nombre del Ejecutable
TARGET = tp2.exe

# Todas las acciones que realiza cuando se invoca con "make" en este caso crear el ejecutable y 
#eliminar los archivos objetos junto al archivo intermedio lex.yy.c
all: $(TARGET) clean

# Enlazado de Objetos
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lfl
	
# Genera los Objetos
#Creacion de lista_cadena_entero.o
lista_cadena_entero.o: lista_cadena_entero.c lista_cadena_entero.h
	$(CC) $(CFLAGS) -o lista_cadena_entero.o -c lista_cadena_entero.c
# Creacion de lista_enteros.o
lista_enteros.o: lista_enteros.c lista_enteros.h
	$(CC) $(CFLAGS) -o lista_enteros.o -c lista_enteros.c
# Creacion de lista_reales.o
lista_reales.o: lista_reales.c lista_reales.h
	$(CC) $(CFLAGS) -o lista_reales.o -c lista_reales.c
validacion.o: validacion.c validacion.h
	$(CC) $(CFLAGS) -o validacion.o -c validacion.c
# Creacion de lex.yy.o
lex.yy.o: lex.yy.c lista_reales.h lista_enteros.h lista_cadena_entero.h validacion.h
	$(CC) $(CFLAGS) -o lex.yy.o -c lex.yy.c
	
#A partir de las reglar definidas en escaner.l, el programa flex crea un archivo lex.yy.c 
#que contendra las funciones para realizar el análisis lexico del archivo.c
lex.yy.c: escaner.l
	flex escaner.l

#Elimina los archivos objetos y el archivo lex.yy.c que solo se utilizaron para obtener el ejecutable
clean:
		rm *.o lex.yy.c
.PHONY: clean
	


