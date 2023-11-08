# Definición de variables
CC = gcc
CFLAGS = -g 
LEX = flex
YACC = bison 

# Archivos fuente y objeto
SOURCES = scanner.l parser.y errores_lexicos.c variables.c funciones.c parametros.c
OBJECTS = lex.yy.c parser.tab.c errores_lexicos.o variables.o funciones.o parametros.o


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
errores_lexicos.o: errores_lexicos.c errores_lexicos.h
	$(CC) $(CFLAGS) -c errores_lexicos.c
	
variables.o: variables.c variables.h
	$(CC) $(CFLAGS) -c variables.c
	
funciones.o: funciones.c funciones.h
	$(CC) $(CFLAGS) -c funciones.c
	
parametros.o: parametros.c parametros.h
	$(CC) $(CFLAGS) -c parametros.c

# Limpieza de archivos generados
clean:
	rm -f $(OBJECTS) lex.yy.c parser.tab.c parser.tab.h *.output

# Regla phony para que "clean" no sea confundido con un archivo llamado "clean"
.PHONY: clean
