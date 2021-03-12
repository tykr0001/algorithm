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
\*************  2021-03-12 01:59:39  *************/

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
int answer = INF;
vvi graph;
vb member;

void Backtrack(int idx, int n) {
    if (n == N / 2) {
        int start = 0;
        int link = 0;
        for (int i = 0; i < N; i++) {
            if (member[i]) {
                for (int j = i + 1; j < N; j++) {
                    if (member[j]) {
                        start += graph[i][j] + graph[j][i];
                    }
                }
            }
            else {
                for (int j = i + 1; j < N; j++) {
                    if (!member[j]) {
                        link += graph[i][j] + graph[j][i];
                    }
                }
            }
        }
        answer = min(answer, abs(start - link));
        return;
    }
    for (int i = idx + 1; i < N; i++) {
        member[i] = true;
        Backtrack(i, n + 1);
        member[i] = false;
    }
}

void Solve(void) {
    Backtrack(-1, 0);
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
    graph.resize(N, vi(N));
    member.resize(N, false);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}