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
\*************  2021-04-22 16:17:54  *************/

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

ll N, w;
vl three;
vl five;
vl sum_three;
vl sum_five;
ll answer;

void Solve(void) {
    int idx = 0;
    int end = min(ll(five.size()), w / 5);
    while (idx <= end) {
        ll num_three = (w - idx * 5) / 3;
        num_three = min(num_three, ll(three.size()));
        ll tmp = sum_five[idx] + sum_three[num_three];
        answer = max(answer, tmp);
        idx++;
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N >> w;
    rep(i, 0, N) {
        ll t, s;
        cin >> t >> s;
        if (t == 3) three.emplace_back(s);
        else five.emplace_back(s);
    }
    sort(three, greater<int>());
    sort(five, greater<int>());
    sum_three.resize(three.size() + 1);
    sum_five.resize(five.size() + 1);
    if (!three.empty()) {
        rep(i, 1, sum_three.size()) {
            sum_three[i] = sum_three[i - 1] + three[i - 1];
        }
    }
    if (!five.empty()) {
        rep(i, 1, sum_five.size()) {
            sum_five[i] = sum_five[i - 1] + five[i - 1];
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}