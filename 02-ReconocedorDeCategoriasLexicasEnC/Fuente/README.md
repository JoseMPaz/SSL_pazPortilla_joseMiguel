Caracteristicas de los datos en los nodos:

Las listas implementadas son:

Lista de identificadores
Lista de literales cadena
Lista de palabras reservadas
Lista de constantes octales
Lista de constantes hecadecimales
Lista de constantes decimales
Lista de constantes reales
Lista de caracteres
Lista de operadores y caracteres de puntuacion
Lista de comentarios
Lista de palabras no reconocidas

Cada lista tiene metodos para agregar elementos, mostrar los elementos de los nodos y de eliminar la lista.

Las expresiones regulares utilizadas son:

Para identificadores: [a-zA-Z_][a-zA-Z0-9_]*
indica que debe comenzar con un caracter que es una letra (mayuscula o minuscula) o un guion bajo, a continuacion
las proximas letras pueden contener numero decimales.

Para literales cadena: \"[^\n"]*\"	
indica que inician y terminan con comillas dobles, y en su interior puede contener 
salto de linea o comillas ninguna vez o infinitas.

Para lalabras reservadas: Se las clasifico como 
TIPO DE DATO: "int"|"char"|"float"|"double"|"void"
ESTRUCTURA DE CONTROL: \#(include|define|ifndef|ifdef)(.*)|\#endif
indica que inician con #, seguido de include|define|ifndef|ifdef seguido de mas caracteres, 
o bien sin encuentra #endif

Para constantes octales: 











