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
\*************  2022-03-29 02:00:03  *************/

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

v2i puzzle;
v2b selected;
vi arr;
int ans = INT32_MIN;

bool IsAdj() {
    bool ret = true;
    if (selected[0][0])
        ret = ret && (selected[0][1] || selected[1][0]);
    if (selected[0][2])
        ret = ret && (selected[0][1] || selected[1][2]);
    if (selected[2][0])
        ret = ret && (selected[2][1] || selected[1][0]);
    if (selected[2][2])
        ret = ret && (selected[2][1] || selected[1][2]);
    return ret;
}

void Calc() {
    if (!IsAdj()) return;
    vi tmp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (selected[i][j]) tmp.emplace_back(puzzle[i][j]);
        }
    }
    sort(tmp);
    int ret = 0;
    for (int i = 0; i < 7; i++) {
        ret += arr[i] * tmp[i];
    }
    ans = max(ans, ret);
}

void Solve(void) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            selected[i][j] = true;

    for (int i = 0; i < 8; i++) {
        selected[i / 3][i % 3] = false;
        for (int j = i + 1; j < 9; j++) {
            selected[j / 3][j % 3] = false;
            Calc();
            selected[j / 3][j % 3] = true;
        }
        selected[i / 3][i % 3] = true;
    }
    cout << ans;
}

void Init(void) {
    resize(puzzle, 3, 3);
    resize(selected, 3, 3);
    resize(arr, 7);
    cin >> puzzle;
    cin >> arr;
    sort(arr);
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}