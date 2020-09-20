#include<iostream>

using namespace std;

int main(void){
	int H=0, M=0;
	cin >> H >> M;
	if(M<45){
		M+=15;
		H-=1;
	}
	else
		M-=45;
	if(H<0)
		H+=24;
	cout << H << ' ' << M;
}
