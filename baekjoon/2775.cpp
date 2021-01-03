/*
 

1 5 15 35 70
1 4 10 20 35 ...
1 3 6 10 15 21..
1 2 3 4 5 6 7 8 9 10 ....


1 + 1 + 2 + 1 + 2 + 3

1 + (1+ 1 + 2) + (1 + 1 + 2 + 1 + 2 + 3)

1*(1+2+3) + 2*(1+2) + 3*(1)

1Ãþ
1 1000
2 0100
3 0010
4 0001

1 12 123 1234
2Ãþ 
1 1111 
2 0111
3 0011
4 0001

1 112 112123 1121231234
3Ãþ 
1 1234
2 0123
3 0012
4 0001

*/
#include<iostream>
#include<cstring>

using namespace std;

int main(void){
	int T;
	cin >> T;
	for(int i=0; i<T; ++i){
		int k_floor,room_number,sum=0;
		cin >> k_floor >> room_number;
		int** arr = new int*[k_floor+1];
		for(int j=0; j<k_floor+1; ++j){
			arr[j] = new int[room_number+1] {0};
		}
		
		for(int j=0; j<room_number+1; ++j){
			arr[0][j] = j;
		}
		for(int j=1; j<k_floor+1; ++j){
			for(int k=1; k<room_number+1; ++k){
				for(int l=1; l<k+1; ++l){
					arr[j][k] += arr[j-1][l];
				}
			}
		}
		cout << arr[k_floor][room_number] << endl;
	}
}
