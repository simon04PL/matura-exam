#include <iostream>

using namespace std;

int n,k=-1, a,b, wynik;
int S[10];
char W[100];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		if(W[i]!='+'&&W[i]!='-'&&W[i]!='*'&&W[i]!='/'){
			k++;
			S[k]=W[i];
		}else{
			a=S[k];
			k--;
			b=S[k];
			k--;
			if(W[i]=='+'){
				wynik=a+b;
			}else if(W[i]=='-'){
				wynik=b-a;
			}else if(W[i]=='*'){
				wynik=b*a;
			}else if(W[i]=='/'){
				wynik=b/a;
			}
			k++;
			S[k]=wynik;
		}
	}
	cout<<wynik;
	return 0;
}
