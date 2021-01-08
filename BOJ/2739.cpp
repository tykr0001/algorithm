#include<iostream>

using namespace std;

int main(void){
	int num, i;
	cin >> num;
	for (i=1; i<10; ++i) {
		printf("%d * %d = %d\n", num, i, num*i);
	}
	return 0;
}
