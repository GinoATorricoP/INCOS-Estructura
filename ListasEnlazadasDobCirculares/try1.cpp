#include <iostream>
#include <cstring>
#define Size 20
using namespace std;

// Definir la estructura de un nodo de la lista
struct nodoldc
{
    int codMaterial; // C�digo del material
    char nombreMaterial[Size]; // Nombre del material
    struct nodoldc *siguiente, *anterior; // Punteros al siguiente y anterior nodo
};

struct nodoldc *ldc; // Puntero al primer nodo de la lista

// Funci�n para crear un nuevo nodo con los datos dados
struct nodoldc *crearnodoldc(int cod, char nom[Size])
{
    struct nodoldc *nuevo;
    nuevo = new struct nodoldc; // Reservar memoria para el nuevo nodo
    if (nuevo != NULL) // Si se pudo crear el nodo
    {
        nuevo->codMaterial = cod; // Asignar el c�digo del material
        strcpy(nuevo->nombreMaterial, nom); // Copiar el nombre del material
        nuevo->siguiente = NULL; // Inicializar los punteros a NULL
        nuevo->anterior = NULL;
    }
    else // Si no se pudo crear el nodo
    {
        nuevo = NULL; // Devolver NULL como indicador de error
    }
    return nuevo; // Devolver el puntero al nuevo nodo o NULL si hubo error
}

// Funci�n para insertar un nuevo nodo al final de la lista
void insertar_ultimo_nodo(int cod, char nom[Size])
{
    struct nodoldc *nuevo;
    nuevo = crearnodoldc(cod, nom); // Crear el nuevo nodo con los datos dados
    if (nuevo == NULL) // Si no se pudo crear el nodo
    {
        cout << "NO SE PUDO INSERTAR NODO \n";
        return;
    }
    if (ldc == NULL) // Si la lista est� vac�a
    {
        nuevo->siguiente = nuevo; // El nuevo nodo se apunta a s� mismo
        nuevo->anterior = nuevo;
        ldc = nuevo; // El puntero 'ldc' apunta al nuevo nodo
    }
    else // Si la lista no est� vac�a
    {
        if (ldc->siguiente == ldc) // Si la lista solo tiene un nodo
        {
            ldc->siguiente = nuevo; // El primer nodo apunta al nuevo nodo
            nuevo->anterior = ldc;  // El nuevo nodo apunta al primer nodo
            nuevo->siguiente = ldc; // El nuevo nodo se apunta a s� mismo
            ldc->anterior = nuevo;  // El primer nodo apunta al nuevo nodo
        }
        else // Si la lista tiene m�s de un nodo
        {
            nuevo->anterior = ldc->anterior; // El nuevo nodo apunta al �ltimo nodo de la lista
            nuevo->siguiente = ldc;         // El nuevo nodo apunta al primer nodo de la lista
            ldc->anterior->siguiente = nuevo; // El �ltimo nodo de la lista apunta al nuevo nodo
            ldc->anterior = nuevo;          // El primer nodo de la lista apunta al nuevo nodo
        }
    }
}

// Funci�n para mostrar los datos de los nodos de la lista en orden ascendente (desde el primero al �ltimo)
void mostrar_ldc_asc()
{
    struct nodoldc *aux = ldc;
    cout << "\nLDC ASCENDENTE: ";
    if (aux != NULL) // Si la lista no est� vac�a
    {
        cout << "(" << aux->codMaterial << ", " << aux->nombreMaterial << "), "; // Mostrar los datos del primer nodo
        aux = aux->siguiente;

        while (aux != ldc) // Mientras no se vuelva al primer nodo
        {
            cout << "(" << aux->codMaterial << ", " << aux->nombreMaterial << "), "; // Mostrar los datos del nodo actual
            aux = aux->siguiente;
        }
    }
    else // Si la lista est� vac�a
    {
        cout << "lista ldc esta vacia";
    }
}

// Funci�n para mostrar los datos de los nodos de la lista en orden descendente (desde el �ltimo al primero)
void mostrar_ldc_desc()
{
    struct nodoldc *aux = ldc;
    cout << "\nLDC DESCENDENTE: ";
    if (aux != NULL) // Si la lista no est� vac�a
    {
        aux = aux->anterior; // Ir al �ltimo nodo de la lista
        cout << "(" << aux->codMaterial << ", " << aux->nombreMaterial << "), "; // Mostrar los datos del �ltimo nodo
        aux = aux->anterior;

        while (aux != ldc->anterior) // Mientras no se vuelva al �ltimo nodo
        {
            cout << "(" << aux->codMaterial << ", " << aux->nombreMaterial << "), "; // Mostrar los datos del nodo actual
            aux = aux->anterior;
        }
    }
    else // Si la lista est� vac�a
    {
        cout << "lista ldc esta vacia";
    }
}

// Funci�n para buscar un nodo con un c�digo dado en la lista
struct nodoldc *buscar(int cod)
{
    if (ldc == NULL) // Si la lista est� vac�a
    {
        return NULL; // No se puede encontrar nada
    }

    struct nodoldc *aux = ldc;
    do // Recorrer la lista circular
    {
        if (aux->codMaterial == cod) // Si el nodo actual tiene el c�digo buscado
        {
            return aux; // Devolver el puntero al nodo encontrado
        }
        aux = aux->siguiente;
    } while (aux != ldc);

    return NULL; // No se encontr� el nodo con el c�digo dado
}

