#include<iostream>

using namespace std;

int main(void){
	
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	int T, A, B;
	
	cin >> T;
	
	while(T!=0){
		cin >> A >> B;
		cout << A+B << endl;
		T--;
	}
	
	return 0;
}
