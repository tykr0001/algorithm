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
\*************  2021-02-04 01:59:11  *************/

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

int A, B;
int answer;
int cnt;
int n;

void Solve(void) {
    n = 1;
    cnt = 0;
    for (int i = 1; i <= A - 1; i++) {
        answer -= n;
        cnt++;
        if (cnt == n) {
            n++;
            cnt = 0;
        }
    }
    n = 1;
    cnt = 0;
    for (int i = 1; i <= B; i++) {
        answer += n;
        cnt++;
        if (cnt == n) {
            n++;
            cnt = 0;
        }
    }
    cout << answer << endl;
}

void Init(void) {
    Boost;
    cin >> A >> B;
}

int main(void) {
    Init();
    Solve();
    return 0;
}