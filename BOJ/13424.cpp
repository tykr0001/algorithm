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

int T;
int N, M, K;
vvi g;
vi loc;
int min_idx;
int min_len;

// Floyd-Warshall(플로이드와샬) 
// @param graph : graph[src][dst] is a weight of the edge which connects src to dst
// @param size  : graph size or number of vertex
// @return      : void
void FloydWarshall(vvi& graph, int size) {
    for (int k = 1; k <= size; k++) { // 중간
        for (int i = 1; i <= size; i++) { // 시작
            for (int j = 1; j <= size; j++) { // 끝
                graph[i][j] = graph[j][i] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

void Solve(void) {
    FloydWarshall(g, N);

    for (int i = 1; i <= N; i++) {
        int tmp = 0;
        for (int j = 0; j < K; j++) {
            tmp += g[i][loc[j]];
        }
        if (min_len > tmp) {
            min_len = tmp;
            min_idx = i;
        }
    }
    cout << min_idx << endl;
}

void Init(void) {
    cin >> N >> M;
    g.clear();
    g.resize(N + 1, vi(N + 1, 2000));

    for (int i = 1; i <= N; i++) {
        g[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
        g[b][a] = c;
    }

    cin >> K;
    loc.clear();
    loc.resize(K);
    for (int i = 0; i < K; i++) {
        cin >> loc[i];
    }
    min_idx = 0;
    min_len = INF;
}

int main(void) {
    Boost;
    cin >> T;
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}