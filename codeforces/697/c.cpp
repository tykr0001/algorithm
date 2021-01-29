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
\*************  2021-01-26 01:05:46  *************/

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

int a, b, k, answer;
v<pii> pairs;
vi boys;
vi girls;

void Solve(void) {
    for (int i = 0; i < k; i++) {
        answer += k - boys[pairs[i].fi] - girls[pairs[i].se] + 1;
    }
    cout << answer / 2 << endl;
}

void Init(void) {
    cin >> a >> b >> k;
    answer = 0;
    pairs.clear();
    pairs.resize(k);
    boys.clear();
    boys.resize(a + 1, 0);
    girls.clear();
    girls.resize(b + 1, 0);
    for (int i = 0; i < k; i++) {
        int boy;
        cin >> boy;
        boys[boy]++;
        pairs[i].fi = boy;
    }
    for (int i = 0; i < k; i++) {
        int girl;
        cin >> girl;
        girls[girl]++;
        pairs[i].se = girl;
    }
}

int main(void) {
    Boost;
    int T;
    cin >> T;
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}