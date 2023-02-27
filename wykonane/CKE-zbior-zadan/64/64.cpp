#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int Zad1L=0, Zad1C=0, Temp, Zad2=0, Zad2Temp=201, Zad3P=0, Zad3NP=0, Zad3NN=0, Zad3Temp=0,Zad3Temp1=0, Zad3Max=0, Zad4TempW=20, Zad4TempK=20;
char x[200][21][21];

bool czyWierszPoprawny(int nrO, int w){
    int ileJedynek=0;
    for(int k=0;k<=19;k++){
        if(x[nrO][k][w]=='1'){
            ileJedynek++;
        }
    }
    if(ileJedynek%2==0&&x[nrO][20][w]=='0'||ileJedynek%2==1&&x[nrO][20][w]=='1'){
        return 1;
    }
    return 0;
}
bool czyKolumnaPoprawna(int nrO, int k){
    int ileJedynek=0;
    for(int w=0;w<=19;w++){
        if(x[nrO][k][w]=='1'){
            ileJedynek++;
        }
    }
    if(ileJedynek%2==0&&x[nrO][k][20]=='0'||ileJedynek%2==1&&x[nrO][k][20]=='1'){
        return 1;
    }
    return 0;
}
int main(){
    ifstream plik;
    plik.open("dane_obrazki.txt");
    vector<int>Zad4;
    vector<int>Zad4W;
    vector<int>Zad4K;
    for(int i=0;i<=199;i++){
        for(int j=0;j<=19;j++){
            for(int z=0;z<=20;z++){
                plik>>x[i][z][j];
            }
        }
        for(int j=0;j<=19;j++){
            plik>>x[i][j][20];
        }
    }
    //64.1    
	for(int i=0;i<=199;i++){
        Temp=0;
        for(int j=0;j<=19;j++){
            for(int z=0;z<=19;z++){
                if(x[i][z][j]=='1'){
                    Temp++;
                }
            }
        }
        if(Temp>200){
            Zad1L++;
            if(Temp>Zad1C){
                Zad1C=Temp;
            }
        }
    }
    //64.2    
	for(int i=0;i<=199;i++){
        Temp=0;
        for(int j=0;j<=9;j++){
            for(int z=0;z<=9;z++){
                if(x[i][z][j]==x[i][z+10][j+10]&&x[i][z][j]==x[i][z+10][j]&&x[i][z][j]==x[i][z][j+10]){
                    Temp++;
                }
            }
        }
        if(Temp==100){
            Zad2++;
            if(Zad2Temp==201){
                Zad2Temp=i;
            }
        }
    }
    //64.3/4   
	for(int i=0;i<=199;i++){
        Zad3Temp=0;
        Zad3Temp1=0;
        for(int j=0;j<=19;j++){
            if(czyKolumnaPoprawna(i, j)==0){
                Zad3Temp++;
                Zad4TempK=j;
            }
            if(czyWierszPoprawny(i, j)==0){
                Zad3Temp1++;
                Zad4TempW=j;
            }
        }
        if(Zad3Temp==0&&Zad3Temp1==0){
            Zad3P++;
        }else if(Zad3Temp<=1&&Zad3Temp1<=1){
        	Zad3NP++;
        	Zad4.push_back(i+1);
        	Zad4W.push_back(Zad4TempW+1);
        	Zad4K.push_back(Zad4TempK+1);
        	Zad4TempW=20;
        	Zad4TempK=20;
		}else{
			Zad3NN++;
			if(Zad3Max<Zad3Temp+Zad3Temp1){
				Zad3Max=Zad3Temp+Zad3Temp1;
			}
		}
	}
    cout<<"64.1: Liczba takich obrazkow: "<<Zad1L<<" Najwiecej czarnych pixeli: "<<Zad1C<<endl;
    cout<<"64.2: Liczba obrzazow rekurencyjnych: "<<Zad2<<" Pierwszy ciag rekurencyjny: "<<endl;
    for(int i=0;i<=19;i++){
        for(int j=0;j<=19;j++){
            cout<<x[Zad2Temp][j][i];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"64.3: poprawne: "<<Zad3P<<" naprawialny: "<<Zad3NP<<" nienaprawialny: "<<Zad3NN<<" maxymalna ilosc niepoprawnych: "<<Zad3Max<<endl;
    cout<<"64.4: "<<endl;
    for(int i=0;i<=Zad4.size()-1;i++){
    	cout<<" Nr. obrazka: "<<Zad4[i]<<" Nr. wiersza do zmiany: "<<Zad4W[i]<<" Nr. kolumny do zmiany: "<<Zad4K[i]<<endl;
	}
    return 0;
}
