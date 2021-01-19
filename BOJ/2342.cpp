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
\*************  2021-01-18 12:07:24  *************/

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

// feet position
// 0 => centor, 1 => up, 2 => left, 3 => down, 4 => right
// v<vvi> cache(100000, vvi(5, vi(5, INF)));
int cache[100001][5][5];
int op;
int idx;
int answer = INF;

int cost(int a, int b) {
    if (a == 0 || b == 0) {
        return 2;
    }
    if (abs(a - b) == 1 || abs(a - b) == 3) {
        return 3;
    }
    if (abs(a - b) == 2) {
        return 4;
    }
}

void Solve(void) {
    while (1) {
        cin >> op;
        if (op == 0) {
            break;
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (op == i || op == j) {
                    cache[idx + 1][i][j] = min(cache[idx + 1][i][j], cache[idx][i][j] + 1);
                }
                else {
                    if (op != j) {
                        cache[idx + 1][op][j] = min(cache[idx + 1][op][j], cache[idx][i][j] + cost(op, i));

                    }
                    if (op != i) {
                        cache[idx + 1][i][op] = min(cache[idx + 1][i][op], cache[idx][i][j] + cost(op, j));
                    }
                }
            }
        }
        idx++;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            answer = min(answer, cache[idx][i][j]);
        }
    }
    cout << answer;
    return;
}

void Init(void) {
    Boost;
    memset(cache, 0x3f, sizeof(cache));
    cache[0][0][0] = 0;
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}