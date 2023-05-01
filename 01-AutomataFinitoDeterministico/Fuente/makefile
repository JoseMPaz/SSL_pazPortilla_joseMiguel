CC = g++
CFLAGS = -ansi -pedantic -Wall -O2
all: tp1_linux tp1_windows.exe
tp1_linux: main.o validacion.o afd.o
	$(CC) $(CFLAGS) -o tp1_linux main.o validacion.o afd.o
tp1_windows.exe: main.o validacion.o afd.o
	$(CC) $(CFLAGS) -o tp1_windows.exe main.o validacion.o afd.o
main.o: main.c
	$(CC) $(CFLAGS) -o main.o -c main.c
validacion.o: validacion.c validacion.h
	$(CC) $(CFLAGS) -o validacion.o -c validacion.c
afd.o: afd.c afd.h
	$(CC) $(CFLAGS) -o afd.o -c afd.c
.PHONY:clean
clean:
	rm *.o
