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
\*************  2021-02-06 05:05:30  *************/

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
vb visited;
void Solve(void) {
    q<tuple<int, int, vi>> search_q; // {node, depth, path}
    search_q.emplace(N, 0, vi(1, N));
    visited[N] = true;
    while (!search_q.empty()) {
        auto front = search_q.front();
        search_q.pop();
        int node = get<0>(front);
        int depth = get<1>(front);
        vi path = get<2>(front);
        if (node == 1) {
            cout << depth << endl;
            for (auto elem : path) {
                cout << elem << " ";
            }
            break;
        }

        if (node % 3 == 0 && !visited[node / 3]) {
            visited[node % 3] = true;
            path.emplace_back(node / 3);
            search_q.emplace(node / 3, depth + 1, path);
            path.pop_back();
        }
        if (node % 2 == 0 && !visited[node / 2]) {
            visited[node % 2] = true;
            path.emplace_back(node / 2);
            search_q.emplace(node / 2, depth + 1, path);
            path.pop_back();
        }
        if (!visited[node - 1]) {
            visited[node - 1] = true;
            path.emplace_back(node - 1);
            search_q.emplace(node - 1, depth + 1, path);
            path.pop_back();
        }
    }
}

void Init(void) {
    Boost;
    cin >> N;
    visited.resize(N + 1, false);
}

int main(void) {
    Init();
    Solve();
    return 0;
}