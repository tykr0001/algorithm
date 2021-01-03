#include<iostream>

using namespace std;

int main(void){
	int N, count=0;
	cin >> N;
	if(N < 100) {
		cout << N;
		return 0;	
	}
	else {
		for(int i=N; i>=100; --i){
			int i_hundreds = i / 100;
			int i_tens = (i - i_hundreds * 100) / 10;
			int i_ones = i - i_hundreds * 100 - i_tens * 10;
			
			if(i_hundreds - i_tens == i_tens - i_ones)
				count++;
		}
		cout << count+99;
	}
	return 0;
}
