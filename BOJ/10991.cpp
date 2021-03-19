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
\*************  2021-03-16 01:21:48  *************/

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

int N;

void Blank(int n) {
    while (n--) cout << ' ';
}

void Star(int n) {
    while (n--) cout << '*';
}

void Solve(void) {
    For(i, 1, N + 1) {
        Blank(N - i);
        For(j, 0, 2 * i - 1) {
            if (j % 2 == 0)
                Star(1);
            else
                Blank(1);
        }
        cout << endl;
    }
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