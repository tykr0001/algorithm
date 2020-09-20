#include<iostream>

using namespace std;
/*
int length(int num){
	int len = 0;
	do{
		num /= 10;
		len++;
	}while(num>0);
	return len;
}
*/
int include(int num, int* arr, int size){
	for(int i=0; i<size; ++i){
		if(num == arr[i] - '0') return 1;
	}
	return 0;
}


int main(void){
	string N;
	int M=0, temp=0, len=0;

	string min, max;

	cin >> N >> M;

	int* arr = new int[M];

	for(int i=0; i<M; ++i){
		cin >> arr[i];
	}

	if(!include(N[0] - '0', arr, sizeof(arr))){
		min[0] = N[0];
		max[0] = N[0];
	}
	else{
		min[0] = N[0] - 1;
		max[0] = N[0] + 1;
	}

	for(int i=1; i<len; ++i){
		if(min[i-1] < N[i-1]){
			for(int j=0; j<10; ++j){
				if(!include(j, arr, sizeof(arr)))
					min[i] = j;
			}
		}
		else{
		 	if(!include(N[i] - '0', arr, sizeof(arr))){
				min[i] = N[i];
			}
			else{
				
			}
		}							
	}
} 
