#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
	int N=0,min=0,max=0;
	cin >> N;
	int *arr = new int[N];
	for(int i=0; i<N; ++i){
		cin >> arr[i];
	}
	min = *min_element(arr,arr+N);
	max = *max_element(arr,arr+N);
	cout << min << ' ' << max;
}
