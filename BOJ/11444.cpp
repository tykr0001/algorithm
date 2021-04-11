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
\*************  2021-04-03 05:59:44  *************/

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
template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T, class U>
void sort(T& container, U cmp) { sort(container.begin(), container.end(), cmp); }
template<class T, class U>
istream& operator>>(istream& is, pair<T, U>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (T& elem : rhs) os << elem << ' '; os << endl; return os; }
/*************************************************/
#define MOD ll(1000000007)

ll inp;

vvl operator*(const vvl& lhs, const vvl& rhs) {
    return { {(lhs[0][0] * rhs[0][0] + lhs[0][1] * rhs[1][0]) % MOD,
              (lhs[0][0] * rhs[0][1] + lhs[0][1] * rhs[1][1]) % MOD},
             {(lhs[1][0] * rhs[0][0] + lhs[1][1] * rhs[1][0]) % MOD,
              (lhs[1][0] * rhs[0][1] + lhs[1][1] * rhs[1][1]) % MOD} };
}

vvl Fibo(ll idx) {
    if (idx == 0) return { {0,0},{0,0} };
    if (idx == 1) return { {1,1},{1,0} };
    if (idx % 2) {
        vvl ret = Fibo((idx - 1) / 2);
        return ret * ret * vvl { {1,1},{1,0} };
    }
    else {
        vvl ret = Fibo(idx / 2);
        return ret * ret;
    }
}

void Solve(void) {
    cout << Fibo(inp)[1][0] % MOD << endl;
}

void Init(void) {
    cin >> inp;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}