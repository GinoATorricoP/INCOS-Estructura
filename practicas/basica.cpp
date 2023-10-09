#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

Nodo* cabeza = NULL;

void insertar(int valor) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = valor;

    if (cabeza == NULL) {
        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
        cabeza = nuevoNodo;
    } else {
        Nodo* ultimo = cabeza->anterior;
        nuevoNodo->siguiente = cabeza;
        nuevoNodo->anterior = ultimo;
        cabeza->anterior = nuevoNodo;
        ultimo->siguiente = nuevoNodo;
    }
}

void mostrar() {
    if (cabeza == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }

    Nodo* temp = cabeza;

    do {
        cout << temp->dato << " ";
        temp = temp->siguiente;
    } while (temp != cabeza);

    cout << endl;
}

int main() {
    insertar(1);
    insertar(2);
    insertar(3);
    insertar(4);
    
    mostrar();
    
    return 0;
}

