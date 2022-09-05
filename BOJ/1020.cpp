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
\*************  2022-08-08 11:28:20  *************/

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
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
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

v3l dp;
string n;
ll num[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };
ll cnt;
ll len;

void Solve(void) {
    dp[0][len][0] = 0;
    for (int i = len - 1, pos = 1; i >= 0; i--, pos *= 10) {
        for (int j = 0; j < 10; j++) {
            for (int k = num[j]; k < len * 8; k++) {
                dp[0][i][k] = min(dp[0][i][k], dp[0][i + 1][k - num[j]] + j * pos);
                if (j > n[i] - '0')
                    dp[1][i][k] = min(dp[1][i][k], dp[0][i + 1][k - num[j]] + j * pos);
            }
        }
        for (int j = num[n[i] - '0']; j < len * 8; j++) {
            dp[1][i][j] = min(dp[1][i][j], dp[1][i + 1][j - num[n[i] - '0']] + (n[i] - '0') * pos);
        }
    }
    cout << min(dp[0][0][cnt] + ll(pow(10, len)), dp[1][0][cnt] - stoi(n)) << endl;
}

void Init(void) {
    cin >> n;
    len = n.length();
    dp = v3l(2, v2l(16, vl(106, LINF)));
    for (int i = 0; i < len; i++) {
        cnt += num[n[i] - '0'];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}