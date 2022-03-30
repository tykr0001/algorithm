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
\*************  2022-03-29 17:54:49  *************/

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

int n, k;
ll ans;

// Segment-Tree(세그먼트트리)
struct Segment {
    vl arr;
    vl tree;

    Segment() { }
    Segment(int n) : arr(n + 1), tree(1 << int(ceil(log2(n))) + 1) { }

    ll Update(int node, int start, int end, int idx, ll diff) {
        if (idx < start || idx > end) return tree[node];
        if (start == end) return tree[node] += diff;
        int mid = (start + end) / 2;
        return tree[node] = Update(node * 2, start, mid, idx, diff)
            + Update(node * 2 + 1, mid + 1, end, idx, diff);
    }

    ll Mid(int node, int start, int end, int cnt) {
        if (start == end) return start;
        int mid = (start + end) / 2;
        if (cnt <= tree[node * 2]) return Mid(node * 2, start, mid, cnt);
        else return Mid(node * 2 + 1, mid + 1, end, cnt - tree[node * 2]);
    }
} seg;

void Solve(void) {
    for (int i = 1; i <= n; i++) {
        seg.Update(1, 0, 70000, seg.arr[i], 1);
        if (i >= k) {
            ll ret = seg.Mid(1, 0, 70000, (k + 1) / 2);
            ans += ret;
            // cout << "#ret" << " : " << ret << endl;
            seg.Update(1, 0, 70000, seg.arr[i - (k - 1)], -1);
        }
    }
    cout << ans;
}

void Init(void) {
    cin >> n >> k;
    resize(seg.arr, n + 1);
    resize(seg.tree, 1 << int(ceil(log2(70000))) + 1);
    for (int i = 1; i <= n; i++) {
        cin >> seg.arr[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}