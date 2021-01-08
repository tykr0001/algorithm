#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int N, M;
	
	cin >> N;
	int* arr_n = new int[N];
	
	for(int i=0; i<N; ++i){
		cin >> arr_n[i];
	}
	sort(arr_n, arr_n+N);
	
	cin >> M;
	int* arr_m = new int[M];
	
	for(int i=0; i<M; ++i){
		cin >> arr_m[i];
	}
	
	for(int i=0; i<M; ++i){
		if(binary_search(arr_n, arr_n+N, arr_m[i]))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	
	return 0;
}
