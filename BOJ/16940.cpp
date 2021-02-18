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
\*************  2021-02-14 01:35:55  *************/

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
qi order;

int BFS(int init) {
    vb visited(N + 1, false);
    qi sq;
    sq.emplace(init);
    visited[init] = true;
    while (!sq.empty()) {
        int parent = sq.front();
        sq.pop();
        set<int> childs;
        for (auto child : graph[parent]) {
            if (!visited[child]) {
                visited[child] = true;
                childs.emplace(child);
            }
        }

        for (int i = 0; i < childs.size(); i++) {
            int next = order.front();
            order.pop();

            if (childs.find(next) != childs.end()) {
                sq.emplace(next);
            }
            else {
                return 0;
            }
        }
    }
    return 1;
}

void Solve(void) {
    int init = order.front();
    order.pop();
    if (init != 1) {
        cout << 0;
        return;
    }
    cout << BFS(init);
}

void Init(void) {
    Boost;
    cin >> N;
    graph.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int src, dst;
        cin >> src >> dst;
        graph[src].emplace_back(dst);
        graph[dst].emplace_back(src);
    }

    for (int i = 0; i < N; i++) {
        int inp;
        cin >> inp;
        order.emplace(inp);
    }
}

int main(void) {
    Init();
    Solve();
    return 0;
}