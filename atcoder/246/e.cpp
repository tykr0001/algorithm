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
\*************  2022-04-02 21:22:47  *************/

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
int a_1, b_1;
int a_2, b_2;
vector<string> arr;

int di[4] = { 1,1,-1,-1 };
int dj[4] = { -1,1,-1,1 };

bool CanGo(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

struct Node {
    int i;
    int j;
    int depth;
    int dir;
};

void Solve(void) {
    auto Cmp = [ ](Node a, Node b) {return a.depth > b.depth; };
    priority_queue<Node, vector<Node>, decltype(Cmp)> pq(Cmp);
    Node init = { a_1 - 1, b_1 - 1, 0, -1 };
    pq.emplace(init);
    v2i depth = v2i(n, vi(n, -1));
    depth[a_1 - 1][b_1 - 1] = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.depth > depth[cur.i][cur.j]) continue;
        if (cur.i == a_2 - 1 && cur.j == b_2 - 1) break;

        for (int k = 0; k < 4; k++) {
            if (k == 3 - cur.dir) continue;
            int cnt = 1;
            while (1) {
                int i = cur.i + di[k] * cnt;
                int j = cur.j + dj[k] * cnt;
                cnt++;
                if (CanGo(i, j) && arr[i][j] != '#') {
                    if (depth[i][j] == -1 || depth[i][j] > depth[cur.i][cur.j] + 1) {
                        depth[i][j] = depth[cur.i][cur.j] + 1;
                        Node next = { i, j, depth[cur.i][cur.j] + 1, k };
                        pq.emplace(next);
                    }
                }
                else
                    break;
            }
        }
    }
    cout << depth[a_2 - 1][b_2 - 1];
}

void Init(void) {
    cin >> n >> a_1 >> b_1 >> a_2 >> b_2;
    resize(arr, n);
    cin >> arr;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}