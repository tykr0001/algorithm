/********* github.com/tykr0001/algorithm *********\
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
*$*                                             *$*
*$*    ||||||||  ||    ||  ||   |||  |||||||    *$*
*$*       ||      ||  ||   || |||    ||    ||   *$*
*$*       ||        ||     |||       |||||||    *$*
*$*       ||        ||     || |||    ||  ||     *$*
*$*       ||        ||     ||   |||  ||   |||   *$*
*$*                                             *$*
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
\*************  2021-01-19 23:50:46  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define v vector 
#define s stack
#define q queue 
#define l list 
#define pq priority_queue 
#define p pair
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define si stack<int>
#define qi queue<int>
#define li list<int> 
#define pii pair<int,int>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2e9
#define LINF 9e18
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int T;

void Solve(void) {
    while (T--) {
        int N;
        string inp;
        cin >> N >> inp;
        vector<int> a(N, 0);
        vector<int> c(N, 0);
        a[0] = 1;
        if(inp[0] == '0'){
            c[0] = 1;
        }
        else{
            c[0] = 2;
        }
        for (int i = 1; i < N; i++) {
            if (inp[i] == '0') {
                if (c[i-1]==0) {
                    a[i] = 1;
                    c[i] = 1;
                }
                else if(c[i-1]==1){
                    a[i] = 0;
                    c[i] = 0;
                }
                else{
                    a[i] = 1;
                    c[i] = 1;
                }
            }
            else {
                if (c[i-1]==0) {
                    a[i] = 1;
                    c[i] = 2;
                }
                else if(c[i-1]==1){
                    a[i] = 1;
                    c[i] = 2;
                }
                else{
                    a[i] = 0;
                    c[i] = 1;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            cout << a[i];
        }
        cout << endl;
    }
    return;
}

void Init(void) {
    Boost;
    cin >> T;
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}