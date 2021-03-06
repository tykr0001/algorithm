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
\*************  2021-04-27 22:01:15  *************/

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
template<class T, class U>
void sort(T& container, U cmp) { sort(container.begin(), container.end(), cmp); }
template<class T, class U>
istream& operator>>(istream& is, pair<T, U>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (const T& elem : rhs) os << elem << ' '; os << endl; return os; }
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... sizes>
void resize(T& container, int _size, sizes... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }
/*************************************************/

int N, Q;
string S;
int U, R, D, L;

void Solve(void) {
    while (Q--) {
        int ans = 0;
        int u = U;
        int r = R;
        int d = D;
        int l = L;
        int x_pos = r - l;
        int y_pos = u - d;
        int x, y;
        cin >> x >> y;
        if ((abs(x) + abs(y)) % 2 != S.length() % 2 || (abs(x) + abs(y)) > S.length()) {
            cout << -1 << endl;
            continue;
        }
        // x
        bool x_flag = false;
        int x_gap = abs(x - x_pos);
        if (x_gap % 2) x_flag = true;
        x_gap /= 2;
        if (x > x_pos) {
            if (x_gap <= l) {
                ans += x_gap;
                l -= x_gap;
                r += x_gap;
            }
            else {
                ans += l;
                r += l;
                l = 0;
            }
        }
        else if (x < x_pos) {
            if (x_gap <= r) {
                ans += x_gap;
                r -= x_gap;
                l += x_gap;
            }
            else {
                ans += r;
                l += r;
                r = 0;
            }
        }

        // y
        int y_gap = abs(y - y_pos);
        y_gap /= 2;
        if (y > y_pos) {
            if (y_gap <= d) {
                ans += y_gap;
                d -= y_gap;
                u += y_gap;
            }
            else {
                ans += d;
                u += d;
                d = 0;
            }
            if (x_flag) {
                u++;
                ans++;
                x_flag = false;
            }
        }
        else if (x < y_pos) {
            if (y_gap <= u) {
                ans += y_gap;
                u -= y_gap;
                d += x_gap;
            }
            else {
                ans += u;
                d += u;
                u = 0;
            }
            if (x_flag) {
                d++;
                ans++;
                x_flag = false;
            }
        }
        x_pos = r - l;
        y_pos = u - d;
        ans += abs(x - x_pos);
        ans += abs(y - y_pos);
        cout << ans << endl;
    }
}

void Init(void) {
    cin >> N >> Q >> S;
    for (char c : S) {
        if (c == 'U') U++;
        if (c == 'R') R++;
        if (c == 'D') D++;
        if (c == 'L') L++;
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}