#include<iostream>
#define R 3

using namespace std;

void find_max_of_combination(int* arr, int& max, int upper_bound){
	int sum=0;
	for(int i=0; i<R; ++i){
		sum += arr[i];
	}
	
	max = (upper_bound-sum >= 0 && max < sum) ? sum : max;
}

void combination(int* arr, int n, int r, int& max, int upper_bound, int index=0, int level=0){
	static int* temp = new int[R];
	if(r==0){
		find_max_of_combination(temp, max, upper_bound);
	}
	else if(n!=0){
		temp[level] = arr[index++];
		combination(arr,n-1,r-1,max,upper_bound,index,level+1); //  현재거 선택
		combination(arr,n-1,r,max,upper_bound,index,level); // 현재거 선택안함	
	}
	return;
}


int main(void){
	int N, M, temp, max = 0;
	cin >> N >> M;
	int* arr = new int[N];
	for(int i=0; i<N; ++i){
		cin >> arr[i];
	}
	combination(arr,N,R,max,M);
	cout << max;
}
