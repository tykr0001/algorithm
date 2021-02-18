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
\*************  2021-02-14 01:36:42  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define v vector
#define s stack
#define q queue 
#define l list 
#define pq priority_queue 
#define p pair
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define si stack<int>
#define qi queue<int>
#define li list<int> 
#define pii pair<int,int>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int N;
vvi graph;
vb visited;
vi inputs;
vi order;
vi built;

void DFS(int node) {
    if (!visited[node]) {
        built.emplace_back(node);
        visited[node] = true;
        for (auto child : graph[node]) {
            if (!visited[child]) {
                visited[node] = true;
                DFS(child);
            }
        }
    }
}

bool Compare(int a, int b) {
    return order[a] < order[b];
}

void Solve(void) {
    DFS(1);
    if (built == inputs) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}

void Init(void) {
    Boost;
    cin >> N;
    graph.resize(N + 1);
    visited.resize(N + 1, false);
    inputs.resize(N + 1, 0);
    order.resize(N + 1, 0);
    built.emplace_back(0);

    for (int i = 0; i < N - 1; i++) {
        int src, dst;
        cin >> src >> dst;
        graph[src].emplace_back(dst);
        graph[dst].emplace_back(src);
    }

    for (int i = 1; i <= N; i++) {
        cin >> inputs[i];
        order[inputs[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        sort(graph[i].begin(), graph[i].end(), Compare);
    }
}

int main(void) {
    Init();
    Solve();
    return 0;
}