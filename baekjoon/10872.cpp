#include<iostream>

using namespace std;

long long factorial(long long);

int main(void){
	int n;
	cin >> n;
	cout << factorial(n);
}

long long factorial(long long n){
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
