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
\*************  2021-01-15 22:56:51  *************/

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

int T;
int N, M, K;
int lo, hi;
int sum;
int answer;
vi money;

void Solve(void) {
    lo = 0; hi = M;
    if (N > M) {
        do {
            if (sum < K) {
                answer++;
            }
            sum = sum - money[lo] + money[hi];
            ++lo;
            if (++hi == N)
                hi = 0;
        } while (lo != N);
    }
    else {
        if (sum < K) {
            answer++;
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N >> M >> K;
    money.clear();
    money.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> money[i];
    }

    sum = 0;
    for (int i = 0; i < M; i++) {
        sum += money[i];
    }

    answer = 0;
}

int main(void) {
    Boost;
    cin >> T;
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}