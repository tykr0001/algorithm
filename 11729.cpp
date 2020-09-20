#include<iostream>
#include<cmath>

using namespace std;

void hanoi(int level, int start, int end);

int main(void){
	unsigned long long N=0, temp=0;
	
	cin >> N;
	
	for(int i=0; i<N; ++i){
		temp=2*temp+1;
	}
	cout << temp << endl;
	
	hanoi(N, 1, 3);
	
	return 0;
}


void hanoi(int level, int start, int end){
	if(level==1){
		printf("%d %d\n", start, end);
		return;
	}
	hanoi(level-1,start,6-start-end);
	hanoi(1,start,end);
	hanoi(level-1,6-start-end,end);
}
