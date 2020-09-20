#include<iostream>

using namespace std;

bool prime_number(int N){
	for(int i=2; i<=N/2; ++i){
		if(N%i==0) return false;
	}
	return N>1;
}

int main(void){
	int count=0, N, temp;
	cin >> N;
	for(int i=0; i<N; ++i){
		cin>>temp;
		if(prime_number(temp)) count++;
	}
	cout << count;
}
