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
\*************  2021-03-17 23:33:24  *************/

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

int n;
int num;
vi a;
vi b;
vi nums;

void Solve(void) {
    num = 0;
    for (int i = 0; i < a.size(); i++) {
        while (a[i] == num)
            num++;
    }
    int ai = 0;
    for (int i = 0; i < b.size(); i++) {
        if (a[ai] == b[i]) {
            cout << b[i] << ' ';
            ai++;
        }
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
        nums[a[i]]--;
    }
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i]) {
            cout << i << ' ';
            nums[i]--;
        }
    }
    cout << endl;
}

void Init(void) {
    cin >> n;
    a.clear();
    a.resize(n);
    nums.clear();
    nums.resize(101);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        nums[a[i]]++;
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
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