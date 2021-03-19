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
\*************  2021-03-19 20:51:55  *************/

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

int N;

void Star(int n) {
    if (n < 0) return;
    while (n--) cout << "*";
}

void Blank(int n) {
    if (n < 0) return;
    while (n--) cout << " ";
}

void Solve(void) {
    Blank(N - 1);
    Star(1);
    if (N == 1) return;
    cout << endl;
    for (int i = 2; i < N; i++) {
        Blank(N - i);
        Star(1);
        Blank(2 * i - 3);
        Star(1);
        cout << endl;
    }
    Star(2 * N - 1);
}

void Init(void) {
    cin >> N;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}