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
\*************  2021-01-15 22:56:51  *************/

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
#define MOD 1000000007
ll n, k;
v<ll> a;
v<v<ll>> cache(1001, v<ll>(1001));

ll c(int N, int R) {
    if (cache[N][R]) {
        return cache[N][R];
    }
    if (N == R) {
        return 1;
    }
    if (R == 1) {
        return N;
    }
    if (R == 0) {
        return 1;
    }
    return (c(N - 1, R - 1) + c(N - 1, R)) % MOD;
}

void Solve(void) {
    sort(a.begin(), a.end(), greater<int>());
    v<ll> ans;
    ans.emplace_back(0);
    int i;
    for (i = 1; i < k; i++) {
        if (a[i] != a[i - 1]) {
            ans.emplace_back(i);
        }
    }
    while (i < a.size() && a[i] == a[i - 1]) {
        i++;
    }
    ans.emplace_back(i);
    ll idx = ans.size() - 1;
    ll answer = c(ans[idx] - ans[idx - 1], k - ans[idx - 1]);
    cout << answer << endl;
}

void Init(void) {
    cin >> n >> k;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
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