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
\*************  2021-03-17 23:59:48  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define v vector
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define vs vector<string> 
#define vc vector<char> 
#define vl vector<ll> 
#define vvl vector<vector<ll>> 
#define pii pair<int,int>
#define pll pair<ll,ll> 
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
typedef long long ll;
/*************************************************/

int n, m;
int answer;
vi a;
vi r;

void Solve(void) {
    answer = 1;
    int lo = 1, hi = m - 1;
    while (lo < hi) {
        if (r[lo] != 0 && r[hi] != 0) {
            int gap = abs(r[lo] - r[hi]);
            if (gap > 1)
                answer += gap - 1;
            answer++;
        }
        else {
            answer += r[lo] + r[hi];
        }
        lo++;
        hi--;
        if (lo == hi) {
            answer++;
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> n >> m;
    a.clear();
    a.resize(n);
    r.clear();
    r.resize(m);
    rep(i, 0, n) {
        cin >> a[i];
        r[a[i] % m]++;
    }
}

int main(void) {
    Boost;
    int t;
    cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}