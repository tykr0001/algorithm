#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int length(int num){
	int len = 0;
	do{
		num /= 10;
		len++;
	}while(num>0);
	return len;
}

int multiple_square(int N){ //return 10^N
	int ret=1;
	for(int i=0; i<N; ++i){
		ret *= 10;
	}
	return ret;
}

int include(int num, int* arr, int size){
	for(int i=0; i<size; ++i){
		if(num == arr[i]) return 1;
	}
	return 0;
}

string my_to_string(int num){
	string ret;
	int len = length(num);
	for(int i=len-1; i>=0; --i){
		ret[i] = num%10 + '0';
		num/=10; 
	}
	return ret;
}



int main(void){
	int N=0, M=0, len=0, count=0;

	cin >> N >> M;
	
	len = length(N);
	
	int* nums = new int[10*multiple_square(len)];
	int* arr = new int[M];
	
	int min = 100*multiple_square(len);
	
	for(int i=0; i<M; ++i){
		cin >> arr[i];
	}
	
	for(int i=0; i<10*multiple_square(len); ++i){
		int j;
		string str_num = my_to_string(i);
		for(j=0; j<length(i); ++j){
			if(include(str_num[j]-'0', arr, M)) break;
		}
		if(!(j<length(i))){
			nums[count++] = i;
		}
	}
	
	for(int i=0; i<count; ++i){
		int temp = length(nums[i]) + abs(N - nums[i]) ;
		if(min > temp) min = temp;
	}
	
	if(min > abs(N-100))
 		cout << abs(N-100);
	else
		cout << min;
	return 0;
}
