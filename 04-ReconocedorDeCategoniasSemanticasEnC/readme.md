#parser.y

#Parametros:

No Terminal: declarador_directo, Produccion: declarador_directo '(' ')'	 
	para funciones que no tenga nada como parametro

No Terminal: declaracion_de_parametro, Produccion: especificadores_de_declaracion declarador
	Para funciones que tengan el tipo de dato y un nombre de parametro
	
No terminal: declaracion_de_parametro, Produccion: especificadores_de_declaracion
	Para funciones que unicamente tengan definido el tipo de dato
	
#Declaracion de Variable o Funcion

No terminal: declaracion, Produccion: especificadores_de_declaracion lista_de_declaradores_inicial ';'
	Para el tipo de dato de declaraciones(variables o funciones)

No terminal: declarador_inicial, Produccion: declarador
	Para el identificador(variable o funcion)
	
No terminal: declarador_inicial, Produccion: declarador operador_de_asignacion inicializador
	para identificador de variables ya que permite asignarles valores

#Definicion de funciones

No terminal: definicion_de_funcion, Produccion: especificadores_de_declaracion declarador sentencia_compuesta
	Para definir funciones con el tipo de dato que devuelven

#Llamada a Funcion

No terminal: expresion_posfija, Produccion: expresion_posfija '(' lista_de_expresiones_de_argumentos ')'
	Para detectar el nombre de una funcion que es llamada para que sea analizada en la tabla_de_simbolos 
	
No terminal: lista_de_expresiones_de_argumentos, Produccion: expresion_de_asignacion
	Para detectar el primer argumento en la llamada a funcion_t
	
No terminal: lista_de_expresiones_de_argumentos, Produccion: lista_de_expresiones_de_argumentos ',' expresion_de_asignacion
	Para detectar el segundo, tercer, ... argumento en la llamada a funcion en caso que lo hubiera
	
