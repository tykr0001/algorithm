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
\*************  2021-01-21 12:06:18  *************/

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
#define LINF 9e18
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

string a;
string b;

void LCS(void) {
    int idx_a = a.length();
    int idx_b = b.length();
    vector<vector<int>> cache(idx_a + 1, vector<int>(idx_b + 1, 0));
    string answer = "";
    for (int i = 0; i < idx_a; i++) {
        for (int j = 0; j < idx_b; j++) {
            if (a[i] == b[j]) {
                cache[i + 1][j + 1] = cache[i][j] + 1;
            }
            else {
                cache[i + 1][j + 1] = max(cache[i + 1][j], cache[i][j + 1]);
            }
        }
    }

    cout << cache[idx_a][idx_b] << endl;
    while (idx_a && idx_b && cache[idx_a][idx_b]) {
        if (cache[idx_a][idx_b] == cache[idx_a - 1][idx_b]) {
            idx_a--;
        }
        else if (cache[idx_a][idx_b] == cache[idx_a][idx_b - 1]) {
            idx_b--;
        }
        else if (cache[idx_a][idx_b] == cache[idx_a - 1][idx_b - 1] + 1) {
            answer += a[idx_a - 1];
            idx_a--;
            idx_b--;
        }
    }
    for (auto iter = answer.rbegin(); iter != answer.rend(); iter++) {
        cout << *iter;
    }
}

void Solve(void) {
    LCS();
    return;
}

void Init(void) {
    Boost;
    cin >> a >> b;
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}