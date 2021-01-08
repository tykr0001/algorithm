#include<iostream>
#include<string>

using namespace std;

int main(void){
	int M,N,count=0,min=64;
	cin >> M >> N;
	string* chess = new string[M];
	for(int i=0; i<M; ++i){
		cin >> chess[i];	
	}
	
	for(int i=0; i<=M-8; ++i){
		for(int j=0; j<=N-8; ++j){
			
			for(int k=i; k<i+8; ++k){
				for(int l=j; l<j+8; ++l){
					if((k-i)%2 == 0){
						if((l-j)%2 == 0){
							if(chess[i][j] != chess[k][l]) count++;
						}
						else{
							if(chess[i][j] == chess[k][l]) count++;
						}
					}
					else{
						if((l-j)%2 != 0){
							if(chess[i][j] != chess[k][l]) count++;
						}
						else{
							if(chess[i][j] == chess[k][l]) count++;
						}
					}
				}
			}
			if(count >= 32) count = 64-count;
			if(count < min) min = count;
			count = 0;
		}
	}
	cout << min;
	return 0;
}
