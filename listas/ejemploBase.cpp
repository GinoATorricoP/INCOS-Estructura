#include<iostream>
using namespace std;


struct nodoInt{
	int dato;
	struct nodoInt * siguiente; 	
};

struct nodoInt * lista;
//struct nodoInt * lista=NULL;

void insertar_dato(){
	struct nodoInt * auxiliar;
	int x;
	cout<<"NUMERO A INGRESAR A LA LISTA" ;
	cin>>x;
	auxiliar = new struct nodoInt;
	auxiliar->dato =x ;
	auxiliar->siguiente = NULL;
	
	auxiliar-> siguiente = lista;
	lista=auxiliar;
}

void mostrar_lista(){
	struct nodoInt * auxiliar;
	auxiliar = lista;
	cout<<"\n LISTA: ";
	while(auxiliar !=NULL){
		cout<<auxiliar -> dato<<", ";
		auxiliar = auxiliar-> siguiente;
	}
}

void destruir_lista(){
	struct nodoInt * auxiliar;
	auxiliar = lista;
	cout <<"\n destruyendo la lista ...";
	while(auxiliar !=NULL){
		lista = lista -> siguiente;
		delete auxiliar ;
		auxiliar = lista;
	}
}

int main(){
	insertar_dato();
	mostrar_lista();
	
	insertar_dato();
	mostrar_lista();
	
	insertar_dato();
	mostrar_lista();
		
	destruir_lista();
}


