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
\*************  2021-03-19 21:05:07  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define v vector
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define vs vector<string> 
#define vc vector<char> 
#define vl vector<ll> 
#define vvl vector<vector<ll>> 
#define pii pair<int,int>
#define pll pair<ll,ll> 
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
typedef long long ll;
/*************************************************/

int V, E;
vvi graph;
vi visited;

bool IsBipartite(void) {
    for (int i = 1; i <= V; i++) {
        for (auto elem : graph[i]) {
            if (visited[i] == visited[elem]) {
                return false;
            }
        }
    }
    return true;
}

void BFS(int init) {
    queue<int> sq;
    sq.emplace(init);
    int color = 1;
    visited[init] = color;
    while (!sq.empty()) {
        auto front = sq.front();
        sq.pop();
        color = 3 - visited[front];
        int toggle;
        for (auto elem : graph[front]) {
            if (!visited[elem]) {
                visited[elem] = color;
                sq.emplace(elem);
            }
        }
    }
}

void Solve(void) {
    for (int i = 1; i < V; i++) {
        if (!visited[i]) {
            BFS(i);
        }
    }
    if (IsBipartite()) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

void Init(void) {
    cin >> V >> E;
    graph.clear();
    graph.resize(V + 1);
    visited.clear();
    visited.resize(V + 1);
    for (int i = 0; i < E; i++) {
        int src, dst;
        cin >> src >> dst;
        graph[src].emplace_back(dst);
        graph[dst].emplace_back(src);
    }
}

int main(void) {
    Boost;
    int t; cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}