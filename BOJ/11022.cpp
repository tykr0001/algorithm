#include<iostream>

using namespace std;

int main(void){
	int T=0, A=0, B=0;
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> A >> B;
		printf("Case #%d: %d + %d = %d\n", i, A, B, A+B);
	}
}