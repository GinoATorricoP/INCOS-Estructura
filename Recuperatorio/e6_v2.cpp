#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int a[3][3];
	int b[3][3];
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout<<"Ingrese un digito para la matriz: ";
			cin>>a[i][j];
		}
	}
	
	//transpuesta
	
	cout<<"Imprecion de la Res: " ;
	cout<<"\n";
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout<<a[i][j];
		}
		cout<<"\n";
	}
	
		cout<<"Imprecion de la trans: " ;
	cout<<"\n";
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout<<a[j][i];
		}
		cout<<"\n";
	}
	
	getch();
	return 0;
}
