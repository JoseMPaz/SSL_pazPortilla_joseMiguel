struct ss{
    char puntero;
    char puntero_2;
} s;

struct str{
    float r;
};

union h;

int main (){
    int entero_2 = 8;
    int entero_3 = 2 * 5;   
    int a = entero_2, b=entero_3, c=a;
    unsigned int entero =1;
    char h;
    int _1 = entero_2 * (restar(entero,a)+sumar(a,b));
 
    unsigned int x = 75;

    switch(a)
	{
		case 1:	printf("Es uno");break;
		case 2: 	puts("Es dos");
		default:	return 1;
	}

    sumar(a, b);

    if (c >= 0 && c <= 9) return 2;
    if (c == '_')
            return 1;
    else
        return 0;
    if (isalpha(c) )
    {
        return 0;
    }

    return 0;
}

int sumar(int a, int b){
    return a+b;
}

float restar(float a, float b){
    return a-b;
}

double multiplicar(double a, double b){
    double c = a*b;
    return (c);
}