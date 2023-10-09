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
	struct nodoldc *aux = ldc;
    cout << "\nLDC: ";
    if (aux != NULL)
    {
        cout << aux->texto << ", ";
        aux = aux->siguiente;

        while (aux != ldc)
        {
            cout << aux->texto << ", ";
            aux = aux->siguiente;
        }
    }
    else
    {
        cout << "lista ldc esta vacia";
    }
}

// Función para buscar un nodo con un texto dado en la lista
struct nodoldc *buscar(const char txt[Size])
{
    if (ldc == NULL)
    {
        return NULL; // La lista está vacía, no se puede encontrar nada
    }

    struct nodoldc *aux = ldc;
    do
    {
        if (strcmp(aux->texto, txt) == 0)
        {
            return aux; // Se encontró el nodo
        }
        aux = aux->siguiente;
    } while (aux != ldc);

    return NULL; // No se encontró el nodo con el texto dado
}

// Función para eliminar un nodo con un texto dado en la lista
void eliminar(const char txt[Size])
{
    struct nodoldc *nodoAEliminar = buscar(txt);

    if (nodoAEliminar != NULL)
    {
        if (nodoAEliminar == ldc)
        {
            ldc = ldc->siguiente; // Actualizar el puntero 'ldc' si estamos eliminando el nodo inicial
        }

        // Actualizar los punteros de los nodos vecinos
        nodoAEliminar->anterior->siguiente = nodoAEliminar->siguiente;
        nodoAEliminar->siguiente->anterior = nodoAEliminar->anterior;

        delete nodoAEliminar; // Liberar la memoria del nodo eliminado
        cout << "Nodo con texto '" << txt << "' eliminado correctamente.\n";
    }
    else
    {
        cout << "Nodo con texto '" << txt << "' no encontrado en la lista.\n";
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
	
	eliminar("MUNDO"); // Eliminar un nodo con el texto "MUNDO"
    mostrar_ldc();
	
	
	
	//cout <<"hola mundo";
	return 0;
}
