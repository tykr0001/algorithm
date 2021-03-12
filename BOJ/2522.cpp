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
\*************  2021-03-13 01:39:58  *************/

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
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define For(i,n) for(int i=0; i<n; i++)
typedef long long ll;
/*************************************************/

int N;

void Star(int n) {
    while (n--) cout << '*';
}
void Blank(int n) {
    while (n--) cout << ' ';
}

void Solve(void) {
    for (int i = 1; i <= N; i++) {
        Blank(N - i);
        Star(i);
        cout << endl;
    }
    for (int i = N - 1; i >= 1; i--) {
        Blank(N - i);
        Star(i);
        cout << endl;
    }
}

void Init(void) {
    cin >> N;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}