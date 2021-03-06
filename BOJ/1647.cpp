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
\*************  2021-01-15 22:56:51  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define v vector 
#define s stack
#define q queue 
#define l list 
#define pq priority_queue 
#define p pair
#define vi vector<int> 
#define si stack<int>
#define qi queue<int>
#define li list<int> 
#define pii pair<int,int>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

class Compare {
public:
    bool operator()(const pii& a, const pii& b) {
        return a.se > b.se;
    }
};

int N;
int M;
v<l<p<int, int>>> graph;
pq<pii, v<pii>, Compare> prim;
v<bool> searched;
int sum;
int heaviest;

void Solve(void) {
    for (auto next_edge : graph[1]) {
        prim.emplace(next_edge);
    }
    searched[1] = true;
    while (!prim.empty()) {
        auto top = prim.top();
        prim.pop();
        if (!searched[top.fi]) {
            searched[top.fi] = true;
            sum += top.se;
            heaviest = max(heaviest, top.se);
            for (auto next_edge : graph[top.fi]) {
                if (!searched[next_edge.fi]) {
                    prim.emplace(next_edge);
                }
            }
        }
    }
    cout << sum - heaviest << endl;
    return;
}

void Init(void) {
    Boost;
    cin >> N >> M;
    graph.resize(N + 1);
    searched.resize(N + 1, false);
    for (int i = 0; i < M; i++) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        graph[src].eb(dst, cost);
        graph[dst].eb(src, cost);
    }
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}