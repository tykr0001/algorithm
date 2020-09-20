#include<iostream>

using namespace std;

int num_of_divisor(int N, int divider)
{
	int count=0;
	while(N>=1){
		if(N%5==0) count++;
		if(N%25==0) count++;
		if(N%125==0) count++;
		N--;
	}
	return count;
}

int main(void)
{
	int N,num_five=0;
	cin >> N;
	num_five = num_of_divisor(N,5);
	cout << num_five;
	return 0;
}