// Funci�n para eliminar un nodo con un c�digo dado en la lista
void eliminar(int cod)
{
    struct nodoldc *nodoAEliminar = buscar(cod); // Buscar el nodo con el c�digo dado

    if (nodoAEliminar != NULL) // Si se encontr� el nodo
    {
        if (nodoAEliminar == ldc) // Si el nodo a eliminar es el primero de la lista
        {
            ldc = ldc->siguiente; // Actualizar el puntero 'ldc' al siguiente nodo
        }

        // Actualizar los punteros de los nodos vecinos al nodo a eliminar
        nodoAEliminar->anterior->siguiente = nodoAEliminar->siguiente;
        nodoAEliminar->siguiente->anterior = nodoAEliminar->anterior;

        delete nodoAEliminar; // Liberar la memoria del nodo eliminado
        cout << "Nodo con codigo '" << cod << "' eliminado correctamente.\n";
    }
    else // Si no se encontr� el nodo
    {
        cout << "Nodo con codigo '" << cod << "' no encontrado en la lista.\n";
    }
}

// Funci�n para modificar los datos de un nodo con un c�digo dado en la lista
void modificar(int cod, int nuevoCod, char nuevoNom[Size])
{
    struct nodoldc *nodoAModificar = buscar(cod); // Buscar el nodo con el c�digo dado

    if (nodoAModificar != NULL) // Si se encontr� el nodo
    {
        nodoAModificar->codMaterial = nuevoCod; // Asignar el nuevo c�digo del material
        strcpy(nodoAModificar->nombreMaterial, nuevoNom); // Copiar el nuevo nombre del material
        cout << "Nodo con codigo '" << cod << "' modificado correctamente.\n";
    }
    else // Si no se encontr� el nodo
    {
        cout << "Nodo con codigo '" << cod << "' no encontrado en la lista.\n";
    }
}



// Funci�n para mostrar el men� y devolver la opci�n elegida por el usuario
int menu()
{
    int opcion;
    cout << "\nMENU DE OPCIONES\n";
    cout << "1. Insertar un nuevo nodo al final de la lista\n";
    cout << "2. Eliminar un nodo con un codigo dado de la lista\n";
    cout << "3. Modificar los datos de un nodo con un codigo dado de la lista\n";
    cout << "4. Mostrar los nodos de la lista en orden ascendente\n";
    cout << "5. Mostrar los nodos de la lista en orden descendente\n";
    cout << "6. Salir del programa\n";
    cout << "Ingrese su opcion: ";
    cin >> opcion;
    return opcion;
}

int main()
{
    ldc = NULL; // Inicializar el puntero 'ldc' a NULL

    int cod, nuevoCod;
    char nom[Size], nuevoNom[Size];
    
    int opcion = menu(); // Mostrar el men� y obtener la opci�n del usuario
    
    while (opcion != 6) // Mientras el usuario no quiera salir
    {
        switch (opcion) // Seg�n la opci�n elegida
        {
            case 1: // Si quiere insertar un nuevo nodo
                // Pedir al usuario que ingrese los datos del nuevo nodo
                cout << "\nIngrese el codigo del material: ";
                cin >> cod;
                cout << "Ingrese el nombre del material: ";
                cin >> nom;

                // Insertar el nuevo nodo en la lista
                insertar_ultimo_nodo(cod, nom);
                
                break;
                
            case 2: // Si quiere eliminar un nodo
                // Pedir al usuario que ingrese el c�digo del nodo a eliminar
                cout << "\nIngrese el codigo del material a eliminar: ";
                cin >> cod;

                // Eliminar el nodo con el c�digo dado de la lista
                eliminar(cod);
                
                break;
                
            case 3: // Si quiere modificar los datos de un nodo
                // Pedir al usuario que ingrese el c�digo del nodo a modificar
                cout << "\nIngrese el codigo del material a modificar: ";
                cin >> cod;

                // Buscar el nodo con el c�digo dado en la lista
                struct nodoldc *nodoAModificar = buscar(cod);

                if (nodoAModificar != NULL) // Si se encontr� el nodo
                {
                    // Mostrar los datos actuales del nodo
                    cout << "Los datos actuales del nodo son:\n";
                    cout << "Codigo: " << nodoAModificar->codMaterial << "\n";
                    cout << "Nombre: " << nodoAModificar->nombreMaterial << "\n";

                    // Pedir al usuario que ingrese los nuevos datos del nodo
                    cout << "Ingrese el nuevo codigo del material: ";
                    cin >> nuevoCod;
                    cout << "Ingrese el nuevo nombre del material: ";
                    cin >> nuevoNom;

                    // Modificar los datos del nodo con los nuevos valores
                    modificar(cod, nuevoCod, nuevoNom);
                }
                else // Si no se encontr� el nodo
                {
                    cout << "Nodo con codigo '" << cod << "' no encontrado en la lista.\n";
                }
                
                break;
                
            case 4: // Si quiere mostrar los nodos de la lista en orden ascendente
                {mostrar_ldc_asc();
				
                
                break;}
                
            case 5: // Si quiere mostrar los nodos de la lista en orden descendente
                mostrar_ldc_desc();
                
                break;
                
            default: // Si eligi� una opci�n inv�lida
                cout << "\nOpcion invalida. Por favor, intente de nuevo.\n";
        }
        
        opcion = menu(); // Mostrar el men� nuevamente y obtener la nueva opci�n del usuario
    }
    
    cout << "\nGracias por usar el programa. Hasta pronto.\n";

    return 0;
}

