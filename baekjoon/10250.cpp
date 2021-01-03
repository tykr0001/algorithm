#include<iostream>

using namespace std;

int main(void){
	int T,height,width,number;
	cin >> T;
	for(int i=0; i<T; ++i){
		cin >> height >> width >> number;
		if(number%height==0){
			cout << height;
			if(number/height<10)
				cout << 0 << number/height << endl;
			else
				cout << number/height << endl;
		}
		else{
			cout << number % height;
			if(number/height<9)
				cout << 0 << number/height + 1 << endl;
			else
				cout << number/height + 1 << endl;
		}
	}
}
