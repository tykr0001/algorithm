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
\*************  2021-03-02 23:35:50  *************/

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

string a;
char open;
char close;
char other;
int cnt;

void Solve(void) {
    open = a.front();
    close = a.back();
    if (open == close) {
        cout << "NO" << endl;
        return;
    }
    if (open == 'A' && close == 'B') other = 'C';
    else if (open == 'A' && close == 'C') other = 'B';
    else if (open == 'B' && close == 'A') other = 'C';
    else if (open == 'B' && close == 'C') other = 'A';
    else if (open == 'C' && close == 'A') other = 'B';
    else if (open == 'C' && close == 'B') other = 'A';

    for (char& elem : a) {
        if (elem == open)
            cnt++;
        else if (elem == close) {
            cnt--;
        }
    }

    if (cnt > 0) {
        cnt = 0;
        bool flag = true;
        for (char& elem : a) {
            if (elem == open)
                cnt++;
            else if (elem == close) {
                cnt--;
            }
            else {
                cnt--;
            }
            if (cnt < 0) {
                flag = false;
                break;
            }
        }
        if (flag && cnt == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else {
        cnt = 0;
        bool flag = true;
        for (char& elem : a) {
            if (elem == open)
                cnt++;
            else if (elem == close) {
                cnt--;
            }
            else {
                cnt++;
            }
            if (cnt < 0) {
                flag = false;
                break;
            }
        }
        if (flag && cnt == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

void Init(void) {
    cin >> a;
    cnt = 0;
}

int main(void) {
    Boost;
    int t; cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}