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
\*************  2022-03-22 13:21:45  *************/

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

int n, m, h;
v2b ladder;
int ans = INF;

int Route(int col) {
    for (int i = 1; i <= h; i++) {
        if (ladder[i][col - 1]) col--;
        else if (ladder[i][col]) col++;
    }
    return col;
}

void BackTrack(int y, int x, int call_depth) {
    if (call_depth > 3) return;

    bool flag = true;
    for (int j = 1; j <= n; j++) {
        if (j != Route(j)) {
            flag = false;
            break;
        }
    }

    if (flag) {
        ans = min(ans, call_depth);
        return;
    }

    for (int j = x; j <= n - 1; j++) {
        if (!ladder[y][j] && !ladder[y][j - 1] && !ladder[y][j + 1]) {
            ladder[y][j] = true;
            BackTrack(y, j, call_depth + 1);
            ladder[y][j] = false;
        }
    }

    for (int i = y + 1; i <= h; i++) {
        for (int j = 1; j <= n - 1; j++) {
            if (!ladder[i][j] && !ladder[i][j - 1] && !ladder[i][j + 1]) {
                ladder[i][j] = true;
                BackTrack(i, j, call_depth + 1);
                ladder[i][j] = false;
            }
        }
    }
}

void Solve(void) {
    BackTrack(1, 1, 0);

    cout << (ans != INF ? ans : -1);
}

void Init(void) {
    cin >> n >> m >> h;
    resize(ladder, h + 1, n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}