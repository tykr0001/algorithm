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
\*************  2021-04-01 20:55:50  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

ll A, B, n;
vpll m;
bool flag;

void Solve(void) {
    flag = true;
    for (int i = 0; i < n - 1; i++) {
        ll cnt;
        if (m[i].se % A)
            cnt = m[i].se / A + 1;
        else
            cnt = m[i].se / A;

        B -= cnt * m[i].fi;
        if (B < 0) {
            flag = false;
            break;
        }
    }

    ll hc, mc;
    if (m[n - 1].se % A)
        hc = m[n - 1].se / A + 1;
    else
        hc = m[n - 1].se / A;

    if (B % m[n - 1].fi)
        mc = B / m[n - 1].fi + 1;
    else
        mc = B / m[n - 1].fi;

    if (hc > mc)
        flag = false;

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void Init(void) {
    cin >> A >> B >> n;
    m.clear();
    m.resize(n);
    rep(i, 0, n) {
        cin >> m[i].fi;
    }
    rep(i, 0, n) {
        cin >> m[i].se;
    }
    sort(m);
}

int main(void) {
    Boost;
    int t; cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}