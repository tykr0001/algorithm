#include<iostream>
#include<memory.h>
#define ll long long

using namespace std;

ll a[100];

ll dp(int index, ll a[])
{
	
	if(a[index] != 0) return a[index];
	
	if(index == 1) return 1;
	if(index == 2) return 1;
	if(index == 3) return 1;
	if(index == 4) return 2;
	if(index == 5) return 2;

	if(index > 5){
		a[index] += dp(index-5,a);
		a[index] += dp(index-1,a);
	}
	return a[index];
}

int main(void)
{
	int T, N;
	cin >> T;
	memset(a,0,sizeof(a));
	for(int i=0; i<T; ++i){
		cin >> N;
		cout << dp(N,a) << endl;
	}
	return 0;
}

