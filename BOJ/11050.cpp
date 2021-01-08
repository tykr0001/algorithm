#include <bits/stdc++.h>

using namespace std;

int dp[11][11];

int c(int n, int r){
    if(dp[n][r]){
        return dp[n][r];
    }
    if(n==r){
        return 1;
    }
    if(r == 1) {
        return n;
    }
    if(r == 0){
        return 1;
    }

    return dp[n][r] = c(n-1,r-1) + c(n-1,r);
}

int main(void){
    int n,r;
    cin >> n >> r;
    cout << c(n,r);
}