# Archivos Fuente
SRCS = escaner.l lista_reales.c lista_enteros.c lista_cadena_entero.c

# Archivos Objetos: Generados por el compilador durante la compilacion
OBJS = lex.yy.o lista_reales.o lista_enteros.o lista_cadena_entero.o

# Obciones de compilacion
LEX = flex
CC = gcc
CFLAGS = -g

# Nombre del Ejecutable
TARGET = tp2.exe

# Todas las acciones que realiza cuando se invoca con "make"
all: $(TARGET) clean

# Enlazado de Objetos
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lfl
	
# Genera los Objetos
lista_cadena_entero.o: lista_cadena_entero.c lista_cadena_entero.h
	$(CC) $(CFLAGS) -o lista_cadena_entero.o -c lista_cadena_entero.c
lista_enteros.o: lista_enteros.c lista_enteros.h
	$(CC) $(CFLAGS) -o lista_enteros.o -c lista_enteros.c
lista_reales.o: lista_reales.c lista_reales.h
	$(CC) $(CFLAGS) -o lista_reales.o -c lista_reales.c
lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -o lex.yy.o -c lex.yy.c
lex.yy.c: escaner.l
	$(LEX) escaner.l

#Elimina los archivos objetos y el archivo lex.yy.c que solo se utilizaron para obtener el ejecutable
clean:
		rm *.o lex.yy.c
.PHONY: clean
	


