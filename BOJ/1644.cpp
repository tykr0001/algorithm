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
\*************  2021-01-15 13:54:36  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define eb emplace_back
#define v vector 
#define s stack
#define q queue 
#define l list 
#define p pair
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<end;
/*************************************************/

int N;
int answer;
vector<bool> cache;
vector<int> prime;

void TwoPointer(void) {
    if (prime.empty()) {
        cout << 0 << endl;
        return;
    }
    int lo = 0, hi = 0;
    int sum = prime[lo];
    while (lo <= hi && hi < prime.size() && prime[hi] <= N) {
        if (sum < N) {
            sum += prime[++hi];
        }
        else if (sum > N) {
            sum -= prime[lo++];
        }
        else {
            sum += prime[++hi];
            sum -= prime[lo++];
            answer++;
        }
    }
    cout << answer << endl;
    return;
}

void Eratos(void) {
    cache.resize(N + 1, true);
    for (int i = 2; i <= N; i++) {
        if (cache[i]) {
            prime.eb(i);
            for (int j = i * 2; j <= N; j += i) {
                cache[j] = false;
            }
        }
    }
}

void Init(void) {
    cin >> N;
    Eratos();
}

int main(void) {
    Init();
    TwoPointer();
    return 0;
}