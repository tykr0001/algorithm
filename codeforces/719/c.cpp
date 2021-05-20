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
\*************  2021-05-05 23:46:33  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
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

int t;
int n;
vvi a;
vb visited;
bool flag;

bool CanGo(int i, int j) {
    bool ret = true;
    if (i > 0)
        if (abs(a[i][j] - a[i - 1][j]) == 1) ret = false;
    if (j > 0)
        if (abs(a[i][j] - a[i][j - 1]) == 1) ret = false;
    return ret;
}

void BackTrack(int i, int j) {
    if (flag) return;
    if (i == n) {
        flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
        return;
    }
    int next_i;
    int next_j;
    if (j < n - 1) {
        next_i = i;
        next_j = j + 1;
    }
    else {
        next_i = i + 1;
        next_j = 0;
    }
    for (int k = 1; k <= n * n; k++) {
        if (!visited[k]) {
            a[i][j] = k;
            if (CanGo(i, j)) {
                visited[k] = true;
                BackTrack(next_i, next_j);
                visited[k] = false;
            }
            a[i][j] = 0;
        }
    }
}

void Solve(void) {
    flag = false;
    if (n < 5) {
        BackTrack(0, 0);
        if (!flag)
            cout << -1 << endl;
    }
    else {
        int aa = 1;
        int bb = 2;
        if (n % 2 == 1) {
            for (int j = 0; j < n; j++) {
                if (j <= n / 2) {
                    a[0][j] = aa;
                    aa += 2;
                }
                if (j > n / 2) {
                    a[0][j] = bb;
                    bb += 2;
                }
            }
        }
        else {
            for (int j = 0; j < n; j++) {
                if (j < n / 2) {
                    a[0][j] = aa;
                    aa += 2;
                }
                if (j >= n / 2) {
                    a[0][j] = bb;
                    bb += 2;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = a[i - 1][j] + n;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
}

void Init(void) {
    cin >> n;
    a = vvi(n, vi(n));
    visited = vb(n * n + 1);
}

int main(void) {
    Boost;
    cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}