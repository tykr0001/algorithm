#include <iostream>

using namespace std;

string map[11];
int dp[10][1024];
int C,M,N;



int main(void){
    cin >> C;
    while(C--){
        cin >> N >> M;
        for(int i=0;i<M;++i){
            cin >> map[i];
        }
    }
}