#include<iostream>

using namespace std;

int main(void){
	string S;
	
	cin >> S;
	
	for(int i='a'; i<='z'; ++i){
		for(int j=0; j<S.size(); j++){
			if(S[j] == i){
				cout << j << ' ';
				break;
			}
			if(j == S.size()-1){
				cout << -1 << ' ';
			}
		}
	}
	
}
