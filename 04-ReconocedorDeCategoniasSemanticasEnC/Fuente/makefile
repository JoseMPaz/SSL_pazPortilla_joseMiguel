# Definición de variables
CC = gcc
CFLAGS = -g 
LEX = flex
YACC = bison 

# Archivos fuente y objeto
SOURCES = scanner.l parser.y lista_cadena_entero.c
HEADERS = lista_cadena_entero.h
OBJECTS = lex.yy.c parser.tab.c lista_cadena_entero.o


# Nombre del ejecutable
TARGET = tpi.exe 

all: $(TARGET) clean

# Regla principal para la construcción del ejecutable
$(TARGET): $(OBJECTS) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) -lm

# Regla para generar el archivo lex.yy.c a partir de scanner.l
lex.yy.c: scanner.l parser.tab.h
	$(LEX) scanner.l

# Regla para generar el archivo parser.tab.c y parser.tab.h a partir de parser.y
parser.tab.c parser.tab.h: parser.y
	$(YACC) -d -v parser.y

# Regla para compilar el archivo de funciones
lista_cadena_entero.o: lista_cadena_entero.c $(HEADERS)
	$(CC) $(CFLAGS) -c lista_cadena_entero.c

# Limpieza de archivos generados
clean:
	rm -f $(OBJECTS) lex.yy.c parser.tab.c parser.tab.h *.output

# Regla phony para que "clean" no sea confundido con un archivo llamado "clean"
.PHONY: clean
