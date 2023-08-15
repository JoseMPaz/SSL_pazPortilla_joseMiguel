TARGET = tp2.exe
CC = gcc
CFLAGS = -g
all: tp2.exe
$(TARGET):lex.yy.o lista_cadena_entero.o lista_enteros.o lista_reales.o
	$(CC) $(CFLAGS) -o tp2.exe lex.yy.o lista_cadena_entero.o lista_enteros.o lista_reales.o
lista_cadena_entero.o: lista_cadena_entero.c lista_cadena_entero.h
	$(CC) $(CFLAGS) -o lista_cadena_entero.o -c lista_cadena_entero.c
lista_enteros.o: lista_enteros.c lista_enteros.h
	$(CC) $(CFLAGS) -o lista_enteros.o -c lista_enteros.c
lista_reales.o: lista_reales.c lista_reales.h
	$(CC) $(CFLAGS) -o lista_reales.o -c lista_reales.c
lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -o lex.yy.o -c lex.yy.c
lex.yy.c: escaner.l
	flex escaner.l
.PHONY:clean
clean:
	rm *.o


