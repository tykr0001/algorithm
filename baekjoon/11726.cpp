#include<iostream>
#include<memory.h> 
#define ll long long

using namespace std;

ll dp[2000], N;

ll recursive_function(int currentPosition)
{
	if(currentPosition == N)	//남은길이 0 
		return 1;
		
	ll& ret = dp[currentPosition];
	if(ret!=-1){
		return ret;
	}
	
	ret = 0;
	if(currentPosition == N-1){	//남은길이 1 
		ret += recursive_function(currentPosition+1);
	}
	else{						//남은길이 2이상
		ret += recursive_function(currentPosition+1);
		ret += recursive_function(currentPosition+2);
	}
	
	return ret%10007;
}
	
int main(void)
{
	cin >> N;
	memset(dp,-1,sizeof(dp));
	if(N==1) cout << 1;
	else{
		cout << recursive_function(0);
	}
	
	return 0;
}
