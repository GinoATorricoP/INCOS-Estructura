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

int main() {
  JTnodoP* pila = crear_pila();

  push(pila, 'a');
  push(pila, 'b');
  push(pila, 'c');

  mostrar(pila);

  pop(pila);
  pop(pila);

  mostrar(pila);

  return 0;
}


