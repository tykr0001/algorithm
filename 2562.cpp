#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
	int* max=NULL;
	int arr[9];
	for(int i=0; i<9; ++i){
		cin >> arr[i];
	}
	max = max_element(arr,arr+9);
	cout << *max << endl << (max-arr) + 1;
}
