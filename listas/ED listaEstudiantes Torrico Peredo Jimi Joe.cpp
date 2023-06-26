/*ESTRUCTURA DE DATOS 
LISTA SIMPLE DE ESTUDIANTES
NOMBRE: Torrico Peredo Jimi Joe 	
MATERIA: Estructura de datos 
CURSO: 2"A" Sis-Inf
INSTRUCCION: lista simple de estudiantes con menu con los siguientes datos: 
nombre 
apellido 
sexo
nota

*/

#include<iostream>
using namespace std;

struct nodoDatos{
    string nombre;
    string apellido;
    char sexo;
    int nota;
    struct nodoDatos* siguiente;
};

struct nodoDatos* lista = NULL;

void insertar_dato(){
    struct nodoDatos* auxiliar;
    string nombre, apellido;
    char sexo;
    int nota;
    
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese el apellido: ";
    cin >> apellido;
    
    while (true) {
        cout << "Ingrese el sexo (M o F): ";
        cin >> sexo;
        if (sexo == 'M' || sexo == 'F') {
            break;
        }
        cout << "Por favor, elegir entre M o F." << endl;
    }
    
    cout << "Ingrese la nota: ";
    cin >> nota;
    
    auxiliar = new struct nodoDatos;
    auxiliar->nombre = nombre;
    auxiliar->apellido = apellido;
    auxiliar->sexo = sexo;
    auxiliar->nota = nota;
    auxiliar->siguiente = NULL;
    
    auxiliar->siguiente = lista;
    lista = auxiliar;
}

void mostrar_lista(){
    struct nodoDatos* auxiliar;
    auxiliar = lista;
    
    cout << "\nLISTA:\n";
    while(auxiliar != NULL){
        cout << "Nombre: " << auxiliar->nombre << endl;
        cout << "Apellido: " << auxiliar->apellido << endl;
        cout << "Sexo: " << auxiliar->sexo << endl;
        cout << "Nota: " << auxiliar->nota << endl;
        cout << endl;
        auxiliar = auxiliar->siguiente;
    }
}

void destruir_lista(){
    struct nodoDatos* auxiliar;
    auxiliar = lista;
    
    cout << "\nDestruyendo la lista..." << endl;
    while(auxiliar != NULL){
        lista = lista->siguiente;
        delete auxiliar;
        auxiliar = lista;
    }
}

int main() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");

        // Texto del men� que se ver� cada vez
        cout << "\n\n\t\t\tMenu de Opciones" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\t1. Insertar dato" << endl;
        cout << "\t2. Mostrar datos" << endl;
        cout << "\t3. Destruir lista" << endl;
        cout << "\t4. Salir" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertar_dato();
                system("pause");  // Pausa despu�s de mostrar la opci�n "Insertar dato"
                break;
            case 2:
                mostrar_lista();
                system("pause");  // Pausa despu�s de mostrar la opci�n "Mostrar datos"
                break;
            case 3:
                destruir_lista();
                system("pause");  // Pausa despu�s de mostrar la opci�n "Destruir lista"
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                repetir = false;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                system("pause");  // Pausa despu�s de mostrar una opci�n inv�lida
                break;
        }
    } while (repetir);

    return 0;
}

