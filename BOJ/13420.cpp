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
\*************  2021-02-14 18:55:40  *************/

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
ll a, b, c;
char op1, op2;

void Solve(void) {
    if (op1 == '+') {
        if (a + b == c) {
            cout << "correct" << endl;
        }
        else {
            cout << "wrong answer" << endl;
        }
    }
    else if (op1 == '-') {
        if (a - b == c) {
            cout << "correct" << endl;
        }
        else {
            cout << "wrong answer" << endl;
        }
    }
    else if (op1 == '*') {
        if (a * b == c) {
            cout << "correct" << endl;
        }
        else {
            cout << "wrong answer" << endl;
        }
    }
    else if (op1 == '/') {
        if (a / b == c) {
            cout << "correct" << endl;
        }
        else {
            cout << "wrong answer" << endl;
        }
    }
}

void Init(void) {
    cin >> a >> op1 >> b >> op2 >> c;
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