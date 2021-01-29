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
\*************  2021-01-26 00:34:52  *************/

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

ll n, m, max_memory, max_cost, answer;
v<ll> a;
v<ll> c;
v<ll> cache; // 해당 메모리를 프리할 때 지불하는 최소 코스트

void Solve(void) {
    if (max_memory < m) {
        cout << -1 << endl;
        return;
    }
    for (ll i = 1; i <= n; i++)
        for (ll j = max_memory; j >= a[i]; j--)
            cache[j] = min(cache[j], cache[j - a[i]] + c[i]);
    for (ll i = 1; i <= max_cost; i++) {
        if (cache[i] >= m) {
            answer = min(answer, i);
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> n >> m;
    max_memory = 0;
    max_cost = 0;
    answer = LINF;
    a.clear();
    a.resize(n + 1);
    c.clear();
    c.resize(n + 1);

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        max_memory += a[i];
    }
    for (ll i = 1; i <= n; i++) {
        cin >> c[i];
        max_cost += c[i];
    }

    cache.clear();
    cache.resize(max_memory + 1, LINF);
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