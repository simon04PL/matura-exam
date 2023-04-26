#include <iostream>
#include <fstream>

using namespace std;


int Zad1I, Temp=0, Zad3=0;
int Zad1J[6], y[40], w[40], Zad2P[7][2], Zad2K[7][2];
char x[10][10];

void Zad1_1(){
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			if(x[j][i]=='X'){
				for(int z=j;z<=j+5;z++){
					if(x[z][i]!='X'){
						break;
					}
					if(z==j+5){
						Zad1I=i+1;
						for(int k=0;k<=5;k++){
							Zad1J[k]=j+k+1;
						}
					}
				}
			}
		}
	}
}
void Zad1_2(){
	Temp=0;
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			if(x[j][i]=='X'){
				if(x[j+1][i]=='X'){
					int k=j+1;
					Zad2P[Temp][0]=j;
					Zad2K[Temp][1]=i;
					Zad2P[Temp][1]=i;
					while(x[k][i]=='X'){
						k++;
					}
					Zad2K[Temp][0]=k;
				}else{
					int k=i+1;
					Zad2P[Temp][0]=j;
					Zad2K[Temp][0]=j;
					Zad2P[Temp][1]=i;
					while(x[j][k]=='X'){
						k++;
					}
					Zad2K[Temp][1]=k;
				}
				Temp++;
			}
		}
	}
}
void Zad1_3(){
	Temp=0;
	for(int i=0;i<=39;i++){
		if(x[y[i]-1][w[i]-1]=='X'){
			Temp++;
		}else{
			if(Zad3<Temp){
				Zad3=Temp;
			}
		}
	}
}
int main(){
	ifstream plik1;
	ifstream plik2;
	plik1.open("statki.txt");
	plik2.open("statki_ruchy.txt");
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			plik1>>x[j][i];
		}
	}
	for(int i=0;i<=39;i++){
		plik2>>y[i]>>w[i];
	}
	Zad1_1();
	Zad1_2();
	Zad1_3();
	cout<<"1.1: "<<endl;
	for(int i=0;i<=5;i++){
		cout<<"("<<Zad1J[i]<<", "<<Zad1I<<")"<<endl;
	}
	cout<<"1.2: "<<endl;
	for(int i=0;i<=6;i++){
		cout<<Zad2P[i][0]+1<<" "<<Zad2P[i][1]+1<<" "<<Zad2K[i][0]+1<<" "<<Zad2K[i][1]+1<<endl;
	}
	cout<<"1.3: "<<Zad3;
	return 0;
}
