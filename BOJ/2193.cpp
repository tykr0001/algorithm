#include<iostream>
#include<memory.h> 
#define ll long long

using namespace std;

ll dp[100][2],N;

ll recursive_func(int cur, int pre)
{
	if(cur==N) return 1;
	ll& ret = dp[cur][pre];
	if(ret!=-1){
		return ret;
	}
	
	ret = 0;
	if(pre==1){//이전숫자 1 
        ret += recursive_func(cur+1,0);
	}
	else{//이전숫자 0 
		ret += recursive_func(cur+1,1); // 자릿수 1 
		if(cur!=0){ // 자릿수 2이상 
			ret += recursive_func(cur+1,0);
		}
	}
	return ret;
}

int main(void)
{
	cin >> N;
	memset(dp,-1,sizeof(dp));
	if(N==1) cout << 1 << endl;
	else{
		cout << recursive_func(0,0);
	}
	return 0;
}


/*

1 : 1
2 : 10
3 : 100 101
4 : 1010 1001 1000
5 : 10101 10100 10010 10001 10000
6 : 101010 101001 101000 100101 100100 100010 100001 100000
*/
