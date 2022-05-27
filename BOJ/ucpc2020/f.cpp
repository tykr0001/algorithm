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
\*************  2021-10-08 15:04:13  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using vb = vector<bool>;
using v2b = vector<vector<bool>>;
using v3b = vector<v2b>;
using vl = vector<ll>;
using v2l = vector<vl>;
using v3l = vector<v2l>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T1, typename T2>
void sort(T1& container, T2 cmp) { sort(container.begin(), container.end(), cmp); }
template<class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (const T& elem : rhs) os << elem << ' '; os << endl; return os; }
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... Size>
void resize(T& container, int _size, Size... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }
/*************************************************/

int N, H, W;
v2i arr;
v2i idx;
int M;

int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };

typedef struct {
    int move;
    int flag;
    int i;
    int j;
    int infight;
} Unit;

vi r;
vector<Unit> units;

bool CanGo(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W;
}

void Solve(void) {
    int K; cin >> K;
    while (K--) {
        v2i weight(H, vi(W, INF));
        class Comp {
            public:
            bool operator()(pair<int, pii> a, pair<int, pii> b) {
                return a.fi > b.fi;
            }
        };
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, Comp> pq;

        int u, a, b; cin >> u >> a >> b;
        if (arr[a][b] == -1 || idx[a][b] != 0) {
            continue;
        }
        pq.emplace(pair<int, pii>{0, pii { units[u].i, units[u].j }});
        weight[units[u].i][units[u].j] = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            int cost = top.fi;
            int y = top.se.fi;
            int x = top.se.se;
            pq.pop();

            if (weight[y][x] < cost) {
                continue;
            }

            for (int k = 0; k < 4; k++) {
                int i = y + di[k];
                int j = x + dj[k];
                if (CanGo(i, j) && arr[i][j] != -1) {
                    int unit = idx[i][j];
                    if (cost + arr[i][j] < weight[i][j]) {
                        // on going
                        if (!(i == a && j == b)) {
                            if (unit == 0 || units[unit].flag == units[u].flag) {
                                bool flag = true;
                                for (int l = 0; l < 4; l++) {
                                    if (CanGo(i + di[l], j + dj[l])) {
                                        int adj_u = idx[i + di[l]][j + dj[l]];
                                        if (!(adj_u == 0 || adj_u == units[u].flag)) {
                                            if (units[adj_u].infight != 0)
                                                flag = false;
                                        }
                                    }
                                }
                                if (flag) {
                                    if (cost + arr[i][j] <= units[u].move) {
                                        weight[i][j] = cost + arr[i][j];
                                        pq.emplace(pair<int, pii>{weight[i][j], pii { i, j }});
                                    }
                                }

                            }
                        }
                        // last
                        else {
                            if (unit == 0) {
                                if (cost + arr[i][j] <= units[u].move) {
                                    weight[i][j] = cost + arr[i][j];
                                    pq.emplace(pair<int, pii>{weight[i][j], pii { i, j }});
                                }
                            }
                        }
                    }
                }
            }

        }
        if (weight[a][b] != INF) {
            for (int k = 0; k < 4; k++) {
                int i = units[u].i + di[k];
                int j = units[u].j + dj[k];
                if (CanGo(i, j) && idx[i][j] != 0 && idx[i][j] != units[u].flag) {
                    units[idx[i][j]].infight--;
                }
            }
            for (int k = 0; k < 4; k++) {
                int i = a + di[k];
                int j = b + dj[k];
                if (CanGo(i, j) && idx[i][j] != 0 && idx[i][j] != units[u].flag) {
                    units[idx[i][j]].infight++;
                }
            }
            idx[units[u].i][units[u].j] = 0;
            units[u].i = a;
            units[u].j = b;
            idx[a][b] = u;
        }
    }
    for (int i = 1; i <= M; i++) {
        cout << units[i].i << ' ' << units[i].j << endl;
    }
}

void Init(void) {
    cin >> N >> H >> W;
    resize(arr, H, W);
    resize(idx, H, W);
    resize(r, N + 1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            arr[i][j] = r[arr[i][j]];
        }
    }
    cin >> M;
    units.resize(M + 1);
    for (int i = 1; i <= M; i++) {
        int m, t, a, b;
        cin >> m >> t >> a >> b;
        units[i] = { m, t, a, b, 0 };
        idx[a][b] = i;
        for (int k = 0; k < 4; k++) {
            int y = a + di[k];
            int x = b + dj[k];
            if (CanGo(y, x) && units[idx[y][x]].flag != t) {
                units[idx[y][x]].infight += 1;
                units[idx[a][b]].infight += 1;
            }
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}