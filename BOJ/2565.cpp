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
\*************  2021-03-30 12:45:56  *************/

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
template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T, class U>
void sort(T& container, U cmp) { sort(container.begin(), container.end(), cmp); }
/*************************************************/


int N;
vpii lines;
vi seq;

int LIS(const vector<int>& arr) {
    vector<int> lis;
    vector<int> idx;
    vector<int> answer;
    lis.emplace_back(arr[0]);
    idx.emplace_back(0);
    for (int i = 1; i < arr.size(); i++) {
        if (lis.back() < arr[i]) {
            lis.emplace_back(arr[i]);
        }
        else {
            auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
            *iter = arr[i];
        }
    }

    return lis.size();
}

void Solve(void) {
    cout << N - LIS(seq);
}

void Init(void) {
    cin >> N;
    lines.resize(N);
    seq.resize(N);
    rep(i, 0, N) {
        cin >> lines[i].fi >> lines[i].se;
    }
    sort(lines, [ ](pii& lhs, pii& rhs) { return lhs.fi < rhs.fi; });

    rep(i, 0, N) {
        seq[i] = lines[i].se;
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}