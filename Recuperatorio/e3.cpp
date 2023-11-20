#include<iostream>
#include<conio.h>


using namespace std;

int main (){
	int mat [2][2];
	int res [2][2];
	
	for(int i= 0; i<2; i++){
		for(int j= 0; j<2; j++){
			cout<<"ingrese valor: ";
			cin>>mat[i][j];
		}
	}
	
	for(int i= 0; i<2; i++){
		for(int j= 0; j<2; j++){
			res[i][j] = mat[i][j];
		}
	}
	
	cout<<"Imprecion de la MaT: " ;
	cout<<"\n";
	for(int i= 0; i<2; i++){
		for(int j= 0; j<2; j++){
			cout<<mat[i][j];
		}
		cout<<"\n";
	}
	
	cout<<"Imprecion de la Res: " ;
	cout<<"\n";
	for(int i= 0; i<2; i++){
		for(int j= 0; j<2; j++){
			cout<<res[i][j];
		}
		cout<<"\n";
	}
	
	
}
