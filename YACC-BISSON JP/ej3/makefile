# Definición de variables
CC = gcc
CFLAGS = -g 
LEX = flex
YACC = bison 

# Archivos fuente y objeto
SOURCES = scanner.l parser.y misFunciones.c
HEADERS = misFunciones.h
OBJECTS = lex.yy.c parser.tab.c misFunciones.o

# Nombre del ejecutable
TARGET = ej3.exe

# Regla principal para la construcción del ejecutable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) -lm

# Regla para generar el archivo lex.yy.c a partir de scanner.l
lex.yy.c: scanner.l parser.tab.h
	$(LEX) scanner.l

# Regla para generar el archivo parser.tab.c y parser.tab.h a partir de parser.y
parser.tab.c parser.tab.h: parser.y
	$(YACC) -d parser.y

# Regla para compilar el archivo de funciones
misFunciones.o: misFunciones.c $(HEADERS)
	$(CC) $(CFLAGS) -c misFunciones.c

# Limpieza de archivos generados
clean:
	rm -f $(TARGET) $(OBJECTS) lex.yy.c parser.tab.c parser.tab.h

# Regla phony para que "clean" no sea confundido con un archivo llamado "clean"
.PHONY: clean
