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
\*************  2021-01-16 11:05:40  *************/

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
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int N;
vi left_work;
vi cost;
vi answer;
v<li> preceding;
qi search_queue; // {idx, cost}
void Solve(void) {
    for (int i = 1; i <= N; i++) {
        if (left_work[i] == 0) {
            search_queue.emplace(i);
            answer[i] = cost[i];
        }
    }
    while (!search_queue.empty()) {
        auto front = search_queue.front();
        search_queue.pop();
        while (!preceding[front].empty()) {
            int next = preceding[front].back();
            preceding[front].pop_back();
            if (--left_work[next] == 0) {
                search_queue.push(next);
            }
            answer[next] = max(answer[next], answer[front] + cost[next]);
        }
    }
    sort(answer.rbegin(), answer.rend());
    cout << answer[0] << endl;
    return;
}

void Init(void) {
    Boost;
    cin >> N;
    left_work.resize(N + 1, 0);
    cost.resize(N + 1);
    answer.resize(N + 1, 0);
    preceding.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        int idx;
        cin >> idx;
        left_work[i] = idx;
        for (int j = 0; j < idx; j++) {
            int work;
            cin >> work;
            preceding[work].push_back(i);
        }
    }
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}