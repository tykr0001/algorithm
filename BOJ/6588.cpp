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
#define pb push_back
#define eb emplace_back
#define v vector 
#define s stack
#define q queue 
#define l list 
#define p pair
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

ll n;
vector<bool> cache(1000001, true);
vector<ll> prime;

void Eratos(void) {
    cache[0] = cache[1] = false;
    for (ll i = 2; i <= 1000000; i++) {
        if (cache[i]) {
            prime.pb(i);
            for (ll j = i * 2; j <= 1000000; j += i) {
                cache[j] = false;
            }
        }
    }
}
void Solve(void) {
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        ll lo = 1, hi = 1;
        while(prime[hi] < n && hi < prime.size()){
            hi++;
        }
        hi--;
        while (lo <= hi) {
            if(prime[lo] + prime[hi] < n){
                lo++;
            }
            else if(prime[lo] + prime[hi] > n){
                hi--;
                lo = 1;
            }
            else{
                cout << n << " = " << prime[lo] << " + " << prime[hi] << endl;
                break;
            }
        }
    }
    return;
}

void Init(void) {
    Boost;
    Eratos();
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}