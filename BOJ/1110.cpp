#include<iostream>

using namespace std;

int main(void){
	int num=0, temp=0, count=0;
	cin >> num;
	temp = num;
	do{
		num=num % 10 * 10 + (num/10+num%10)%10;
		count++;
	}while(num!=temp);
	cout << count;
}
