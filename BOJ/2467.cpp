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
\*************  2021-01-18 12:48:56  *************/

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
int answer = INF;
int answer_lo;
int answer_hi;
vi liquid;

void Solve(void) {
    int lo = 0, hi = N - 1;
    while (0 <= lo && lo < hi && hi < N) {
        int mid = (lo + hi) / 2;
        if (abs(liquid[lo] + liquid[hi]) < answer) {
            answer = abs(liquid[lo] + liquid[hi]);
            answer_lo = lo;
            answer_hi = hi;
        }
        if (liquid[lo] + liquid[hi] < 0) {
            lo++;
        }
        else if (liquid[lo] + liquid[hi] > 0) {
            hi--;
        }
        else {
            break;
        }
    }
    cout << liquid[answer_lo] << " " << liquid[answer_hi] << endl;
    return;
}

void Init(void) {
    Boost;
    cin >> N;
    liquid.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> liquid[i];
    }
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}