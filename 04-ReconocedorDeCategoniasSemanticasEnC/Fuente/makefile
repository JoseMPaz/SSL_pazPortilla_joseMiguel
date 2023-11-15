# Definición de variables
CC = gcc
CFLAGS = -g 
LEX = flex
YACC = bison 

# Archivos fuente y objeto
SOURCES = scanner.l parser.y errores.c variables.c funciones.c parametros.c identificador.c operaciones.c
OBJECTS = lex.yy.c parser.tab.c errores.o variables.o funciones.o parametros.o identificador.o operaciones.o


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
errores.o: errores.c errores.h
	$(CC) $(CFLAGS) -c errores.c
	
variables.o: variables.c variables.h
	$(CC) $(CFLAGS) -c variables.c
	
funciones.o: funciones.c funciones.h
	$(CC) $(CFLAGS) -c funciones.c
	
parametros.o: parametros.c parametros.h
	$(CC) $(CFLAGS) -c parametros.c

identificador.o: identificador.c identificador.h
	$(CC) $(CFLAGS) -c identificador.c

operaciones.o: operaciones.c operaciones.h
	$(CC) $(CFLAGS) -c operaciones.c
	
# Limpieza de archivos generados
clean:
	rm -f $(OBJECTS) lex.yy.c parser.tab.c parser.tab.h *.output

# Regla phony para que "clean" no sea confundido con un archivo llamado "clean"
.PHONY: clean
