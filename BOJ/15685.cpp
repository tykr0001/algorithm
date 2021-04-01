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
\*************  2021-03-31 12:34:28  *************/

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
int answer;
vvi graph(101, vi(101));
vvi curve(11);
int di[4] = { 0,-1,0,1 };
int dj[4] = { 1,0,-1,0 };


void Solve(void) {
    cin >> N;
    while (N--) {
        int j, i, d, g;
        cin >> j >> i >> d >> g;
        graph[i][j] = 1;
        rep(k, 0, curve[g].size()) {
            i += di[(curve[g][k] + d) % 4];
            j += dj[(curve[g][k] + d) % 4];
            graph[i][j] = 1;
        }
    }

    rep(i, 0, 100) {
        rep(j, 0, 100) {
            if (graph[i][j] == 1 && graph[i + 1][j] == 1 && graph[i][j + 1] == 1 && graph[i + 1][j + 1] == 1)
                answer++;
        }
    }
    cout << answer << endl;
}

void Init(void) {
    curve[0] = { 0 };
    rep(i, 1, 11) {
        curve[i] = curve[i - 1];
        rep(j, 0, curve[i - 1].size())
            curve[i].emplace_back((curve[i - 1][curve[i - 1].size() - 1 - j] + 1) % 4);
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}