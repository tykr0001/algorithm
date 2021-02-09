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

int n;
vb is_prime;
vi cache;
int answer;

void Eratos(int n) {
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            cache.emplace_back(i);
            for (int j = i * 2; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void Solve(void) {
    int lo = 0;
    int hi = 0;
    int tmp = cache[lo];
    while (lo <= hi && hi < cache.size()) {
        if (tmp > n) {
            tmp -= cache[lo];
            lo++;
        }
        else {
            if (tmp == n) {
                answer++;
            }
            hi++;
            tmp += cache[hi];
        }
    }
    cout << answer << endl;
}

void Init(void) {
    Boost;
    cin >> n;
    is_prime.resize(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    Eratos(n);

}

int main(void) {
    Init();
    Solve();
    return 0;
}