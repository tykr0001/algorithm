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
\*************  2022-03-30 12:47:53  *************/

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
int ans;

struct Line {
    int x;
    int y1;
    int y2;
    int flag;
};

// Segment-Tree(세그먼트트리)
struct Segment {
    vector<Line> arr;
    vl cnt;
    vl depth;

    Segment() { }
    Segment(int n) : arr(n + 1), cnt(1 << int(ceil(log2(n))) + 1), depth(1 << int(ceil(log2(n))) + 1) { }

    void UpdateRange(int node, int start, int end, int left, int right, ll diff) {
        if (right < start || left > end) return;
        if (left <= start && end <= right) depth[node] += diff;
        else {
            int mid = (start + end) / 2;
            UpdateRange(node * 2, start, mid, left, right, diff);
            UpdateRange(node * 2 + 1, mid + 1, end, left, right, diff);
        }

        if (depth[node] != 0) cnt[node] = end - start + 1;
        else if (start == end) cnt[node] = 0;
        else cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
    }
} seg;

void Solve(void) {
    for (int i = 1; i <= 2 * n; i++) {
        if (i != 1) {
            int gap = seg.arr[i].x - seg.arr[i - 1].x;
            ans += gap * seg.cnt[1];
        }
        seg.UpdateRange(1, 1, 30001, seg.arr[i].y1, seg.arr[i].y2 - 1, seg.arr[i].flag);
    }
    cout << ans;
}

void Init(void) {
    cin >> n;
    seg.arr.resize(2 * n + 1);
    seg.cnt.resize(1 << int(ceil(log2(30001))) + 1);
    seg.depth.resize(1 << int(ceil(log2(30001))) + 1);
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Line left = { x1, y1 + 1, y2 + 1, 1 };
        Line right = { x2, y1 + 1, y2 + 1, -1 };
        seg.arr[i * 2 - 1] = left;
        seg.arr[i * 2] = right;
    }
    sort(seg.arr.begin() + 1, seg.arr.end(), [ ](Line a, Line b) { return a.x < b.x; });
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}