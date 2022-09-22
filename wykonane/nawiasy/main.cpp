#include <iostream>
#include <stack>
#include <string>

using namespace std;

string x;
int l;
int main() {
    stack<char> y;
    cin>>x;
    l=x.length();
    for(int i =0;i<=l-1;i++){
        if(i==0||y.empty()==0){
            if(x[i]=='('){
                y.push('(');
            }else if(x[i]==')'){
                y.pop();
            }else{
                cout<<"bledny znak"<<endl;
            }
        }else{
            y.push('b');
            break;
        }
    }
    if(y.empty()==1){
        cout<<"Poprawny stos"<<endl;
    }else{
        cout<<"bledne wyrazenie"<<endl;
    }
    return 0;
}
