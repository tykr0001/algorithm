#include <iostream>

using namespace std;

typedef long long LL;

LL n_1, n_2;

// S(n_1,n_2) = {2^(2^n_1) + 1 ~ 2^(2^n_2) + 1}

LL dp[10001];

LL Ex(LL a, LL x){
    if(x==0){
        return 1;
    }
    else if(x==1){
        return a;
    }
    if(dp[x])
        return dp[x];
    LL tmp = Ex(a,x/2);
    if(x%2){
        return dp[x] = tmp*tmp*a;
    }
    else{
        return dp[x] = tmp*tmp;
    }
}

LL P(LL n){
    int ret = 1;
    for(int i=0; i<=n; i++){
        ret *= Ex(2,i);
    }
}

int main(void){
    cin >> n_1 >> n_2;
    
}