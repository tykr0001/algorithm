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
\*************  2022-09-21 11:20:08  *************/

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

int n, m;
int sqrt_n;
int ret;
int arr[100001], ans[100001], cnt[100001], cnt2[100001];
pair<pii, int> query[100001];

void Add(int idx) {
    cnt2[cnt[arr[idx]]]--;
    cnt[arr[idx]]++;
    cnt2[cnt[arr[idx]]]++;
    ret = max(ret, cnt[arr[idx]]);
}

void Sub(int idx) {
    cnt2[cnt[arr[idx]]]--;
    cnt[arr[idx]]--;
    cnt2[cnt[arr[idx]]]++;
}

int Query(pii& prev, pii& q) {
    for (int i = prev.fi - 1; i >= q.fi; i--) Add(i);
    for (int i = prev.se + 1; i <= q.se; i++) Add(i);
    for (int i = prev.fi; i < q.fi; i++) Sub(i);
    for (int i = prev.se; i > q.se; i--) Sub(i);
    return ret;
}

void Solve(void) {
    pii prev = { 0, -1 };
    for (int i = 0; i < m; i++) {
        auto q = query[i];
        ans[q.se] = Query(prev, q.fi);
        while (cnt2[ans[q.se]] == 0) ans[q.se]--;
        prev = q.fi;
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;
    return;
}

void Init(void) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        query[i].fi.fi = a - 1;
        query[i].fi.se = b - 1;
        query[i].se = i;
    }
    sqrt_n = sqrt(n);
    sort(query, query + m, [ ](auto& a, auto& b) {
        if (a.fi.fi / sqrt_n == b.fi.fi / sqrt_n)
            return a.fi.se == b.fi.se ? a.fi.fi < b.fi.fi : a.fi.se < b.fi.se;
        return a.fi.fi / sqrt_n < b.fi.fi / sqrt_n;
        });
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}