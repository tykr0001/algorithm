#include<iostream>
#include<string>

using namespace std;

int main(void){
	int count=0;
	string str;
	cin >> str;
	for(string::iterator iter = str.begin(); iter < str.end(); ++iter){
		if( (*iter == 'c') && ((*(iter+1) == '=') || (*(iter+1) == '-')) ){
			++iter;
			++count;
		}
		else if( (*iter == 'd') && (*(iter+1) == 'z') && (*(iter+2) == '=') ){
			++iter;
			++iter;
			++count;
		}
		else if( (*iter == 'd') && (*(iter+1) == '-') ){
			++iter;
			++count;
		}
		else if( (*iter == 'l') && (*(iter+1) == 'j') ){
			++iter;
			++count;
		}	
		else if( (*iter == 'n') && (*(iter+1) == 'j') ){
			++iter;
			++count;
		}	
		else if( (*iter == 's') && (*(iter+1) == '=') ){
			++iter;
			++count;
		}
		else if( (*iter == 'z') && (*(iter+1) == '=') ){
			++iter;
			++count;
		}
		else
			++count;
	}
	cout << count;
}
