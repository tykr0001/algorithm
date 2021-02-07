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
\*************  2021-02-08 03:15:42  *************/

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
int M;
int k;
int answer;
vi parent;
vi A;

int Find(int node) {
    if (parent[node] == 0) {
        return node;
    }
    else {
        return parent[node] = Find(parent[node]);
    }
}

void Union(int a, int b) {
    if (A[Find(a)] > A[Find(b)]) {
        parent[Find(a)] = Find(b);
    }
    else {
        parent[Find(b)] = Find(a);
    }
}

void Solve(void) {
    for (int i = 1; i <= N; i++) {
        if (parent[i] == 0) {
            answer += A[i];
        }
    }
    if (answer <= k) {
        cout << answer << endl;
    }
    else {
        cout << "Oh no" << endl;
    }
}

void Init(void) {
    Boost;
    cin >> N >> M >> k;
    parent.resize(N + 1, 0);
    A.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        int src, dst;
        cin >> src >> dst;
        if (Find(src) != Find(dst)) {
            Union(src, dst);
        }
    }
}

int main(void) {
    Init();
    Solve();
    return 0;
}