#include<iostream>
#include<string>

using namespace std;

int main(void){
	string str;
	getline(cin,str);
	while(str!="END"){
	   //cin.ignore('\n');
	   for(string::iterator iter=str.end()-1; iter>=str.begin(); --iter){
	   cout << *iter;
	   }
	   cout << endl;
	   getline(cin,str);
	}
	return 0;
}
