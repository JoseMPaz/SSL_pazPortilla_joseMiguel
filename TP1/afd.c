#include "afd.h"

void procesar_archivo (FILE * ptr_archivo_entrada, FILE * ptr_archivo_salida)
{
	char c;
	int i, contador = 0;
	estado_t q_anterior, q_actual;
	estado_t tabla_de_transiciones[7][7]={ {CERO_OCTAL,DECIMAL ,DECIMAL ,OTRO_ASCII,OTRO_ASCII,INICIAL,OTRO_ASCII},
														{DECIMAL,DECIMAL,DECIMAL,OTRO_ASCII,OTRO_ASCII,INICIAL,OTRO_ASCII},
														{OCTAL,OCTAL,OTRO_ASCII,OTRO_ASCII,HEXADECIMAL_INCONCLUSO,INICIAL,OTRO_ASCII},
														{OCTAL,OCTAL,OTRO_ASCII,OTRO_ASCII,OTRO_ASCII,INICIAL,OTRO_ASCII},
														{HEXADECIMAL,HEXADECIMAL,HEXADECIMAL,HEXADECIMAL,OTRO_ASCII,INICIAL,OTRO_ASCII},
														{HEXADECIMAL,HEXADECIMAL,HEXADECIMAL,HEXADECIMAL,OTRO_ASCII,INICIAL,OTRO_ASCII},
														{OTRO_ASCII,OTRO_ASCII,OTRO_ASCII,OTRO_ASCII,OTRO_ASCII,INICIAL,OTRO_ASCII}};
	
	q_anterior = q_actual = INICIAL;
	c = fgetc (ptr_archivo_entrada);
	while (c != EOF)
	{
		q_actual = tabla_de_transiciones[(int)q_anterior][Columna(c)];
		if (q_actual != INICIAL)
		{
			fprintf (ptr_archivo_salida,"%c",c);
		}
		else
		{
			if (q_anterior == DECIMAL)
				fprintf (ptr_archivo_salida,"%15s%c", "DECIMAL",'\n');
			else if (q_anterior == CERO_OCTAL || q_anterior == OCTAL)
				fprintf (ptr_archivo_salida,"%15s%c", "OCTAL",'\n');
			else if (q_anterior == HEXADECIMAL)
				fprintf (ptr_archivo_salida,"%15s%c", "HEXADECIMAL",'\n');
			else
				fprintf (ptr_archivo_salida,"%15s%c", "NO RECONOCIDA",'\n');
				
			q_anterior = q_actual;
		}
		c = fgetc (ptr_archivo_entrada);
		q_anterior = q_actual;
	}
	return;
}
	
int Columna (char c)
{	
	if (c == '0')
		return 0;
	if (c =='1'||c =='2'||c =='3'||c =='4'||c =='5'||c =='6'||c =='7')
		return 1;
	if (c =='8'||c =='9')
		return 2;
	if (c =='a'||c =='b'||c =='c'||c =='d'||c =='e'||c =='f'||c =='A'||c =='B'||c =='C'||c =='D'||c =='E'||c =='F')
		return 3;
	if (c =='x'||c =='X')
		return 4;
	if (c ==','||c =='\n'||c =='\r'||c =='\0')
		return 5;
		
	return 6;
}

/*q = Q0;
		while (c != DELIMITADOR && c != SALTO_DE_LINEA && c != RETORNO_DE_CARRO && c != FIN_DE_CADENA && c != EOF)
		{
			q = tabla_de_transiciones[q][Columna(c)];
			if (q == Q6)
			{
				fprintf (ptr_archivo_salida,"%c",c);
				fprintf (ptr_archivo_salida,"%15s%c", "NO RECONOCIDA",'\n');
				c = fgetc (ptr_archivo_entrada);
				while (c != DELIMITADOR && c != SALTO_DE_LINEA && c != RETORNO_DE_CARRO && c != FIN_DE_CADENA)
				{
					fprintf (ptr_archivo_salida,"%c",c);
					c = fgetc (ptr_archivo_entrada);
				}
				break;
			}
			else
			{
				fprintf (ptr_archivo_salida,"%c",c);
				c = fgetc (ptr_archivo_entrada);	
			}
		}
		if (q == Q0 || q == Q6 || q == Q3 )
			fprintf (ptr_archivo_salida,"%15s%c", "NO RECONOCIDA",'\n');
		if (q == Q2)
			fprintf (ptr_archivo_salida,"%15s%c", "DECIMAL",'\n');
		if (q == Q5 || q == Q1)
			fprintf (ptr_archivo_salida,"%15s%c", "OCTAL",'\n');
		if (q == Q4)
			fprintf (ptr_archivo_salida,"%15s%c", "HEXADECIMAL",'\n');
		
		c = fgetc (ptr_archivo_entrada);*/

