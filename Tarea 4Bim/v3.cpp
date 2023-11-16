#include <iostream>

using namespace std;

struct JTnodoP
{
    char dato;
    JTnodoP *sig;
};

bool es_vacia(JTnodoP *pila)
{
    return pila == NULL;
}

JTnodoP *crear_pila()
{
    return NULL;
}

void push(JTnodoP *&pila, char dato)
{
    JTnodoP *nuevo = new JTnodoP();
    nuevo->dato = dato;
    nuevo->sig = pila;
    pila = nuevo;
}

void pop(JTnodoP *&pila)
{
    if (!es_vacia(pila))
    {
        JTnodoP *aux = pila;
        pila = pila->sig;
        delete aux;
    }
    else
    {
        cout << "La pila esta vacia";
    }
}

void mostrar(JTnodoP *pila)
{
    while (pila != NULL)
    {
        cout << pila->dato << " ";
        pila = pila->sig;
    }
    cout << endl;
}

int main()
{

    JTnodoP *pila = crear_pila();

    int opcion;
    char dato;

    do
    {
        cout << "1. Insertar un elemento" << endl;
        cout << "2. Eliminar un elemento" << endl;
        cout << "3. Vaciar la pila" << endl;
        cout << "4. Mostrar la pila" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese el dato a insertar: ";
            cin >> dato;
            push(pila, dato);
            break;
        case 2:
            pop(pila);
            break;
        case 3:
            while (!es_vacia(pila))
            {
                pop(pila);
            }
            break;
        case 4:
            if (!es_vacia(pila))
            {
                mostrar(pila);
            }
            else
            {
                cout << "La pila esta vacia ";
            }
            break;
        default:
            break;
        }
    } while (opcion != 0);

    return 0;
}
