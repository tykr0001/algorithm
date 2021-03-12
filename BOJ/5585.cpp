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
\*************  2021-03-12 05:15:22  *************/

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

int money;
int answer;

void Solve(void) {
    money = 1000 - money;
    while (money >= 500) {
        answer++;
        money -= 500;
    }
    while (money >= 100) {
        answer++;
        money -= 100;
    }
    while (money >= 50) {
        answer++;
        money -= 50;
    }
    while (money >= 10) {
        answer++;
        money -= 10;
    }
    while (money >= 5) {
        answer++;
        money -= 5;
    }
    while (money >= 1) {
        answer++;
        money -= 1;
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> money;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}