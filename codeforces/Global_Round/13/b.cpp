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
\*************  2021-02-28 23:00:37  *************/

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

int t;
int N, U, V;
vi graph;
ll answer;

void Solve(void) {
    for (int i = 1; i <= N - 1; i++) {
        int j = i + 1;
        if (abs(graph[i] - graph[j]) == 1) {
            answer = min(min(answer, ll(U)), ll(V));
        }
        else if (graph[i] == graph[j]) {
            answer = min(min(answer, ll(U + V)), ll(2 * V));
        }
        else {
            answer = 0;
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N >> U >> V;
    answer = LINF;
    graph.clear();
    graph.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        int j;
        cin >> j;
        graph[i] = j;
    }
}

int main(void) {
    Boost;
    cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}