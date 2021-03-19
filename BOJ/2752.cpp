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
\*************  2021-03-19 20:59:50  *************/

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

vi arr(3);

void Solve(void) {
    for (auto elem : arr) {
        cout << elem << " ";
    }
}

void Init(void) {
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}