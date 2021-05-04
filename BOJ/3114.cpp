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
\*************  2021-05-05 01:37:33  *************/

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

vvs arr;
vvi cache;
vvi A_sum;
vvi B_sum;
int R, C;

int ToInt(const string& str) {
    int ret = 0;
    for (int i = 1; i < str.length(); i++)
        ret = ret * 10 + str[i] - '0';
    return ret;
}

int DP(int r, int c) {
    if (cache[r][c])
        return cache[r][c];
    if (r == 0 && c == 0) {
        return cache[r][c] = A_sum[1][0];
    }
    int ret = 0;
    int tmp = 0;
    if (r > 0) {
        tmp = DP(r - 1, c);
        if (arr[r][c][0] == 'A')
            tmp -= ToInt(arr[r][c]);
        ret = max(ret, tmp);
    }
    if (c > 0) {
        tmp = DP(r, c - 1);
        if (r + 1 < R) tmp += A_sum[r + 1][c];
        if (r - 1 >= 0) tmp += B_sum[r - 1][c];
        ret = max(ret, tmp);
    }
    if (r > 0 && c > 0) {
        tmp = DP(r - 1, c - 1);
        if (r + 1 < R) tmp += A_sum[r + 1][c];
        if (r - 1 >= 0) tmp += B_sum[r - 1][c];
        ret = max(ret, tmp);
    }
    return cache[r][c] = ret;
}

void Solve(void) {
    cout << DP(R - 1, C - 1);
}

void Init(void) {
    cin >> R >> C;
    resize(arr, R, C);
    resize(cache, R, C);
    resize(A_sum, R, C);
    resize(B_sum, R, C);
    cin >> arr;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            B_sum[i][j] = B_sum[i - 1 >= 0 ? i - 1 : 0][j];
            if (arr[i][j][0] == 'B')
                B_sum[i][j] += ToInt(arr[i][j]);
        }
    }
    for (int i = R - 1; i >= 0; i--) {
        for (int j = 0; j < C; j++) {
            A_sum[i][j] = A_sum[i + 1 < R ? i + 1 : R - 1][j];
            if (arr[i][j][0] == 'A')
                A_sum[i][j] += ToInt(arr[i][j]);
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}