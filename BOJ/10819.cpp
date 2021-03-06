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
\*************  2021-03-15 23:52:12  *************/

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

int N;
int answer;
vi arr;
vi order;
vb visited;

void BackTrack(int cnt) {
    if (cnt == N - 1) {
        int tmp = 0;
        For(i, 0, N - 1) {
            tmp += abs(order[i] - order[i + 1]);
        }
        answer = max(answer, tmp);
    }
    For(i, 0, N) {
        if (!visited[i]) {
            order[cnt + 1] = arr[i];
            visited[i] = true;
            BackTrack(cnt + 1);
            visited[i] = false;
        }
    }
}

void Solve(void) {
    BackTrack(-1);
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
    arr.resize(N);
    order.resize(N);
    visited.resize(N);
    For(i, 0, N) {
        cin >> arr[i];
        order[i] = i;
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}