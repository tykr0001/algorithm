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
\*************  2021-01-21 16:21:11  *************/

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

int T;

void Solve(void) {
    while (T--) {
        int N;
        cin >> N;
        int answer = N;
        vi stud(N + 1);
        vb visited(N + 1, false);
        for (int i = 1; i < N + 1; i++) {
            cin >> stud[i];
        }


        for (int i = 1; i < N + 1; i++) {
            int root = i;
            int prev = root;
            int next = stud[prev];
            int cnt = 1;
            vi group;
            group.emplace_back(prev);
            visited[prev] = true;
            while (root != next && prev != next && !visited[next]) {
                group.emplace_back(next);
                visited[next] = true;
                prev = next;
                next = stud[next];
                cnt++;
            }
            if (root == next) {
                answer -= cnt;
            }
            else {
                for (auto i : group) {
                    visited[i] = false;
                }
            }
        }
        cout << answer << endl;
    }
    return;
}

void Init(void) {
    Boost;
    cin >> T;
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}