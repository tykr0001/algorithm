#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
	int N, sum=0;
	int arr[1000]={0};
	cin >> N;
	
	for(int i=0; i<N; ++i){
		cin >> arr[i];
	}
	
	sort(arr, arr+N);
	
	for(int i=0; i<N; ++i){
		sum += (N-i)*arr[i];
	}
	
	cout << sum << endl;
	return 0;
}
