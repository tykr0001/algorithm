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
\*************  2021-03-15 04:13:34  *************/

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

int N, M, K;
int answer;
vvi arr;

void Solve(void) {
    cin >> K;
    while (K--) {
        int ii, ij, gi, gj;
        cin >> ii >> ij >> gi >> gj;
        answer = 0;
        For(i, 1, N + 1) {
            For(j, 1, M + 1) {
                if (ii <= i && i <= gi && ij <= j && j <= gj) {
                    answer += arr[i][j];
                }
            }
        }
        cout << answer << endl;
    }
}

void Init(void) {
    cin >> N >> M;
    arr.resize(N + 1, vi(M + 1));
    For(i, 1, N + 1) {
        For(j, 1, M + 1) {
            cin >> arr[i][j];
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}