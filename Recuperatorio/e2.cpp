/*Realizar un programa que defina una matriz, de 3x3 y escriba un cicli para que muestre la diagonal principal*/

#include<iostream>
#include<conio.h>


using namespace std;

int main(){
	int t = 0;
	int con = 0;
	cout<<"ingrese el tamaño de la matriz: ";
	cin>>t;
	if(t % 2 != 0){
		
		int numeros[t][t];
	
		for(int i = 0; i<t;i++){
			for(int j = 0; j<t;j++){
				cout<<"ingrese un digito para la matriz :";
				cin>>numeros[i][j];
			}
		}
		
		cout<<"Impresion de la diagonar de la matriz: ";
		cout<<"\n";
		for(int i = 0; i<t;i++){
			for(int j = 0; j<t;j++){
				if(i == j){
					con = con + numeros[i][j];
					cout<<"Posicion : " << i << " - " << j << " : "<< numeros[i][j] <<"\n";
				}
			}
		}
		cout<<"La suma de la diagonal es de : " << con;
	}
	else{
		cout<<"El numero que se introdusca tiene que ser impar";
	}

}
