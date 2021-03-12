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
\*************  2021-03-13 00:51:32  *************/

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
#define For(i,n) for(int i=0; i<n; i++)
typedef long long ll;
/*************************************************/

int N;
int answer;
vi A;
vi cache;

void Solve(void) {
    For(i, N) {
        For(j, i) {
            if (A[i] > A[j]) {
                cache[i] = max(cache[i], cache[j] + A[i]);
            }
        }
    }
    For(i, N) {
        answer = max(answer, cache[i]);

    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
    A.resize(N);
    cache.resize(N);
    For(i, N) {
        cin >> A[i];
        cache[i] = A[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}