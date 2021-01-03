#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
	int N, sum=0, max;
	float avg;
	cin >> N;
	
	int *arr = new int[N];
	
	for(int i=0; i<N; ++i){
		cin >> arr[i];
		sum += arr[i];
	}
	max = *max_element(arr, arr+N);
	
	avg=(float)sum/(float)N/(float)max*100.0;
	
	cout << avg;
}
