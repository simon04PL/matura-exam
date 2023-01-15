#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int x[2023];
int Temp, Zad1P=0,Zad1N=0, Zad2=0, Zad3, Zad4=0;
int main(){
    ifstream plik;
    plik.open("dane8.txt");
    for(int i=0;i<=2022;i++){
        plik>>x[i];
    }
    //8.1
    for(int i=0;i<=2021;i++){
        if(x[i+1]-x[i]>=0){
            Temp=x[i+1]-x[i];
            if(Temp%2==0){
                Zad1P++;
            }else{
                Zad1N++;
            }
        }else{
            Temp=x[i]-x[i+1];
            if(Temp%2==0){
                Zad1P++;
            }else{
                Zad1N++;
            }
        }
    }
    //8.2
    for(int i=0;i<=2021;i++){
        for(int j=i+1;j<=2022;j++){
            if(x[i]>x[j]){
                Zad2++;
            }
        }
    }
    //8.3
    Temp=1;
    for(int i =0;i<=2022;i++){
        if(x[i]>x[i-1]){
            Temp++;
        }else{
            if(Temp>Zad3){
                Zad3=Temp;
            }
            Temp=1;
        }
    }
    //8.4
    int d[2023];
    fill(d, d+2023, 1);
    for(int i=0;i<=2022;i++){
        for(int j=i-1;j>=0;j--){
            if(x[i]>x[j]){
                if(d[j]+1>d[i]){
                    d[i]=d[j]+1;
                }
            }
        }
    }
    for(int i=0;i<=2022;i++){
        if(Zad4<d[i]){
            Zad4=d[i];
        }
    }
    cout<<"8.1: Parzyste: "<<Zad1P<<" Nieparzyste: "<<Zad1N<<endl;
    cout<<"8.2: "<<Zad2<<endl;
    cout<<"8.3: "<<Zad3<<endl;
    cout<<"8.4: "<<Zad4;
    return 0;
}
