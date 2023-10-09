#include <iostream>
#include <cstring>
#include <fstream>
#define Size 20
using namespace std;

struct nodoldc
{
    int codMaterial;
    char nombreMaterial[Size];
    struct nodoldc *siguiente, *anterior;
};

struct nodoldc *ldc;

struct nodoldc *crearnodoldc(int cod, char nombre[Size])
{
    struct nodoldc *nuevo;
    nuevo = new struct nodoldc;
    if (nuevo != NULL)
    {
        nuevo->codMaterial = cod;
        strcpy(nuevo->nombreMaterial, nombre);
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
    }
    else
    {
        nuevo = NULL;
    }
    return nuevo;
}

void insertar_cabeza(int cod, char nombre[Size])
{
    struct nodoldc *nuevo;
    nuevo = crearnodoldc(cod, nombre);
    if (nuevo == NULL)
    {
        cout << "NO SE PUDO INSERTAR NODO \n";
        return;
    }
    if (ldc == NULL)
    {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        ldc = nuevo;
    }
    else
    {
        nuevo->siguiente = ldc;
        nuevo->anterior = ldc->anterior;
        ldc->anterior->siguiente = nuevo;
        ldc->anterior = nuevo;
        ldc = nuevo;
    }
}

void insertar_en_orden(int cod, char nombre[Size])
{
    struct nodoldc *nuevo;
    nuevo = crearnodoldc(cod, nombre);
    if (nuevo == NULL)
    {
        cout << "NO SE PUDO INSERTAR NODO \n";
        return;
    }
    if (ldc == NULL)
    {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        ldc = nuevo;
    }
    else
    {
        struct nodoldc *aux = ldc;
        do
        {
            if (cod < aux->codMaterial)
            {
                nuevo->siguiente = aux;
                nuevo->anterior = aux->anterior;
                aux->anterior->siguiente = nuevo;
                aux->anterior = nuevo;
                if (ldc == aux)
                    ldc = nuevo;
                return;
            }
            aux = aux->siguiente;
        } while (aux != ldc);
        nuevo->siguiente = ldc;
        nuevo->anterior = ldc->anterior;
        ldc->anterior->siguiente = nuevo;
        ldc->anterior = nuevo;
        ldc = nuevo;
    }
}

void mostrar_ldc()
{
    struct nodoldc *aux = ldc;
    cout << "\nLDC: ";
    if (aux != NULL)
    {
        do
        {
            cout << "[" << aux->codMaterial << ", " << aux->nombreMaterial << "], ";
            aux = aux->siguiente;
        } while (aux != ldc);
    }
    else
    {
        cout << "Lista ldc esta vacia";
    }
}

void buscar_material(int cod)
{
    struct nodoldc *aux = ldc;
    if (aux != NULL)
    {
        do
        {
            if (aux->codMaterial == cod)
            {
                cout << "\nMaterial encontrado: [" << aux->codMaterial << ", " << aux->nombreMaterial << "]";
                return;
            }
            aux = aux->siguiente;
        } while (aux != ldc);
    }
    cout << "\nMaterial no encontrado.";
}

void insertar_antes_de(int cod, int codNuevo, char nombreNuevo[Size])
{
    struct nodoldc *nuevo;
    nuevo = crearnodoldc(codNuevo, nombreNuevo);
    if (nuevo == NULL)
    {
        cout << "NO SE PUDO INSERTAR NODO \n";
        return;
    }
    struct nodoldc *aux = ldc;
    if (aux != NULL)
    {
        do
        {
            if (aux->codMaterial == cod)
            {
                nuevo->siguiente = aux;
                nuevo->anterior = aux->anterior;
                aux->anterior->siguiente = nuevo;
                aux->anterior = nuevo;
                if (ldc == aux)
                    ldc = nuevo;
                cout << "\nMaterial insertado antes de [" << cod << ", " << nombreNuevo << "]";
                return;
            }
            aux = aux->siguiente;
        } while (aux != ldc);
    }
    cout << "\nMaterial no encontrado.";
}

void editar_material(int cod)
{
    struct nodoldc *aux = ldc;
    if (aux != NULL)
    {
        do
        {
            if (aux->codMaterial == cod)
            {
                cout << "\nEditar Material [" << cod << ", " << aux->nombreMaterial << "]";
                cout << "\nIngrese el nuevo nombre: ";
                cin >> aux->nombreMaterial;
                cout << "\nMaterial editado: [" << cod << ", " << aux->nombreMaterial << "]";
                return;
            }
            aux = aux->siguiente;
        } while (aux != ldc);
    }
    cout << "\nMaterial no encontrado.";
}

