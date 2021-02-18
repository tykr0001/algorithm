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
\*************  2021-02-14 14:21:16  *************/

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

int K, L, cnt;
map<int, int> sid;
v<pii> sorted_sid;

bool Compare(const pii a, const pii b) {
    return a.second < b.second;
}

void Solve(void) {
    sorted_sid = v<pii>(sid.begin(), sid.end());
    sort(sorted_sid.begin(), sorted_sid.end(), Compare);
    for (int i = 0; i < sorted_sid.size(); i++) {
        cout << setfill('0') << setw(8) << right << sorted_sid[i].first << endl;
        if (++cnt == K) {
            break;
        }
    }
}

void Init(void) {
    cin >> K >> L;
    for (int i = 0; i < L; i++) {
        int key;
        cin >> key;
        sid[key] = i;
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}