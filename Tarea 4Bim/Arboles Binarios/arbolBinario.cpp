#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

//creacion de nodos

Nodo *crearNodo(int);
Nodo *arbol = NULL;


//funcion insertar nodos en el arbol
void insertarNodo(Nodo *&arbol, int n){
	if(arbol == NULL){//si el arbol esta vacio creamos un nodo e insertamos el dato en la raiz
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;//de esta manera lo insertamos en la raiz
	}
	else{//en caso de que no este vacio el arbol
		int valorRaiz = arbol->	dato;
		if(n < valorRaiz){//si es menos, insertamos a la izq
			insertarNodo(arbol->izq, n);
		}
		else{//si es mayor a la raiz, insetamos en la derecha
			insertarNodo(arbol->der, n);
		}
	}
}

//menu
void menu(){
	int dato, opcion;
	do{
		cout<<"\t.:Menu:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Salir"<<endl;
		cout<<"Digite la opcion que desea";
		cin>>opcion;
		
		switch(opcion){
			case 1 : cout<<"\nDigite un numero: ";
					cin>>dato;
					insertarNodo(arbol, dato);//insertamos dato
					cout<<"\n";
					system("pause");
					break;
		}
		system("cls");
	}while(opcion !=2);
}

int main(){
	menu();
	getch();
	return 0;
}

//funcion crear un nuevo nodo

Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
}
