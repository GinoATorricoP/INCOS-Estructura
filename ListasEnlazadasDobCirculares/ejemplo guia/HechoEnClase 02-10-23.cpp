#include <iostream>
#include <cstring>
#define Size 20
using namespace std;

struct nodoldc
{
	char texto[Size];
	struct nodoldc *siguiente, *anterior;
};

struct nodoldc *ldc ;

struct nodoldc * crearnodoldc(char txt [Size])
{
	struct nodoldc *nuevo ;
	nuevo = new struct nodoldc;
	if(nuevo != NULL)
	{
		strcpy (nuevo -> texto, txt);
		nuevo -> siguiente = NULL ;
		nuevo -> anterior = NULL;
	}
	else
	{
		nuevo = NULL;
	}
	return nuevo;
}

void insertar_ultimo_nodo (char txt [Size])
{
	struct nodoldc * nuevo;
	nuevo = crearnodoldc(txt);
	if (nuevo == NULL)
	{
		cout <<"NO SE PUDO INSERTAR NODO \n";
		return;
	}
	if (ldc ==NULL)
	{
		nuevo -> siguiente = nuevo;
		nuevo -> anterior = nuevo;
		ldc = nuevo;
	}
	else
	{
		if (ldc -> siguiente == ldc )
		{
			ldc->siguiente = nuevo ;
			nuevo -> anterior = ldc;
			nuevo -> siguiente = ldc;
			ldc->anterior = nuevo;
		}
		else
		{
			nuevo-> anterior = ldc -> anterior;
			nuevo-> siguiente = ldc;
			ldc->anterior->siguiente = nuevo;
			ldc->anterior = nuevo;
		}
	}
}

void mostrar_ldc()
{
	struct nodoldc * aux = ldc;
	cout <<"\nLDC";
	if(aux!= NULL)
	{
		cout <<aux->texto<<", ";
		aux = aux-> siguiente;
		
	}
	else
	{
		cout<<"lista ldc esta vacia";
	}
	aux  =aux -> siguiente;
	while (aux!= ldc){
		cout <<aux->texto<<", ";
		aux = aux ->siguiente;
	}
}

int main ()
{
	ldc = NULL;
	char cHolatexto[Size]= {"HOLA"};
	char cMundotexto[Size]= {"MUNDO"};
	char cGordotexto[Size]= {"GORDO"};
	mostrar_ldc();
	insertar_ultimo_nodo (cHolatexto);
	mostrar_ldc();
	insertar_ultimo_nodo (cMundotexto);
	mostrar_ldc();
	insertar_ultimo_nodo (cGordotexto);
	mostrar_ldc();
	
	
	
	//cout <<"hola mundo";
	return 0;
}
