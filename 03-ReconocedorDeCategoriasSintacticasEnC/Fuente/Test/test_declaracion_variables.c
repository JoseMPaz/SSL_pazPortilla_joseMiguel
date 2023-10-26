//Ejemplos de declaracion de variable
#include <stdio.h>

long main (void){
    
    //Ejemplo de declaracion sin modificadores
    int a;
    char b;
    float c;
    double d;
    //void e;

    //Ejemplo de declaracion con modificadores
    signed int mod1;
    long double mod2;
    unsigned mod3;
    short int mod4;

    //Ejemplo variable con un valor por defecto con y sin modificadores
    int x = 5;
    char y = 'a';
    //float z = 7.0f;
    double w = 9.8;
    signed int var1 = 7;
    //long double var2 = 6.5L;
    //unsigned int var3 = 8U;
    short int var4 = -2;

    //Ejemplos de variables con algun tipo de error sintáctico
    //int err1 = "Hola";          //Error, no se puede asignar una cadena de texto a un entero
    //char err2 = true;           //Error, no es posible asignarle un booleano a un carácter
    //float err3 = nullptr;       //Error, no es valido asignar nullptr a un flotante
    //double err4 = &err1;        //Error, no es valido asignar la direccion de memoria de otra variable
    //long double err5 = ;
    //int unsigned ;

    return 0;
}