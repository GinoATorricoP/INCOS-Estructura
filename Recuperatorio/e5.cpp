#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
  // Declarar variables
  int mat[2][2];

  // Inicializar el generador de números aleatorios
  srand(time(NULL));

  // Llenar la matriz con números aleatorios
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mat[i][j] = 1 + rand() % 100;
    }
  }

  // Imprimir la matriz
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

