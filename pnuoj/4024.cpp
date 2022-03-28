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
\*************  2022-03-29 05:00:50  *************/

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

int n;
v2i pole;
int height;
vector<pii> highest;
pii left_most;
pii right_most;
pii up_most;
pii down_most;

void Solve(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pole[i][j] == height)
                highest.emplace_back(i, j);
        }
    }
    left_most = right_most = up_most = down_most = highest.front();
    for (int i = 1; i < highest.size(); i++) {
        if (left_most.se > highest[i].se) left_most = highest[i];
        if (right_most.se < highest[i].se) right_most = highest[i];
        if (up_most.fi < highest[i].fi) up_most = highest[i];
        if (down_most.fi > highest[i].fi) down_most = highest[i];
    }
    int length = max(right_most.se - left_most.se, up_most.fi - down_most.fi);
    cout << height + (length % 2 ? length / 2 + 1 : length / 2);
}

void Init(void) {
    cin >> n;
    resize(pole, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> pole[i][j];
            if (pole[i][j] > height) height = pole[i][j];
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}