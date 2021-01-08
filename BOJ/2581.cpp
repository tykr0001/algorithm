#include<iostream>

using namespace std;

bool prime_number(int N){
	for(int i=2; i<=N/2; ++i)
		if(N%i==0) return false;
	return N>1;
}

int main(void){
	int M,N,sum=0,min=N;
	cin >> M >> N;
	for(int i=N; i>=M; --i){
		if(prime_number(i)){
			sum+=i;
			min=i;	
		}
	}
	if(sum==0){
		cout << -1 << endl;
	}
	else
		cout << sum << endl << min << endl;
	return 0;
}
