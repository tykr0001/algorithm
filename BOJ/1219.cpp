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
\*************  2021-05-13 15:06:19  *************/

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
using vvs = vector<vector<string>>;
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

int V, init, goal, E;
vector<pair<int, pii>> edge;
vector<ll> money;
vector<ll> dist;

void BellmanFord(int init) {
    dist[init] = money[init];
    for (int j = 0; j < 2; j++) {
        
        // O(V)
        for (int i = 0; i < V; i++) {
            // O(E)
            for (auto& e : edge) {
                int src = e.second.first;
                int dst = e.second.second;
                int cost = e.first;
                if (dist[src] == INT64_MIN) continue;
                else if (dist[src] == INT64_MAX) dist[dst] = INT64_MAX;
                else if (dist[dst] < dist[src] - cost + money[dst]) {
                    if (j == 0)
                        dist[dst] = dist[src] - cost + money[dst];
                    else
                        dist[dst] = INT64_MAX;
                }
            }
        }
        
    }
}

void Solve(void) {
    BellmanFord(init);
    if (dist[goal] == INT64_MIN)
        cout << "gg" << endl;
    else if (dist[goal] == INT64_MAX)
        cout << "Gee" << endl;
    else
        cout << dist[goal] << endl;
}

void Init(void) {
    cin >> V >> init >> goal >> E;
    edge.resize(E);
    money.resize(V);
    dist.resize(V, INT64_MIN);
    for (auto& e : edge) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        e = pair<int, pii>(cost, pii(src, dst));
    }
    for (auto& m : money)
        cin >> m;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}