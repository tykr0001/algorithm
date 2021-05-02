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
\*************  2021-04-28 22:52:17  *************/

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
using vvc = vector<vector<char>>;
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
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (const T& elem : rhs) os << elem << ' '; os << endl; return os; }
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... sizes>
void resize(T& container, int _size, sizes... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }
/*************************************************/

vs graph;
vvi answer;
vvb visited;
int row, col;

int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

bool CanGo(int i, int j) {
    return 0 <= i && i < row && 0 <= j && j < col;
}

int BFS(const pii& init) {
    int ret = 1;
    queue<pii> sq;
    sq.emplace(init);
    while (!sq.empty()) {
        auto node = sq.front();
        sq.pop();
        rep(k, 0, 4) {
            int i = node.fi + di[k];
            int j = node.se + dj[k];
            if (CanGo(i, j) && graph[i][j] == '0' && !visited[i][j]) {
                sq.emplace(i, j);
                visited[i][j] = true;
                ret++;
            }
        }
    }
    return ret % 10;
}

void Solve(void) {
    rep(i, 0, row) {
        rep(j, 0, col) {
            if (graph[i][j] == '1')
                answer[i][j] = BFS(pii { i,j });
            cout << answer[i][j];
        }
        cout << endl;
    }

}

void Init(void) {
    cin >> row >> col;
    resize(graph, row);
    resize(answer, row, col);
    resize(visited, row, col);
    cin >> graph;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}