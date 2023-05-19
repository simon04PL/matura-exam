#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int Zad1IlePlansz=0, Zad1MaxPustychKolumn=0, Zad2=0, Zad2Max=100, Zad3Czarne=0, Zad3Biale=0;
char x[125][8][8];

multiset<char>Zad2LiczenieBierek;

bool czySzach(int i, int k, int w, char z){
	for(int j=k+1;j<=7;j++){
		if(x[i][j][w]==z){
			return 1;
		}else if(x[i][j][w]!='.'){
			break;
		}
	}
	for(int j=w+1;j<=7;j++){
		if(x[i][k][j]==z){
			return 1;
		}else if(x[i][k][j]!='.'){
			break;
		}
	}
	for(int j=k-1;j>=0;j--){
		if(x[i][j][w]==z){
			return 1;
		}else if(x[i][j][w]!='.'){
			break;
		}
	}
	for(int j=w-1;j>=0;j--){
		if(x[i][k][j]==z){
			return 1;
		}else if(x[i][k][j]!='.'){
			break;
		}
	}
	return 0;
}
void Zad1_1(){
	for(int i=0;i<=124;i++){
		int Temp=0;
		for(int k=0;k<=7;k++){
			for(int w=0;w<=7;w++){
				if(x[i][k][w]!='.'){
					break;
				}
				if(w==7){
					Temp++;
					if(Temp==1){
						Zad1IlePlansz++;
					}
				}
			}
		}
		if(Temp>Zad1MaxPustychKolumn){
			Zad1MaxPustychKolumn=Temp;
		}
	}
}
void Zad1_2(){
	for(int i=0;i<=124;i++){
		for(int w=0;w<=7;w++){
			for(int k=0;k<=7;k++){
				if(x[i][k][w]!='.'){
					Zad2LiczenieBierek.insert(x[i][k][w]);
				}
			}
		}
		if(Zad2LiczenieBierek.count('K')==Zad2LiczenieBierek.count('k')&&Zad2LiczenieBierek.count('W')==Zad2LiczenieBierek.count('w')&&Zad2LiczenieBierek.count('S')==Zad2LiczenieBierek.count('s')&&Zad2LiczenieBierek.count('H')==Zad2LiczenieBierek.count('h')&&Zad2LiczenieBierek.count('G')==Zad2LiczenieBierek.count('g')&&Zad2LiczenieBierek.count('P')==Zad2LiczenieBierek.count('p')){
			Zad2++;
			if(Zad2Max>Zad2LiczenieBierek.count('K')+Zad2LiczenieBierek.count('k')+Zad2LiczenieBierek.count('W')+Zad2LiczenieBierek.count('w')+Zad2LiczenieBierek.count('S')+Zad2LiczenieBierek.count('s')+Zad2LiczenieBierek.count('H')+Zad2LiczenieBierek.count('h')+Zad2LiczenieBierek.count('G')+Zad2LiczenieBierek.count('g')+Zad2LiczenieBierek.count('P')+Zad2LiczenieBierek.count('p')){
				Zad2Max=Zad2LiczenieBierek.count('K')+Zad2LiczenieBierek.count('k')+Zad2LiczenieBierek.count('W')+Zad2LiczenieBierek.count('w')+Zad2LiczenieBierek.count('S')+Zad2LiczenieBierek.count('s')+Zad2LiczenieBierek.count('H')+Zad2LiczenieBierek.count('h')+Zad2LiczenieBierek.count('G')+Zad2LiczenieBierek.count('g')+Zad2LiczenieBierek.count('P')+Zad2LiczenieBierek.count('p');
			}
		}
		Zad2LiczenieBierek.clear();
	}
}
void Zad1_3(){
	for(int i=0;i<=124;i++){
		for(int w=0;w<=7;w++){
			for(int k=0;k<=7;k++){
				if(x[i][k][w]=='K'&&czySzach(i, k, w, 'w')==1){
					Zad3Biale++;
				}
				if(x[i][k][w]=='k'&&czySzach(i, k, w, 'W')==1){
					Zad3Czarne++;
				}
			}
		}
	}
}
int main(){
	ifstream plik;
	plik.open("szachy.txt");
	for(int i=0;i<=124;i++){
		for(int w=0;w<=7;w++){
			for(int k=0;k<=7;k++){
				plik>>x[i][k][w];
			}
		}
	}
	Zad1_1();
	Zad1_2();
	Zad1_3();
	cout<<"1.1:"<<endl<<"Plansz w ktorych przynajmniej jedna kolumna jest pusta: "<<Zad1IlePlansz<<endl<<"Natomiast maksymalna liczba pustych kolumn w jednej planszy wynosi: "<<Zad1MaxPustychKolumn<<endl;
	cout<<"1.2:"<<endl<<"Ile jest planasz w rownowadze: "<<Zad2<<endl<<"Ile najmniejsza liczba bierek: "<<Zad2Max<<endl;
	cout<<"1.3:"<<endl<<"Szachow na bialym krolu, czarna wieza: "<<Zad3Czarne<<endl<<"Szachow na czarnym krolu, biala wieza: "<<Zad3Biale;
	return 0;
}
