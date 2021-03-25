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
\*************  2021-03-25 12:48:19  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vc = vector<char>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pair<int, int>>;
using vvpii = vector<vector<pair<int, int>>>;
using vpll = vector<pair<ll, ll>>;
using vvpll = vector<vector<pair<ll, ll>>>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
/*************************************************/
#define MOD 9901

int N;
vvi cache;
vi prefix_sum;

void Solve(void) {
    cache[1][0] = 1;
    cache[1][1] = 1;
    prefix_sum[1] = cache[1][0] + cache[1][1];
    rep(i, 2, N + 1) {
        cache[i][0] = (prefix_sum[i - 2] + cache[i - 1][1] + 1) % MOD;
        cache[i][1] = (prefix_sum[i - 2] + cache[i - 1][0] + 1) % MOD;
        prefix_sum[i] = (prefix_sum[i - 1] + cache[i][0] + cache[i][1]) % MOD;
    }
    prefix_sum[N]++;
    cout << prefix_sum[N] % MOD << endl;
}

void Init(void) {
    cin >> N;
    cache.resize(N + 1, vi(2));
    prefix_sum.resize(N + 1);
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}