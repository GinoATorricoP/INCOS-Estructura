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
    cout << "Ingrese el sexo (M o F): ";
    cin >> sexo;
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

int main(){
    int opcion;
    
    do {
        cout << "\nMENU\n";
        cout << "1. Insertar dato\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Destruir lista\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                insertar_dato();
                break;
            case 2:
                mostrar_lista();
                break;
            case 3:
                destruir_lista();
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 4);
    
    return 0;
}

