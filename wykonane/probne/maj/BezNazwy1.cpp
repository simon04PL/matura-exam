#include <iostream>
#include <string>

using namespace std;

int main(){
	char x[1];
	int y;
	string z={"2487"};
	itoa(400,x,9);
	y=stoi(z, nullptr,9);
	cout<<y;
}
