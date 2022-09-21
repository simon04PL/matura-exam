#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string klucz1String;
string tjString;
string haslo;
char znakKlucz;
char znakSzyfr;
int index=0;
int lSzyfr;
int lKlucz;

int main() {
	ifstream klucz1;
	ifstream tj;
	tj.open("tj.txt");
	klucz1.open("klucze1.txt");
	while(!tj.eof()){
		klucz1>>klucz1String;
		tj>>tjString;
		lSzyfr=tjString.length();
		lKlucz=klucz1String.length();
		if(lSzyfr<=lKlucz){
			haslo={""};
			for(int i =0;i<=lSzyfr;i++){
				znakKlucz=klucz1String[i];
				znakSzyfr=tjString[i];
				znakSzyfr+=znakKlucz-65;
				cout<<znakSzyfr<<endl;
				if(znakSzyfr>90){
					znakSzyfr-=26;
				}
				haslo[i]=znakSzyfr;
			}
		cout<<haslo<<endl;
		}
	}
	return 0;
}
