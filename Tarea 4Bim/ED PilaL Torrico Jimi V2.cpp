#include <iostream>

using namespace std;

struct JTnodoP {
  char dato;
  JTnodoP* sig;
};

bool es_vacia(JTnodoP* pila) {
  return pila == NULL;
}

JTnodoP* crear_pila() {
  return NULL;
}

void push(JTnodoP*& pila, char dato) {
  JTnodoP* nuevo = new JTnodoP();
  nuevo->dato = dato;
  nuevo->sig = pila;
  pila = nuevo;
}

void pop(JTnodoP*& pila) {
  if (!es_vacia(pila)) {
    JTnodoP* aux = pila;
    pila = pila->sig;
    delete aux;
  }
}

void mostrar(JTnodoP* pila) {
  while (pila != NULL) {
    cout << pila->dato << " ";
    pila = pila->sig;
  }
  cout << endl;
}

void menu() {
  int opcion;

  do {
    cout << "1. Insertar un elemento" << endl;
    cout << "2. Eliminar un elemento" << endl;
    cout << "3. Vaciar la pila" << endl;
    cout << "4. Mostrar la pila" << endl;
    cout << "0. Salir" << endl;
    cout << "Opción: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        push(pila, 'a');
        break;
      case 2:
        pop(pila);
        break;
      case 3:
        while (!es_vacia(pila)) {
          pop(pila);
        }
        break;
      case 4:
        mostrar(pila);
        break;
      default:
        break;
    }
  } while (opcion != 0);
}

int main() {
  JTnodoP* pila = crear_pila();
  menu();
  mostrar(pila);
  

  return 0;
}


