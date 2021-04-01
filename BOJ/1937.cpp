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
\*************  2021-03-31 12:00:06  *************/

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
vvi graph;
vvi cache;

int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };

bool CanGo(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}

int DP(int i, int j) {
    if (cache[i][j]) return cache[i][j];
    int ret = 1;
    rep(k, 0, 4) {
        int y = i + di[k];
        int x = j + dj[k];
        if (CanGo(y, x) && graph[y][x] > graph[i][j]) {
            ret = max(ret, DP(y, x) + 1);
        }
    }
    return cache[i][j] = ret;
}

void Solve(void) {
    int answer = 0;
    rep(i, 0, N) {
        rep(j, 0, N) {
            answer = max(answer, DP(i, j));
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
    graph.resize(N, vi(N));
    cache.resize(N, vi(N));
    rep(i, 0, N) {
        rep(j, 0, N) {
            cin >> graph[i][j];
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}