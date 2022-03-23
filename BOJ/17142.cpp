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
\*************  2022-03-23 18:37:56  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using vb = vector<bool>;
using v2b = vector<vb>;
using vs = vector<string>;
using v2s = vector<vs>;
using vc = vector<char>;
using v2c = vector<vc>;
using vl = vector<ll>;
using v2l = vector<vl>;
using v3l = vector<v2l>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
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

int ans = INF;
int n, m;
int empty_room;
v2i arr;
vector<pii> virus;
vector<bool> selected;

int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };

bool CanGo(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

void BFS() {
    queue<pii> q;
    v2i depth(n, vi(n, -1));
    int time = 0;
    int searched_room = 0;
    for (int i = 0; i < virus.size(); i++) {
        if (selected[i]) {
            q.push(virus[i]);
            depth[virus[i].fi][virus[i].se] = 0;
        }
    }

    while (!q.empty()) {
        pii node = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int i = node.fi + di[k];
            int j = node.se + dj[k];
            if (CanGo(i, j) && arr[i][j] != 1 && depth[i][j] == -1) {
                q.push(pii { i,j });
                depth[i][j] = depth[node.fi][node.se] + 1;
                if (arr[i][j] == 0) {
                    searched_room++;
                    time = depth[i][j];
                }
            }
        }
    }
    if (searched_room == empty_room)
        ans = min(ans, time);
}

void BackTrack(int idx, int depth) {
    if (depth == m)
        BFS();
    else {
        for (int i = idx; i < virus.size(); i++) {
            if (!selected[i]) {
                selected[i] = true;
                BackTrack(i + 1, depth + 1);
                selected[i] = false;
            }
        }
    }
}

void Solve(void) {
    BackTrack(0, 0);
    cout << (ans != INF ? ans : -1) << endl;
}

void Init(void) {
    cin >> n >> m;
    resize(arr, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int inp; cin >> arr[i][j];
            if (arr[i][j] == 0) empty_room++;
            if (arr[i][j] == 2) virus.push_back(pii { i, j });
        }
    }
    selected.resize(virus.size());
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}