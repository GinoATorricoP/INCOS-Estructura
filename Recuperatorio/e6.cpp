#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int a[3][3];
	int b[3][3];
	
	int ind = 1;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			a[i][j] = ind;
			ind++;
		}
	}
	 ind = 1;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			b[j][i] = ind;
			ind++;
		}
	}
	
	
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
			cout<<b[i][j];
		}
		cout<<"\n";
	}
	
	getch();
	return 0;
}
