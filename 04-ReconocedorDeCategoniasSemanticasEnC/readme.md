#parser.y

#Parametros: No terminales utilizados

declarador_directo: Produccion <declarador_directo '(' ')'	>
	para funciones que no tenga nada como argumento

declaracion_de_parametro: Produccion <especificadores_de_declaracion declarador>
	Para funciones que tengan el tipo de dato y su parametro_t
	
declaracion_de_parametro: Produccion <especificadores_de_declaracion>
	Para funciones que solo tengan definido el tipo de dato 
