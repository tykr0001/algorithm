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
\*************  2021-02-03 23:43:09  *************/

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

vb is_prime;
vi cache;
int N, K;
int cnt;

void Solve(void) {
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i; j <= N; j += i) {
                if (is_prime[j]) {
                    is_prime[j] = false;
                    if (++cnt == K) {
                        cout << j << endl;
                        return;
                    }
                }
            }
        }
    }
}

void Init(void) {
    Boost;
    cin >> N >> K;
    is_prime.resize(N + 1, true);
    is_prime[0] = is_prime[1] = false;
}

int main(void) {
    Init();
    Solve();
    return 0;
}