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
\*************  2021-02-14 18:55:31  *************/

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
string str;
string A, B;

void Solve(void) {
    str += str;
    for (int i = 0; i < str.length(); i++) {
        if (i % 2) {
            B += str[i];
        }
        else {
            A += str[i];
        }
    }
    for (int i = 1; i < A.length(); i++) {
        if (A.length() % i == 0) {
            string tmp = "";
            string pattern = "";
            for (int j = 0; j < i; j++) {
                pattern += A[j];
            }
            for (int j = 0; j < A.length() / i; j++) {
                tmp += pattern;
            }
            if (A == tmp) {
                A = pattern;
                break;
            }
        }
    }
    for (int i = 1; i < B.length(); i++) {
        if (B.length() % i == 0) {
            string tmp = "";
            string pattern = "";
            for (int j = 0; j < i; j++) {
                pattern += B[j];
            }
            for (int j = 0; j < B.length() / i; j++) {
                tmp += pattern;
            }
            if (B == tmp) {
                B = pattern;
                break;
            }
        }
    }
    cout << A << endl << B << endl;
}

void Init(void) {
    cin >> str;
    A = "";
    B = "";
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