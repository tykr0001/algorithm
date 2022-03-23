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
\*************  2022-03-23 16:56:47  *************/

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

int cnt;
int n;
v2i weight;
v2i shortest;

struct Path {
    int i;
    int j;
    int cost;
};

int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };

bool CanGo(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

void Dijkstra() {
    auto Comp = [ ](Path a, Path b) {return a.cost > b.cost; };
    priority_queue<Path, vector<Path>, decltype(Comp)> pq(Comp);
    pq.push(Path { 0,0,weight[0][0] });
    while (!pq.empty()) {
        Path top = pq.top();
        pq.pop();

        if (top.cost > shortest[top.i][top.j]) continue;

        for (int k = 0; k < 4; k++) {
            int i = top.i + di[k];
            int j = top.j + dj[k];
            if (CanGo(i, j) && top.cost + weight[i][j] < shortest[i][j]) {
                pq.push(Path { i,j,top.cost + weight[i][j] });
                shortest[i][j] = top.cost + weight[i][j];
            }
        }
    }
    cout << "Problem " << cnt << ": " << shortest[n - 1][n - 1] << endl;
}

int main(void) {
    Boost;
    while (1) {
        cnt++;
        cin >> n;
        if (!n) break;
        weight.clear();
        resize(weight, n, n);
        shortest = v2i(n, vi(n, INF));
        cin >> weight;
        Dijkstra();
    }
    return 0;
}