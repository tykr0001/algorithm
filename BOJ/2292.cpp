#include<iostream>

using namespace std;

int main(void){
	int N,i=1;
	cin >> N;
	while(N-1>0){
		N-=i*6;
		++i;
	}
	cout << i;
} 
