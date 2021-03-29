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
\*************  2021-03-28 20:22:54  *************/

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

int N;
vvi meetings;
vi cache;

void Solve(void) {
    rep(i, 0, N) {
        cache[i + 1] = max(cache[i + 1], cache[i]);
        int j = lower_bound(meetings.begin(), meetings.end(), vi { meetings[i][1],0,0 }) - meetings.begin();
        cache[j] = max(cache[j], cache[i] + meetings[i][2]);
        j++;
    }
    cout << cache[N];
}

void Init(void) {
    cin >> N;
    meetings.resize(N, vi(3));
    cache.resize(N + 1);
    rep(i, 0, N) {
        cin >> meetings[i][0] >> meetings[i][1] >> meetings[i][2];
    }
    sort(meetings.begin(), meetings.end(), [ ](const vi& lhs, const vi& rhs) { return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[1] < rhs[1]; });
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}