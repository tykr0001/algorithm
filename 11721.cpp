#include<iostream>
#include<string>

using namespace std;

int main(void){
	string str;

	cin >> str;

	for(int i=0; i<str.length(); i+=10){
		for(int j=i; j<i+10 && j<str.length(); ++j){
			cout << str[j];
		}
		cout << endl;
	}
}

