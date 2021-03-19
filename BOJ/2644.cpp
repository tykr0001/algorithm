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
\*************  2021-03-16 01:29:12  *************/

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
#define For(i,beg,end) for(int i=beg; i<end; i++)
typedef long long ll;
/*************************************************/

int n, m;
int a, b;
vvi graph;
vb visited;

int BFS(int init, int goal) {
    q<pii> sq;
    sq.emplace(init, 0);
    visited[init] = true;
    while (!sq.empty()) {
        auto front = sq.front();
        sq.pop();
        for (int elem : graph[front.fi]) {
            if (!visited[elem]) {
                if (elem == goal) {
                    return front.se + 1;
                }
                sq.emplace(elem, front.se + 1);
                visited[elem] = true;
            }
        }
    }
    return -1;
}

void Solve(void) {
    cout << BFS(a, b);
}

void Init(void) {
    cin >> n;
    cin >> a >> b;
    graph.resize(n + 1);
    visited.resize(n + 1);
    cin >> m;
    For(i, 0, m) {
        int x, y;
        cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}