#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string klucz1String;
string tjString;
string klucz2String;
string szString;
int index=0;
int lSzyfr;
int lKlucz;
int j =0;

int main() {
	ifstream klucz1;
	ifstream tj;
	ofstream haslo;
	tj.open("tj.txt");
	klucz1.open("klucze1.txt");
	haslo.open("wynik4a.txt");
	while(!tj.eof()){
		klucz1>>klucz1String;
		tj>>tjString;
		lSzyfr=tjString.length();
		lKlucz=klucz1String.length();
		if(lSzyfr<=lKlucz){
			for(int i =0;i<=lSzyfr;i++){
				tjString[i]+=klucz1String[i]-65;
				if(tjString[i]>90){
					tjString[i]-=26;
				}
			}
		}else{
			j=0;
			for(int i =0;i<=lSzyfr;i++){
				if(j<=lKlucz){
					tjString[i]+=klucz1String[j]-65;
					if(tjString[i]>90){
						tjString[i]-=26;
					}
					j++;
					if(j==lKlucz){
						j=0;
					}
				}
			}
		}
		haslo<<tjString<<endl;
	}
	ifstream klucz2;
	ifstream sz;
	ofstream odszyfrowanie;
	klucz2.open("klucze2.txt");
	sz.open("sz.txt");
	odszyfrowanie.open("wynik4b.txt");
	while(!sz.eof()){
		klucz2>>klucz2String;
		sz>>szString;
		lSzyfr=szString.length();
		lKlucz=klucz2String.length();
		if(lSzyfr<=lKlucz){
			for(int i =0;i<=lSzyfr;i++){
				szString[i]-=klucz2String[i]-65;
				if(szString[i]<65){
					szString[i]+=26;
				}
			}
		}else{
			j=0;
			for(int i =0;i<=lSzyfr;i++){
				if(j<=lKlucz){
					szString[i]-=klucz2String[j]-65;
					if(szString[i]<65){
						szString[i]+=26;
					}
					j++;
					if(j==lKlucz){
						j=0;
					}
				}
			}
		}
		odszyfrowanie<<szString<<endl;
	}
	return 0;
}
