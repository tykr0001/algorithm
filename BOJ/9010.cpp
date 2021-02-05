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
\*************  2021-02-03 17:44:40  *************/

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

int T;
int N;
vb is_prime;
vi cache;
int answer_lo;
int answer_hi;

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
    while(T--){
        cin >> N;
        auto lo = cache.begin();
        auto hi = upper_bound(cache.begin(), cache.end(), N);
        hi--;
        while(*lo<=*hi){
            if(*lo + *hi == N){
                answer_lo = *lo;
                answer_hi = *hi;
                lo++;
                hi--;
            }
            else if(*lo + *hi < N){
                lo++;
            }
            else{
                hi--;
            }
        }
        cout << answer_lo << " " << answer_hi << endl;
    }
}

void Init(void) {
    cin >> T;
    is_prime.resize(10001, true);
    is_prime[0] = is_prime[1] = false;
    Eratos(10000);
}

int main(void) {
    Boost;
	Init();
	Solve();
	return 0;
}