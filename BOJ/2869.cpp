#include<iostream>
#include<cmath>

using namespace std;

int main(void){
	int A,B,V;
	cin >> A >> B >> V;
	if((V-A)%(A-B)==0)
		cout << ((V-A)/(A-B))+1 << endl;
	else
		cout << ((V-A)/(A-B))+2 << endl;
}
