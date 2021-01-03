#include<iostream>

using namespace std;

bool prime_number(int N){
	for(int i=2; i<=N/2; ++i)
		if(N%i==0) return false;
	return N>1;
}

int main(void){
	int n,count;
	cin >> n;
	while(n!=0){
		count=0;
		for(int i=n+1; i<=2*n; ++i){
			if(prime_number(i)){
				count++;	
			}
		}
	cout << count << endl;
	cin >> n;
	}
	return 0;
}
