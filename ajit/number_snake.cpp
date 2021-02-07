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
\*************  2021-02-07 21:04:29  *************/

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

int N;
int num;
int loop;
int i, j;
vvi arr;
// 0 => right, 1 => left-down, 2 => down, 3 => right-up
int state;


void Solve(void) {
    while (loop--) {
        arr[i][j] = ++num;
        switch (state) {
        case 0:
            j++;
            if (i == 0) {
                state = 1;
            }
            else {
                state = 3;
            }
            break;
        case 1:
            i++;
            j--;
            if (i == N - 1) {
                state = 0;
            }
            else if (j == 0) {
                state = 2;
            }
            break;
        case 2:
            i++;
            if (j == 0) {
                state = 3;
            }
            else {
                state = 1;
            }
            break;
        case 3:
            i--;
            j++;
            if (j == N - 1) {
                state = 2;
            }
            else if (i == 0) {
                state = 0;
            }
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Init(void) {
    Boost;
    cin >> N;
    arr.resize(N, vi(N));
    loop = N * N;
}

int main(void) {
    Init();
    Solve();
    return 0;
}