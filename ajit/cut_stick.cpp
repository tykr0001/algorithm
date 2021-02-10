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

int L, K;
vi arr;
int answer;

void BinarySearch(int lo, int hi) {
    if (hi - lo == 2){
        answer += arr[hi] - arr[lo];
    } 
    else if (hi - lo > 2) {
        answer += arr[hi] - arr[lo];
        int mid = (arr[hi] + arr[lo]) / 2;
        auto idx = lower_bound(arr.begin() + lo, arr.begin() + hi + 1, mid);
        int mid_idx = abs(mid - *(idx - 1)) < abs(mid - *(idx)) ? distance(arr.begin(), idx - 1) : distance(arr.begin(), idx);
        BinarySearch(lo, mid_idx);
        BinarySearch(mid_idx, hi);
    }
}

void Solve(void) {
    BinarySearch(0, arr.size() - 1);
    cout << answer << endl;
}

void Init(void) {
    Boost;
    cin >> L >> K;
    arr.resize(K + 2);
    arr[0] = 0;
    for (int i = 1; i <= K; i++) {
        cin >> arr[i];
    }
    arr[K + 1] = L;
    sort(arr.begin(), arr.end());
}

int main(void) {
    Init();
    Solve();
    return 0;
}