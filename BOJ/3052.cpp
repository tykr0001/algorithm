#include<iostream>
#include<string>

using namespace std;

bool duplicate(int, int*, int);

int main(void){
	int arr[10];

	for(int i=0;i<10;++i){
		cin >> arr[i];
		arr[i] = arr[i]%42;
	}
	
	int count=0;	
	for(int i=0;i<10;++i)
		if(!duplicate(arr[i],arr,i)) {
			count++;
		}
	cout << count;
}

bool duplicate(int num, int* arr, int iter){
	for(int i=0;i<10;++i)
		if(i>iter && arr[i]==arr[iter]) return true;
	return false;
}
