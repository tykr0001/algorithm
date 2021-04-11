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
\*************  2021-04-08 20:44:56  *************/

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
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... sizes>
void resize(T& container, int _size, sizes... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }
/*************************************************/

int n, m;
vi a;
vi b;
vi c;
vvi diff;
vi answer;

void Solve(void) {
    diff.clear();
    resize(diff, 1e5 + 1);
    answer.clear();
    answer.reserve(m);

    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            diff[b[i]].emplace_back(i);
            num++;
        }
    }

    int same = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] == c[m]) {
            same = i;
            break;
        }
    }
    if (same == 0) {
        cout << "NO" << endl;
        return;
    }

    for (int i = m; i >= 1; i--) {
        if (diff[c[i]].empty()) {
            if (i == m)
                answer.emplace_back(same);
            else
                answer.emplace_back(answer.front());
        }
        else {
            answer.emplace_back(diff[c[i]].back());
            diff[c[i]].pop_back();
            num--;
        }
    }

    if (num == 0) {
        cout << "YES" << endl;
        for (int i = answer.size() - 1; i >= 0; i--) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }

}

void Init(void) {
    cin >> n >> m;
    a.clear();
    b.clear();
    c.clear();
    resize(a, n + 1);
    resize(b, n + 1);
    resize(c, m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= m; i++)
        cin >> c[i];
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