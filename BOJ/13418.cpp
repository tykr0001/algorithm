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
\*************  2021-02-14 17:38:20  *************/

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

struct edge {
    int weight;
    int src;
    int dst;
};

class Less {
public:
    bool operator()(edge a, edge b) {
        return a.weight < b.weight;
    }
};

class Greater {
public:
    bool operator()(edge a, edge b) {
        return a.weight > b.weight;
    }
};

int N, M;
pq<edge, vector<edge>, Greater> min_edges;
pq<edge, vector<edge>, Less> max_edges;
vi parent;
int min_len;
int max_len;

int Find(int node) {
    if (parent[node] == -1 || parent[node] == node) {
        return node;
    }
    else {
        return parent[node] = Find(parent[node]);
    }
}

void Union(int a, int b) {
    parent[Find(a)] = Find(b);
}

void Solve(void) {
    parent.clear();
    parent.resize(N + 1, -1);
    parent[0] = 0;
    while (!min_edges.empty()) {
        edge top = min_edges.top();
        min_edges.pop();
        if (Find(top.src) != Find(top.dst)) {
            Union(top.src, top.dst);
            min_len += top.weight;
        }
    }

    parent.clear();
    parent.resize(N + 1, -1);
    parent[0] = 0;
    while (!max_edges.empty()) {
        edge top = max_edges.top();
        max_edges.pop();
        if (Find(top.src) != Find(top.dst)) {
            Union(top.src, top.dst);
            max_len += top.weight;
        }
    }

    cout << max_len * max_len - min_len * min_len << endl;
}

void Init(void) {
    cin >> N >> M;
    for (int i = 0; i < M + 1; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        min_edges.push(edge({ abs(C - 1),A,B }));
        max_edges.push(edge({ abs(C - 1),A,B }));
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}