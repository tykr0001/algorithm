#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> stairs;
vector<vector<int>> dp; // [i][state]

// state: 0= 1개 이어짐, 1=2개 이어짐
int DP(int i, int state){
    if(i <= 0){
        return 0;
    }
    if(dp[i][state]){
        return dp[i][state];
    }
    if(state==0){
        dp[i][state] = max(DP(i-2, 0), DP(i-2,1)) + stairs[i];
    }
    else{
        dp[i][state] = DP(i-1,0) + stairs[i];
    }

    return dp[i][state];
}

int main(void){
    cin >> N;
    stairs.resize(N+1);
    dp.resize(N+1,vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = 0;
    stairs[0] = 0;
    for(int i=1;i<=N; i++){
        cin >> stairs[i];
    }
    DP(N,0);
    DP(N,1);
    int answer = 0;
    for(int i=1; i<=N; i++){
        answer = max(answer, max(dp[i][0], dp[i][1]));
    }
    cout << answer << endl;
}