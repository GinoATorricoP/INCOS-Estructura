#include <iostream>
#include <cstring>
#define Size 20
using namespace std;

// Estructura `Nodo`, que representa un nodo en la lista.
// Cada nodo tiene tres campos:
// - `materia`: la materia almacenada en el nodo.
// - `nota`: la nota almacenada en el nodo.
// - `siguiente` y `anterior`: punteros a los nodos siguiente y anterior en la lista, respectivamente.
struct Nodo {
    char materia[Size];
    int nota;
    struct Nodo* siguiente;
    struct Nodo* anterior;
};

// Variable `cabeza`, que es un puntero al nodo cabeza de la lista.
struct Nodo* cabeza = NULL;

// Función `crearNodo()`, que crea un nuevo nodo en la lista.
// La función toma como parámetros una cadena de texto y un número entero,
// y devuelve un puntero al nuevo nodo, o `NULL` si no se pudo crear el nodo.
struct Nodo* crearNodo(char mat[Size], int nt) {
    // Crea un nuevo nodo.
    struct Nodo* nuevoNodo = new struct Nodo;

    // Si el nuevo nodo se creó correctamente,
    if (nuevoNodo != NULL) {
        // Copia la cadena de texto y el número entero en el nodo.
        strcpy(nuevoNodo->materia, mat);
        nuevoNodo->nota = nt;

        // Establece los punteros `siguiente` y `anterior` del nuevo nodo en `NULL`.
        nuevoNodo->siguiente = NULL;
        nuevoNodo->anterior = NULL;
    }

    // Devuelve el puntero al nuevo nodo.
    return nuevoNodo;
}

// Función `insertar()`, que inserta un nuevo nodo al final de la lista.
// La función toma como parámetros una cadena de texto y un número entero,
// y devuelve un puntero al nuevo nodo, o `NULL` si no se pudo insertar el nodo.
void insertar(char mat[Size], int nt) {
    // Crea un nuevo nodo.
    struct Nodo* nuevoNodo = crearNodo(mat, nt);

    // Si el nuevo nodo se creó correctamente,
    if (nuevoNodo != NULL) {
        // Verifica si la lista está vacía.
        if (cabeza == NULL) {
            // La lista está vacía. El nuevo nodo se convierte en el único nodo de la lista.
            nuevoNodo->siguiente = nuevoNodo;
            nuevoNodo->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
        else {
            // La lista no está vacía. El nuevo nodo se inserta después del último nodo de la lista.
            struct Nodo* ultimo = cabeza->anterior;
            nuevoNodo->siguiente = cabeza;
            nuevoNodo->anterior = ultimo;
            cabeza->anterior = nuevoNodo;
            ultimo->siguiente = nuevoNodo;
        }
    }
}

// Función `borrar()`, que borra un nodo de la lista.
// La función toma como parámetro una cadena de texto,
// y devuelve `true` si el nodo se pudo borrar, o `false` si no se encontró el nodo.
void borrar(char mat[Size]) {
    // Verifica si la lista está vacía.
    if (cabeza == NULL) {
        // La lista está vacía.
        cout << "La lista está vacía." << endl;
        return;
    }

    // Crea un puntero al nodo que se va a borrar.
    struct Nodo* temp = cabeza;
    struct Nodo* siguienteNodo = cabeza->siguiente;

    // Recorre la lista buscando el nodo con la materia especificada.
    while (temp != cabeza || siguienteNodo != cabeza) {
        if (strcmp(temp->materia, mat) == 0) {
            // Se encontró el nodo.

            // Si el nodo es el primero de la lista, la cabeza de la lista se actualiza.
            if (temp == cabeza) {
                cabeza = cabeza->siguiente;
            }

            // Los punteros `siguiente` y `anterior` del nodo anterior y del nodo siguiente
            // se actualizan para que salten sobre el nodo que se va a borrar.
            temp->anterior->siguiente = temp->siguiente;
            temp->siguiente->anterior = temp->anterior;

            // El nodo se borra de la memoria.
            delete temp;

            // Se informa que el nodo se borró correctamente.
            cout << "Nodo borrado." << endl;
            return;
        }

        temp = siguienteNodo;
        siguienteNodo = siguienteNodo->siguiente;
    }

    // No se encontró el nodo.
    cout << "No se encontró el nodo con la materia especificada." << endl;
}

// Función `mostrar()`, que muestra los datos de todos los nodos de la lista.
void mostrar() {
    // Verifica si la lista está vacía.
    if (cabeza == NULL) {
        // La lista está vacía.
        cout << "La lista está vacía." << endl;
        return;
    }

    // Crea un puntero al primer nodo de la lista.
    struct Nodo* temp = cabeza;

    // Recorre la lista mostrando los datos de cada nodo.
    do {
        // Muestra los datos del nodo actual.
        cout << "Materia: " << temp->materia << ", Nota: " << temp->nota << endl;

        // Avanza al siguiente nodo.
        temp = temp->siguiente;
    } while (temp != cabeza);
}

// Función principal.
int main() {
    // Inserta algunos datos en la lista.
    insertar("Matemáticas", 8);
    insertar("Física", 9);
    insertar("Programación", 10);

    // Muestra los datos de la lista.
    mostrar();

    // Borra un nodo de la lista.
    borrar("Física");

    // Muestra los datos de la lista nuevamente.
    mostrar();

    // Devuelve 0 para indicar que el programa se ejecutó correctamente.
    return 0;
}


