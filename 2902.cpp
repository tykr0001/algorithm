#include<iostream>
#include<string>

using namespace std;

int main(void){
	string str;
	getline(cin,str);
	cout << *str.begin();
	for(string::iterator iter=str.begin(); iter < str.end(); ++iter){
		if(*(iter-1)=='-') cout << *iter;	
	}
	return 0;
}
