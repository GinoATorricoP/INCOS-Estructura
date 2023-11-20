/*matriz que pide el numero de filas y comlumnas y posteriormente mostrar en pantalla*/

#include<iostream>
#include<conio.h>

using namespace std;






int main(){
	int numeros[100][100], filas, columnas;
	cout<<"Digite numero de filas :";
	cin>>filas;
	cout<<"Digite numero de columnas:";
	cin>>columnas;
	
	//almacenando elementos en la matriz
	for(int i = 0;i<filas;i++){
		for(int j = 0;j<columnas;j++){
			cout<<"Digite un numero : ";
			cin>>numeros[i][j];
		}
	}
	
	
	//mostrar elementos en matriz
	for(int i = 0;i<filas;i++){
		for(int j = 0;j<columnas;j++){
			cout<<numeros[i][j];
		}
		cout<<"\n";
	}
	
	getch();
	return 0;
}
