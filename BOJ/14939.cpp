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
\*************  2021-02-08 02:27:46  *************/

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

v<string> bulb(10);
int answer;

void Toggle(char& c) {
    if (c == '#') {
        c = 'O';
    }
    else {
        c = '#';
    }
}

void PushButton(v<string>& b, int x, int y) {
    Toggle(b[x][y]);
    if (x > 0) {
        Toggle(b[x - 1][y]);
    }
    if (y > 0) {
        Toggle(b[x][y - 1]);
    }
    if (x < 9) {
        Toggle(b[x + 1][y]);
    }
    if (y < 9) {
        Toggle(b[x][y + 1]);
    }
}

void Solve(void) {
    for (int mask = 0; mask <= (1 << 10) - 1; mask++) {
        v<string> bulb_copy(bulb);
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            if ((1 << i) & mask) {
                PushButton(bulb_copy, 0, i);
                cnt++;
            }
        }
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (bulb_copy[i - 1][j] == 'O') {
                    PushButton(bulb_copy, i, j);
                    cnt++;
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < 10; i++) {
            if (bulb_copy[9][i] == 'O') {
                flag = true;
                break;
            }
        }
        if (flag) {
            cnt = INF;
        }
        answer = min(answer, cnt);
    }
    if (answer == INF) {
        answer = -1;
    }
    cout << answer << endl;
}

void Init(void) {
    Boost;
    for (int i = 0; i < 10; i++) {
        cin >> bulb[i];
    }
    answer = INF;
}

int main(void) {
    Init();
    Solve();
    return 0;
}