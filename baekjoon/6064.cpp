#include<iostream>

using namespace std;

int main(void){
	int T,M,N,x,y;
	cin >> T;
	/*
	for(int i=0; i<T; ++i){
		cin >> M >> N >> x >> y;
		if(x>M || y>N) cout << -1;
		int j,k;
		for(j=0; j<N; ++j){
			for(k=0; k<M; ++k){
				if(x+j*M == y+k*N){
					break;
				}
			}
			if(k!=M) break;
		}
		if(j==N || k==M) cout << -1 << endl;
		else cout << x+j*M << endl;
	}
	return 0;
	*/
	for(int i=0; i<T; ++i){
		cin >> M >> N >> x >> y;
		int temp_left=x,temp_right=y;
		while(temp_left != temp_right){
			if(temp_left>temp_right) temp_right += N;
			else temp_left += M;
		 	
			if(temp_left > M*N || temp_right > M*N){
			 	break;
			}
		}
		if(temp_left > M*N || temp_right > M*N){
			cout << -1 << endl;
		}
		else cout << temp_left << endl;
	}
	return 0;
}
