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
\*************  2022-06-28 12:08:00  *************/

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

// 2D Fenwick-Tree(2차원 펜윅트리)
struct Fenwick2D {
    ll n;
    v2l arr;
    v2l tree;

    Fenwick2D() { }
    Fenwick2D(int n) : n(n), arr(n + 1, vl(n + 1)), tree(n + 1, vl(n + 1)) { }

    void Update(int x, int y, ll diff) {
        while (x < n + 1) {
            int tmp_y = y;
            while (tmp_y < n + 1) {
                tree[x][tmp_y] = tree[x][tmp_y] + diff;
                tmp_y = tmp_y + (tmp_y & -tmp_y);
            }
            x = x + (x & -x);
        }
    }

    ll Query(int x, int y) {
        ll ret = 0;
        while (x > 0) {
            int tmp_y = y;
            while (tmp_y > 0) {
                ret = ret + tree[x][tmp_y];
                tmp_y = tmp_y - (tmp_y & -tmp_y);
            }
            x = x - (x & -x);
        }
        return ret;
    }

} fen;

int n, m;

void Solve(void) {
    for (int i = 0; i < m; i++) {
        int w; cin >> w;
        if (w == 0) {
            int x, y, c;
            cin >> x >> y >> c;
            int diff = c - fen.arr[x][y];
            fen.arr[x][y] = c;
            fen.Update(x, y, diff);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << fen.Query(x2, y2) -
                fen.Query(x2, y1 - 1) -
                fen.Query(x1 - 1, y2) +
                fen.Query(x1 - 1, y1 - 1) << endl;
        }
    }

}

void Init(void) {
    cin >> n >> m;
    fen = Fenwick2D(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> fen.arr[i][j];
            fen.Update(i, j, fen.arr[i][j]);
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}