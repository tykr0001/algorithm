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
\*************  2021-01-16 02:24:02  *************/

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

int N, S;
int answer = INF;
vi sequence;

void Solve(void) {
    int lo = 0, hi = 0;
    int sum = sequence[0];
    while (lo <= hi && hi < sequence.size()) {
        if (sum < S) {
            sum += sequence[++hi];
        }
        else {
            answer = min(answer, hi - lo + 1);
            sum -= sequence[lo++];
        }
    }
    if (answer == INF) {
        answer = 0;
    }
    cout << answer << endl;
    return;
}

void Init(void) {
    Boost;
    cin >> N >> S;
    sequence.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}