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
\*************  2021-03-16 00:13:58  *************/

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

int N, M;
int answer;
vi arr;

void Solve(void) {
    int lo = 0;
    int hi = 0;
    int sum = arr[lo];
    while (lo < N && hi < N) {
        if (sum > M) {
            sum -= arr[lo++];
        }
        else if (sum < M) {
            sum += arr[++hi];
        }
        else {
            answer++;
            sum -= arr[lo++];
            sum += arr[++hi];
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N >> M;
    arr.resize(N);
    For(i, 0, N) {
        cin >> arr[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}