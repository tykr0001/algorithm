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
\*************  2021-01-15 22:56:51  *************/

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

int m;
int cnt;
string head_move;
string tail_move;
vvi arr(51, vi(51, 0));

struct {
    int i;
    int j;
} head, tail;

string operator*(string str, int n) {
    string ret;
    while (n--) {
        ret += str;
    }
    return ret;
}

void Solve(void) {
    for (int i = 0; i < head_move.length(); i++) {
        cnt++;
        arr[tail.i][tail.j] = 0;
        if (tail_move[i] == 'N') {
            tail.i--;
        }
        else if (tail_move[i] == 'E') {
            tail.j++;
        }
        else if (tail_move[i] == 'W') {
            tail.j--;
        }
        else {
            tail.i++;
        }

        if (head_move[i] == 'N') {
            head.i--;
        }
        else if (head_move[i] == 'E') {
            head.j++;
        }
        else if (head_move[i] == 'W') {
            head.j--;
        }
        else {
            head.i++;
        }
        if(arr[head.i][head.j] == 1) {
            cout << cnt << " itself" << endl;
            break;
        }
        else if(head.i < 1 || head.i > 50 || tail.i < 1 || tail.j > 50) {
            cout << cnt << " out" << endl;
            break;
        }
        arr[head.i][head.j] = 1;
    }
    cout << cnt << " success" << endl;
}

void Init(void) {
    Boost;
    cin >> m >> head_move;
    string N = "N";
    tail_move = N * 19 + head_move;
    head = { 25, 30 };
    tail = { 25, 11 };
}

int main(void) {
    Init();
    Solve();
    return 0;
}