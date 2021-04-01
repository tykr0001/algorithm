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
\*************  2021-04-01 21:49:41  *************/

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

int n;
vi a;
vi seg0;
vi seg1;
vi tmp;

void Solve(void) {
    seg0.emplace_back(0);
    seg1.emplace_back(0);
    rep(i, 0, n) {
        if (a[i] == seg0.back()) {
            for (int elem : tmp)
                seg1.emplace_back(elem);
            tmp.clear();
        }
        else if (a[i] == seg1.back()) {
            for (int elem : tmp)
                seg0.emplace_back(elem);
            tmp.clear();
        }
        else {
            if (tmp.empty() || find(tmp.begin(), tmp.end(), a[i]) == tmp.end()) {
                tmp.emplace_back(a[i]);
            }
            else {
                for (int& elem : tmp)
                    if (elem != a[i])
                        seg0.emplace_back(elem);
                    else
                        seg1.emplace_back(elem);
                tmp.clear();
            }

        }
    }
    cout << seg0.size() + seg1.size() + tmp.size() - 2;
}

void Init(void) {
    cin >> n;
    a.resize(n);
    cin >> a;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}