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
\*************  2021-03-31 11:49:15  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vc = vector<char>;
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
/*************************************************/

int F, S, G, U, D;
int answer;
vb visited;

int BFS() {
    queue<pii> sq;
    sq.emplace(S, 0);
    visited[S] = true;
    while (!sq.empty()) {
        auto front = sq.front();
        sq.pop();
        if (front.fi == G) return front.se;
        if (front.fi + U <= F && !visited[front.fi + U]) {
            sq.emplace(front.fi + U, front.se + 1);
            visited[front.fi + U] = true;
        }
        if (front.fi - D >= 1 && !visited[front.fi - D]) {
            sq.emplace(front.fi - D, front.se + 1);
            visited[front.fi - D] = true;
        }
    }
    return -1;
}

void Solve(void) {
    answer = BFS();
    if (answer != -1)
        cout << answer;
    else
        cout << "use the stairs";
}

void Init(void) {
    cin >> F >> S >> G >> U >> D;
    visited.resize(F + 1);
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}