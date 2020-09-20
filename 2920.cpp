#include<iostream>

using namespace std;

bool ascending(int*);
bool descending(int*);

int main(void){
	int arr[8];
	for(int i=0;i<8;++i){
		cin >> arr[i];
	}
	
	if(ascending(arr)) cout << "ascending";
	else if(descending(arr)) cout << "descending";
	else cout << "mixed";
	
}

bool ascending(int* arr){
	for(int i=0; i<8; ++i)
		if(arr[i] != i+1) return false;
	return true;
}
bool descending(int* arr){
	for(int i=0; i<8; ++i)
		if(arr[i] != 8-i) return false;
	return true;
}

