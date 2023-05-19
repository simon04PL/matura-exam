#include <iostream>
#include <fstream>

using namespace std;

int suma, Max=0, Max2=0, MaxI=0, MaxJ=0;
int A[1000], A2[100000];

void Zad1_3(){
	for(int i=0;i<=999;i++){
		for(int j=0;j<=i-1;j++){
			suma=0;
			for(int k=j;k<=i;k++){
				suma+=A[k];
			}
			if(Max<suma){
				Max=suma;
			}
		}
	}

}
void Zad1_4(){
	for(int i=1;i<=99999;i++){

		suma=A2[i];
		for(int j=i-1;j>=0;j--){
			suma+=A2[j];
		cout<<i<<endl;
		for(int j=0;j<=i-1;j++){
			suma=0;
			for(int k=j;k<=i;k++){
				suma+=A2[k];
			}

			if(Max2<suma){
				Max2=suma;
				MaxI=i+1;
				MaxJ=j+1;
			}
		}
	}
}
int main(){
	ifstream plik1;
	ifstream plik2;
	plik1.open("dane1_3.txt");
	plik2.open("dane1_4.txt");
	for(int i=0;i<=999;i++){
		plik1>>A[i];
	}
	for(int i=0;i<=99999;i++){
		plik2>>A2[i];
	}
	Zad1_3();
	Zad1_4();
	cout<<"1.3: "<<Max<<endl;
	cout<<"1.4: max poczatek: "<<MaxJ<<" Max koniec: "<<MaxI<<endl;
	cout<<"1.4: max i: "<<MaxI<<" MaxJ: "<<MaxJ<<endl;
	cout<<"1.4: max i: "<<MaxI<<" MaxJ: "<<MaxJ<<endl;
}
