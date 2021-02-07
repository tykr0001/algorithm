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
\*************  2021-02-07 22:18:33  *************/

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

int m, n, row, col;
int i, j;
int loop;
// 0 => right, 1 ==> down, 2 => left, 3 => up
int state = 0;
vvi arr;

void Solve(void) {
    while (loop--) {
        arr[i][j] = m++;
        switch (state) {
        case 0:
            j++;
            if (j == n || arr[i][j + 1] != -1) {
                state = 1;
            }
            break;
        case 1:
            i++;
            if (i == n || arr[i + 1][j] != -1) {
                state = 2;
            }
            break;
        case 2:
            j--;
            if (j == 1 || arr[i][j - 1] != -1) {
                state = 3;
            }
            break;
        case 3:
            i--;
            if (i == 1 || arr[i - 1][j] != -1) {
                state = 0;
            }
            break;
        default:
            break;
        }
    }
    cout << arr[row][col] << endl;
}

void Init(void) {
    Boost;
    cin >> m >> n >> row >> col;
    arr.resize(n + 1, vi(n + 1, -1));
    i = j = 1;
    loop = n * n;
}

int main(void) {
    Init();
    Solve();
    return 0;
}