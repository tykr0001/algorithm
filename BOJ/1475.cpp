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
\*************  2021-03-12 02:34:37  *************/

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

string N;
int answer;
vi num(10);

void Solve(void) {
    for (int i = 0; i < N.length(); i++) {
        num[N[i] - '0']++;
    }
    int tmp = num[6] + num[9];
    if (tmp % 2 == 1) {
        num[6] = num[9] = tmp / 2 + 1;
    }
    else {
        num[6] = num[9] = tmp / 2;
    }
    for (int i = 0; i < 10; i++) {
        answer = max(answer, num[i]);
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}