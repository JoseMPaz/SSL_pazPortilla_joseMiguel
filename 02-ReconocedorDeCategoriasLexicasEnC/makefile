TARGET = tp2.exe
CC = gcc
CFLAGS = -g
all: tp2.exe
$(TARGET):lex.yy.o lista.o palabra_entero.o
	$(CC) $(CFLAGS) -o tp2.exe lex.yy.o lista.o palabra_entero.o
palabra_entero.o: palabra_entero.c palabra_entero.h
	$(CC) $(CFLAGS) -o palabra_entero.o -c palabra_entero.c
lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -o lista.o -c lista.c
lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -o lex.yy.o -c lex.yy.c
lex.yy.c: escaner.l
	flex escaner.l
.PHONY:clean
clean:
	rm *.o


