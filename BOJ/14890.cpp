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
\*************  2021-03-25 13:20:04  *************/

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

int N, L;
int answer;
vvi graph;
vvb cache;

void Solve(void) {
    rep(i, 0, N) {
        bool flag = true;
        rep(j, 0, N) {
            cache[i][j] = false;
        }
        rep(j, 1, N) {
            if (graph[i][j - 1] == graph[i][j]) {
                continue;
            }
            else if (graph[i][j - 1] - graph[i][j] == 1) {
                rep(k, j, j + L) {
                    if (!(k < N) || cache[i][k] || graph[i][j - 1] - graph[i][k] != 1) {
                        flag = false;
                        break;
                    }
                    cache[i][k] = true;
                }
            }
            else if (graph[i][j] - graph[i][j - 1] == 1) {
                rep(k, j - L, j) {
                    if (!(0 <= k) || cache[i][k] || graph[i][j] - graph[i][k] != 1) {
                        flag = false;
                        break;
                    }
                    cache[i][k] = true;
                }
            }
            else {
                flag = false;
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            answer++;
        }
    }

    rep(j, 0, N) {
        bool flag = true;
        rep(i, 0, N) {
            cache[i][j] = false;
        }
        rep(i, 1, N) {
            if (graph[i - 1][j] == graph[i][j]) {
                continue;
            }
            else if (graph[i - 1][j] - graph[i][j] == 1) {
                rep(k, i, i + L) {
                    if (!(k < N) || cache[k][j] || graph[i - 1][j] - graph[k][j] != 1) {
                        flag = false;
                        break;
                    }
                    cache[k][j] = true;
                }
            }
            else if (graph[i][j] - graph[i - 1][j] == 1) {
                rep(k, i - L, i) {
                    if (!(0 <= k) || cache[k][j] || graph[i][j] - graph[k][j] != 1) {
                        flag = false;
                        break;
                    }
                    cache[k][j] = true;
                }
            }
            else {
                flag = false;
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            answer++;
        }
    }
    cout << answer;
}

void Init(void) {
    cin >> N >> L;
    graph.resize(N, vi(N));
    cache.resize(N, vb(N));
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