#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

typedef long long LL;

vector<LL> f(MAX);
vector<LL> g(MAX);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for(int i=1; i<=1000000; i++){
        for(int j=1; i*j<=1000000; j++){
            f[i*j] += i;
        }
    }
    for(int i=1; i<=1000000; i++){
        g[i] = g[i-1] + f[i];
    }
    while(T--){
        int N;
        cin >> N;
        cout << g[N] << '\n';
    }
}