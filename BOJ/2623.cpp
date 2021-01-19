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
\*************  2021-01-18 18:17:45  *************/

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
#define INF 2e9
#define LINF 9e18
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int N, M;
v<vi> graph;
vi need;
qi search_queue;
qi answer_queue;
int cnt;

void Solve(void) {
    for (int i = 1; i <= N; i++) {
        if (need[i] == 0) {
            search_queue.emplace(i);
        }
    }

    while (!search_queue.empty()) {
        int front = search_queue.front();
        search_queue.pop();
        answer_queue.emplace(front);
        cnt++;
        for (int i = 0; i < graph[front].size(); i++) {
            if (--need[graph[front][i]] == 0) {
                search_queue.emplace(graph[front][i]);
            }
        }
    }

    if (cnt == N) {
        while (!answer_queue.empty()) {
            cout << answer_queue.front() << endl;
            answer_queue.pop();
        }
    }
    else {
        cout << 0 << endl;
    }
    return;
}

void Init(void) {
    Boost;
    cin >> N >> M;
    graph.resize(N + 1);
    need.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int num, src, dst;
        cin >> num;
        cin >> src;
        for (int j = 0; j < num - 1; j++) {
            cin >> dst;
            graph[src].emplace_back(dst);
            src = dst;
        }
    }
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
        graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
        for (int j = 0; j < graph[i].size(); j++) {
            need[graph[i][j]]++;
        }
    }
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}