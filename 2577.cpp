#include<iostream>
#include<string>
#include<sstream>

using namespace std;

string int_to_string(int);

int main(void)
{
	int A=0, B=0, C=0;
	cin >> A >> B >> C;
	string num = int_to_string(A*B*C);
	
	for(int j=0; j<10; ++j){
		int count=0;
		for(int i=0; i<num.length(); ++i)
			if(num[i]-'0'==j) count++;	
		cout << count << endl;
	}
}

string int_to_string(int num){
	stringstream s;
	s << num;
	return s.str();
}
