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
\*************  2022-03-30 12:08:19  *************/

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

int n;
int not_ans;
int ans;

struct Student {
    int fi, se, th;
};

// Segment-Tree(세그먼트트리)
struct Segment {
    vector<Student> arr;
    vl tree;

    Segment() { }
    Segment(int n) : arr(n + 1), tree(1 << int(ceil(log2(n))) + 1, LINF) { }

    ll Update(int node, int start, int end, int idx, ll diff) {
        if (idx < start || idx > end) return tree[node];
        if (start == end) return tree[node] = diff;
        int mid = (start + end) / 2;
        return tree[node] = min(Update(node * 2, start, mid, idx, diff),
            Update(node * 2 + 1, mid + 1, end, idx, diff));
    }

    ll Min(int node, int start, int end, int left, int right) {
        if (left > end || right < start) return LINF;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return tree[node] = min(Min(node * 2, start, mid, left, right),
            Min(node * 2 + 1, mid + 1, end, left, right));
    }
} seg;

void Solve(void) {
    for (int i = 1; i <= n; i++) {
        if (seg.Min(1, 1, n, 1, seg.arr[i].se) < seg.arr[i].th)
            not_ans++;
        seg.Update(1, 1, n, seg.arr[i].se, seg.arr[i].th);
    }
    ans = n - not_ans;
    cout << ans;
}

void Init(void) {
    cin >> n;
    seg = Segment(n);
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        seg.arr[inp].fi = i;
    }

    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        seg.arr[inp].se = i;
    }
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        seg.arr[inp].th = i;
    }
    sort(seg.arr.begin() + 1, seg.arr.end(), [ ](Student a, Student b) { return a.fi < b.fi; });
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}