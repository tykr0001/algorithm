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
\*************  2022-07-13 16:11:06  *************/

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

int n, m, k;
vector<string> arr;
vector<vector<int>> u_idx;
long long ans;
string query;

// 미만
int LowBinary(vector<int>& row, int val) {
    int lo = 0, hi = row.size() - 1;
    int mid;
    int ret = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (row[mid] >= val) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
            ret = mid;
        }
    }
    return ret;
}

// 이하
int LowBinary_2(vector<int>& row, int val) {
    int lo = 0, hi = row.size() - 1;
    int mid;
    int ret = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (row[mid] > val) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
            ret = mid;
        }
    }
    return ret;
}

void Solve() {
    int hi = m - 1;
    int lo_idx = LowBinary(u_idx[query.back() - 'A'], hi);
    int lo = 0;
    if (lo_idx != -1) lo = u_idx[query.back() - 'A'][lo_idx] + 1;

    ans += hi - lo + 1;
    for (int i = query.size() - 2; i >= 0; i--) {
        int row = query[i] - 'A';
        int next_hi_idx = LowBinary_2(u_idx[row], hi);  // 이전 hi 이하,최대
        int next_lo_idx = LowBinary(u_idx[row], lo);    // 이전 lo 미만
        int next_hi = 0;
        int next_lo = 0;
        if (next_hi_idx == -1)
            break;
        else
            next_hi = u_idx[row][next_hi_idx];
        if (next_lo_idx != -1) next_lo = u_idx[row][next_lo_idx] + 1;
        if (next_hi < lo) break;

        hi = next_hi;
        lo = next_lo;
        ans += hi - lo + 1;
    }

    cout << ans;
}

void Init() {
    cin >> n >> m >> k;
    arr.resize(k);
    u_idx.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 'U') {
                u_idx[i].emplace_back(j);
            }
        }
    }
    cin >> query;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}