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
\*************  2021-02-13 22:52:21  *************/

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

int C;
int N, M;
int answer;
vi seats;

void Solve(void) {
    for (int mask = 0; mask < 1 << M; mask++) {
        if (mask & seats[0]) continue;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M; j++) {
                
            }
        }
    }
}

void Init(void) {
    Boost;
    cin >> N >> M;
    seats.clear();
    seats.resize(N, 0);
    answer = 0;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            if (tmp[j] == '.') {
                seats[i] = seats[i] << 1 | 0;
            }
            else {
                seats[i] = seats[i] << 1 | 1;
            }
        }
    }
}

int main(void) {
    Boost;
    cin >> C;
    while (C--) {
        Init();
        Solve();
    }
    return 0;
}