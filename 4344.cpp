#include<iostream>
#include<iomanip>

using namespace std;

int main(void){
	int C;
	cin >> C;
	
	for(int i=0; i<C; ++i){
		int N, sum=0, count=0;
		float avg, percentage;
		cin >> N;
		int *arr = new int[N];
		
		for(int j=0; j<N; ++j){
			cin >> arr[j];
			sum += arr[j];
		}
		avg = float(sum) / float(N);
		
		cout << sum << endl;
		cout << N << endl;
		cout << avg << endl;
		
		for(int j=0; j<N; ++j){
			if(arr[j]>avg) count++;
		}
		percentage = (float)count / (float)N * 100.0;
		cout.precision(3);
		cout << fixed;
		cout << percentage << '\%' << endl;
		delete[] arr;
	}
	return 0;
}
