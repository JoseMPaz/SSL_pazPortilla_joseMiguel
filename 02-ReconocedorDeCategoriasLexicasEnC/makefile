TARGET = tp2
CC = gcc
CFLAGS = -g
SRCS = escaner.l mis_funciones.c
HEADERS = mis_funciones.h
OBJS = $(SRCS:.c=.o) lex.yy.o
all: tp2
$(TARGET):lex.yy.o mis_funciones.o
	$(CC) $(CFLAGS) -o tp2 lex.yy.o mis_funciones.o
mis_funciones.o: mis_funciones.c mis_funciones.h
	$(CC) $(CFLAGS) -o mis_funciones.o -c mis_funciones.c
lex.yy.o: lex.yy.c mis_funciones.h
	$(CC) $(CFLAGS) -o lex.yy.o -c lex.yy.c
lex.yy.c: escaner.l
	flex escaner.l
.PHONY:clean
clean:
	rm *.o


