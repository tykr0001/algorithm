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
\*************  2021-04-27 16:47:05  *************/

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

int N, M, K;
vector<vector<int>> tubes;      // tubes[idx]    = list of station connected to idx-th tube
vector<vector<int>> stations;   // stations[idx] = list of tube connected to idx-th station
vector<bool> visited_tube;
vector<bool> visited_station;

int BFS(int init, int goal) {
    if (init == goal) return 1;
    queue<pii> sq; // <station, cost>
    sq.emplace(init, 1);
    visited_station[init] = true;

    while (!sq.empty()) {
        int prev_station, cost;
        tie(prev_station, cost) = sq.front();
        sq.pop();
        for (int tube : stations[prev_station]) {
            if (!visited_tube[tube]) {
                visited_tube[tube] = true;
                for (int station : tubes[tube]) {
                    if (station == goal) {
                        return cost + 1;
                    }
                    if (!visited_station[station]) {
                        visited_station[station] = true;
                        sq.emplace(station, cost + 1);
                    }
                }
            }
        }
    }
    return -1;
}

void Solve(void) {
    cout << BFS(1, N);
}

void Init(void) {
    cin >> N >> K >> M;
    tubes = vector<vector<int>>(M + 1); // resize(tubes, M + 1);
    stations = vector<vector<int>>(N + 1); // resize(stations, N + 1);
    visited_tube = vector<bool>(M + 1); // resize(visited_tube, M + 1);
    visited_station = vector<bool>(N + 1); // resize(visited_station, N + 1);
    for (int i = 1; i < M + 1; i++) {
        for (int j = 0; j < K; j++) {
            int inp; cin >> inp;
            stations[inp].emplace_back(i);
            tubes[i].emplace_back(inp);
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}