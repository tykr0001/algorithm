#include<iostream>

using namespace std;

int main(void){
	int score, num;
	
	cin >> score;

	num = score / 10;
	
	switch(num){
		case 10, 9 : cout << 'A'; break;
		case 8 : cout << 'B'; break;
		case 7 : cout << 'C'; break;
		case 6 : cout << 'D'; break;
		default : cout << 'F'; break;
	}
	
	return 0;
}
