#include <iostream>
using namespace std;

struct NodoDatos {
    string nombre;
    string apellido;
    char sexo;
    int nota;
    struct NodoDatos* siguiente;
};

struct NodoDatos* lista = NULL;

void insertarDato() {
    struct NodoDatos* auxiliar = new NodoDatos;
    string nombre, apellido;
    char sexo;
    int nota;

    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese el apellido: ";
    cin >> apellido;
    cout << "Ingrese el sexo (M/F): ";
    cin >> sexo;
    cout << "Ingrese la nota: ";
    cin >> nota;

    auxiliar->nombre = nombre;
    auxiliar->apellido = apellido;
    auxiliar->sexo = sexo;
    auxiliar->nota = nota;
    auxiliar->siguiente = NULL;

    auxiliar->siguiente = lista;
    lista = auxiliar;
}

void mostrarLista() {
    struct NodoDatos* auxiliar = lista;

    cout << "\nLISTA:\n";
    while (auxiliar != NULL) {
        cout << "Nombre: " << auxiliar->nombre << endl;
        cout << "Apellido: " << auxiliar->apellido << endl;
        cout << "Sexo: " << auxiliar->sexo << endl;
        cout << "Nota: " << auxiliar->nota << endl;
        cout << endl;
        auxiliar = auxiliar->siguiente;
    }
}

void destruirLista() {
    struct NodoDatos* auxiliar = lista;

    cout << "\nDestruyendo la lista..." << endl;
    while (auxiliar != NULL) {
        lista = lista->siguiente;
        delete auxiliar;
        auxiliar = lista;
    }
}

int main() {
    int opcion;

    do {
        cout << "\nMENU\n";
        cout << "1. Insertar dato\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Destruir lista\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertarDato();
                break;
            case 2:
                mostrarLista();
                break;
            case 3:
                destruirLista();
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}

