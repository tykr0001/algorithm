#include<iostream>

using namespace std;

int main(void){
	int N, K, count=0;
	cin >> N >> K;
	int *coin = new int[N];
	for(int i=0; i<N; ++i){
		cin >> coin[i];
	}
	for(int i=N-1; i>=0; --i){
		while(K>=coin[i]){
			K-=coin[i];
			++count;
		}
	}	
	cout << count;
	delete[] coin;
}
