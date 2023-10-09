#include <iostream>
#include <cstring>
#define Size 20
using namespace std;

struct Nodo {
    char materia[Size];
    int nota;
    struct Nodo* siguiente;
    struct Nodo* anterior;
};

struct Nodo* cabeza = NULL;

struct Nodo* crearNodo(char mat[Size], int nt) {
    struct Nodo* nuevoNodo = new struct Nodo;
    if (nuevoNodo != NULL) {
        strcpy(nuevoNodo->materia, mat);
        nuevoNodo->nota = nt;
        nuevoNodo->siguiente = NULL;
        nuevoNodo->anterior = NULL;
    }
    return nuevoNodo;
}

void insertar(char mat[Size], int nt) {
    struct Nodo* nuevoNodo = crearNodo(mat, nt);
    if (nuevoNodo == NULL) {
        cout << "No se pudo insertar el nodo." << endl;
        return;
    }
    if (cabeza == NULL) {
        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
        cabeza = nuevoNodo;
    } else {
        struct Nodo* ultimo = cabeza->anterior;
        nuevoNodo->siguiente = cabeza;
        nuevoNodo->anterior = ultimo;
        cabeza->anterior = nuevoNodo;
        ultimo->siguiente = nuevoNodo;
    }
}

void borrar(char mat[Size]) {
    if (cabeza == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }

    struct Nodo* temp = cabeza;
    struct Nodo* siguienteNodo = cabeza->siguiente;

    while (temp != cabeza || siguienteNodo != cabeza) {
        if (strcmp(temp->materia, mat) == 0) {
            if (temp == cabeza) {
                cabeza = cabeza->siguiente;
            }
            temp->anterior->siguiente = temp->siguiente;
            temp->siguiente->anterior = temp->anterior;
            delete temp;
            cout << "Nodo borrado." << endl;
            return;
        }
        temp = siguienteNodo;
        siguienteNodo = siguienteNodo->siguiente;
    }

    cout << "No se encontró el nodo con la materia especificada." << endl;
}

void mostrar() {
    if (cabeza == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }

    struct Nodo* temp = cabeza;

    do {
        cout << "Materia: " << temp->materia << ", Nota: " << temp->nota << endl;
        temp = temp->siguiente;
    } while (temp != cabeza);
}

int main() {
    insertar("Matemáticas", 8);
    insertar("Física", 9);
    insertar("Programación", 10);
    
    mostrar();
    
    borrar("Física");
    
    mostrar();
    
    return 0;
}