void borrar_material(int cod)
{
    struct nodoldc *aux = ldc;
    if (aux != NULL)
    {
        do
        {
            if (aux->codMaterial == cod)
            {
                if (ldc == aux)
                {
                    if (ldc->siguiente == ldc)
                    {
                        delete ldc;
                        ldc = NULL;
                    }
                    else
                    {
                        ldc->anterior->siguiente = ldc->siguiente;
                        ldc->siguiente->anterior = ldc->anterior;
                        struct nodoldc *temp = ldc;
                        ldc = ldc->siguiente;
                        delete temp;
                    }
                }
                else
                {
                    aux->anterior->siguiente = aux->siguiente;
                    aux->siguiente->anterior = aux->anterior;
                    delete aux;
                }
                cout << "\nMaterial [" << cod << "] eliminado.";
                return;
            }
            aux = aux->siguiente;
        } while (aux != ldc);
    }
    cout << "\nMaterial no encontrado.";
}

void destruir_ldc()
{
    struct nodoldc *aux = ldc;
    if (aux != NULL)
    {
        do
        {
            struct nodoldc *temp = aux;
            aux = aux->siguiente;
            delete temp;
        } while (aux != ldc);
    }
    ldc = NULL;
    cout << "\nLista destruida.";
}

void ordenar_ldc()
{
    if (ldc == NULL || ldc->siguiente == ldc)
        return;

    struct nodoldc *sorted = NULL;
    struct nodoldc *current = ldc;
    do
    {
        struct nodoldc *next = current->siguiente;

        if (sorted == NULL)
        {
            sorted = current;
            sorted->siguiente = sorted;
            sorted->anterior = sorted;
        }
        else
        {
            struct nodoldc *temp = sorted;
            do
            {
                if (current->codMaterial < temp->codMaterial)
                {
                    current->siguiente = temp;
                    current->anterior = temp->anterior;
                    temp->anterior->siguiente = current;
                    temp->anterior = current;
                    if (sorted == temp)
                        sorted = current;
                    break;
                }
                temp = temp->siguiente;
            } while (temp != sorted);

            if (temp == sorted)
            {
                current->siguiente = sorted;
                current->anterior = sorted->anterior;
                sorted->anterior->siguiente = current;
                sorted->anterior = current;
                sorted = current;
            }
        }

        current = next;
    } while (current != ldc);

    ldc = sorted;
    cout << "\nLista ordenada por codMaterial.";
}

void guardar_archivo()
{
    ofstream archivo("lista_materiales.txt");
    struct nodoldc *aux = ldc;
    if (aux != NULL)
    {
        do
        {
            archivo << "[" << aux->codMaterial << ", " << aux->nombreMaterial << "]\n";
            aux = aux->siguiente;
        } while (aux != ldc);
    }
    archivo.close();
    cout << "\nLista guardada en el archivo 'lista_materiales.txt'.";
}

int main()
{
    ldc = NULL;
    int opcion;

    do
    {
        cout << "\nMENU DE OPCIONES:";
        cout << "\n1. Insertar al inicio";
        cout << "\n2. Insertar en orden";
        cout << "\n3. Mostrar lista";
        cout << "\n4. Buscar material";
        cout << "\n5. Insertar antes de un material";
        cout << "\n6. Editar material";
        cout << "\n7. Borrar material";
        cout << "\n8. Destruir lista";
        cout << "\n9. Ordenar lista";
        cout << "\n10. Guardar lista en archivo";
        cout << "\n0. Salir";
        cout << "\nIngrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            int cod;
            char nombre[Size];
            cout << "\nIngrese el codigo del material: ";
            cin >> cod;
            cout << "\nIngrese el nombre del material: ";
            cin >> nombre;
            insertar_cabeza(cod, nombre);
            break;
        }
        case 2:
        {
            int cod;
            char nombre[Size];
            cout << "\nIngrese el codigo del material: ";
            cin >> cod;
            cout << "\nIngrese el nombre del material: ";
            cin >> nombre;
            insertar_en_orden(cod, nombre);
            break;
        }
        case 3:
            mostrar_ldc();
            break;
        case 4:
        {
            int cod;
            cout << "\nIngrese el codigo del material a buscar: ";
            cin >> cod;
            buscar_material(cod);
            break;
        }
        case 5:
        {
            int cod, codNuevo;
            char nombreNuevo[Size];
            cout << "\nIngrese el codigo del material antes del cual desea insertar: ";
            cin >> cod;
            cout << "\nIngrese el codigo del nuevo material: ";
            cin >> codNuevo;
            cout << "\nIngrese el nombre del nuevo material: ";
            cin >> nombreNuevo;
            insertar_antes_de(cod, codNuevo, nombreNuevo);
            break;
        }
        case 6:
        {
            int cod;
            cout << "\nIngrese el codigo del material a editar: ";
            cin >> cod;
            editar_material(cod);
            break;
        }
        case 7:
        {
            int cod;
            cout << "\nIngrese el codigo del material a borrar: ";
            cin >> cod;
            borrar_material(cod);
            break;
        }
        case 8:
            destruir_ldc();
            break;
        case 9:
            ordenar_ldc();
            break;
        case 10:
            guardar_archivo();
            break;
        case 0:
            break;
        default:
            cout << "\nOpcion no valida.";
            break;
        }
    } while (opcion != 0);

    return 0;
}
