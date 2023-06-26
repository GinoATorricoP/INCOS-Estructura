/*ESTRUCTURA DE DATOS 
EJEMPLOS MENU
NOMBRE: Torrico Peredo Jimi Joe 	
MATERIA: Estructura de datos 
CURSO: 2"A" Sis-Inf
*/
#include <iostream>
#include <cstdlib>

using namespace std;

// Prototipos de las funciones
void sumar();
void restar();
void multiplicar();
void dividir();

int main()
{
    int opcion;
    bool repetir = true;

    do
    {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\n\n\t\t\tMenu de Opciones" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\t1. Sumar dos numeros" << endl;
        cout << "\t2. Restar dos numeros" << endl;
        cout << "\t3. Multiplicar dos numeros" << endl;
        cout << "\t4. Dividir dos numeros" << endl;
        cout << "\t0. SALIR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        int numero1, numero2;
        float resultado;
        switch (opcion)
        {
        case 1:
            sumar();
            break;

        case 2:
            restar();
            break;

        case 3:
            multiplicar();
            break;

        case 4:
            dividir();
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);

    return 0;
}

// Definiciones de las funciones
void sumar()
{
    int numero1, numero2;
    float resultado;

    cout << "\n\tIngrese primer numero: ";
    cin >> numero1;

    cout << "\tIngrese segundo numero: ";
    cin >> numero2;

    cout << "\t---------------------------" << endl;
    resultado = numero1 + numero2;
    cout << "\tResultado: " << resultado << endl;

    system("pause>nul");
}

void restar()
{
    int numero1, numero2;
    float resultado;

    cout << "\n\tIngrese primer numero: ";
    cin >> numero1;

    cout << "\tIngrese segundo numero: ";
    cin >> numero2;

    cout << "\t---------------------------" << endl;
    resultado = numero1 - numero2;
    cout << "\tResultado: " << resultado << endl;

    system("pause>nul");
}

void multiplicar()
{
    int numero1, numero2;
    float resultado;

    cout << "\n\tIngrese primer numero: ";
    cin >> numero1;

    cout << "\tIngrese segundo numero: ";
    cin >> numero2;

    cout << "\t---------------------------" << endl;
    resultado = numero1 * numero2;
    cout << "\tResultado: " << resultado << endl;

    system("pause>nul");
}

void dividir()
{
    int numero1, numero2;
    float resultado;

    cout << "\n\tIngrese primer numero: ";
    cin >> numero1;

    cout << "\tIngrese segundo numero: ";
    cin >> numero2;

    cout << "\t---------------------------" << endl;

    if (numero2 == 0)
    {
        cout << "\tResultado: No se puede dividir por cero." << endl;
    }
    else
    {
        resultado = numero1 / (numero2 * 1.0);
        cout << "\tResultado: " << resultado << endl;
    }

    system("pause>nul");
}
