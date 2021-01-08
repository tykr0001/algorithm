#include<iostream>
#include<memory.h>
#define ll long long

using namespace std;

ll a[1000000];

/*
ll dp(int length, ll a[])
{
	
	if(a[length] != 0) return a[length];
	
	if(length == 0) return 1;
	if(length == 1) return 1;
	if(length == 2) return 2;

	if(length > 2){
		a[length] += dp(length-1,a);
		a[length] += dp(length-2,a);
	}
	return a[length]%15746;
}

int main(void)
{
	int N;
	cin >> N;
	memset(a,0,sizeof(a));
	cout << dp(N,a) << endl;
}
*/

int main(void)
{
	int N,i;
	cin >> N;
	a[0]=1;
	a[1]=1;
	for(i=2; i<=N; ++i){
		a[i] = a[i-2] + a[i-1];
	}
	cout << a[i];
	
}
