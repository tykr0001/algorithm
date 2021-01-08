#include<iostream>
#include<memory.h>
#define ll long long

using namespace std;

ll dp[100][2],N;

ll recursive_function(int cur, int pre){
	
	//이전숫자 1 
	//이전숫자 0 
	//길이 1일때 
	
	if(cur==N) return 1;
	ll& ret = dp[cur][pre];
	if(ret!=-1){
		return ret;
	}
	ret = 0;
	if(pre==1){
		ret = recursive_function(cur+1, 0);
	}
	else{
		ret += recursive_function(cur+1, 1);
		if(cur!=0){
			ret += recursive_function(cur+1, 0);
		}
		
	}
	
	return ret;
}

int main(void)
{
	cin >> N;
	memset(dp,-1,sizeof(dp));
	
	if(N==1){
		cout << 1;
	}
	else{
		cout << recursive_function(0,0);
	}
	return 0;
}
