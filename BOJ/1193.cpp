/*
2 1
3 2 3
4 4 5 6
5 7 8 9 10
6 11 12 13 14 15
*/
#include<iostream>

using namespace std;

int main(void){
	int N,temp,i=1;
	cin >> N;
	temp = N;
	while(temp>0){
		temp-=i;
		++i;
	}
	if(i%2==0) cout << 1-temp << "/" << i-1+temp;
	else cout << i-1+temp << "/" << 1-temp;
	return 0;
}// ºÁµµµÅ 
