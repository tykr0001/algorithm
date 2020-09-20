#include<iostream>
#include<string>

using namespace std;

int length(int num);
string my_to_string(int num);

using namespace std;

int main(void){
	int A, B;
	cin >> A >> B;
	string str_B = my_to_string(B);
	cout << A*int(str_B[2]-'0') << endl;
	cout << A*int(str_B[1]-'0') << endl;
	cout << A*int(str_B[0]-'0') << endl;
	cout << A*B;
}

int length(int num){
	int len = 0;
	do{
		num /= 10;
		len++;
	}while(num>0);
	return len;
}

string my_to_string(int num){
	string ret;
	int len = length(num);
	for(int i=len-1; i>=0; --i){
		ret[i] = num%10 + '0';
		num/=10; 
	}
	return ret;
}


