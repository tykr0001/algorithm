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
\*************  2021-02-20 15:16:11  *************/

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

string king;
string stone;
int N;

string NextPos(string str, string op) {
    if (op == "R") {
        str[0]++;
    }
    else if (op == "L") {
        str[0]--;
    }
    else if (op == "B") {
        str[1]--;
    }
    else if (op == "T") {
        str[1]++;
    }
    else if (op == "RT") {
        str[0]++;
        str[1]++;
    }
    else if (op == "LT") {
        str[0]--;
        str[1]++;
    }
    else if (op == "RB") {
        str[0]++;
        str[1]--;
    }
    else if (op == "LB") {
        str[0]--;
        str[1]--;
    }

    return str;
}

bool CanMove(string str) {
    return 'A' <= str[0] && str[0] <= 'H' && '1' <= str[1] && str[1] <= '8';
}

void Solve(void) {
    for (int i = 0; i < N; i++) {
        string op;
        cin >> op;
        string next_king = NextPos(king, op);
        if (CanMove(next_king)) {
            string next_stone = NextPos(stone, op);
            if (next_king == stone && CanMove(next_stone)) {
                king = next_king;
                stone = next_stone;
            }
            else if (next_king != stone) {
                king = next_king;
            }
        }
    }
    cout << king << endl << stone << endl;
}

void Init(void) {
    cin >> king >> stone >> N;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}