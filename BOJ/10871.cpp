#include<iostream>

using namespace std;

int main(void){
	int N, X;
	int *arr = new int[N];
	if(!arr) cout << "할당실패" << endl; 
	cin >> N >> X;
	for(int i=0; i<N; ++i){
		cin >> arr[i];
	}

	for(int i=0; i<N; ++i){
		if(arr[i]<X) cout << arr[i] << ' ';
	}
	cout << endl;
	
	return 0;
}
