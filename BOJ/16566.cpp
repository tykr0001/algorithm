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
\*************  2021-02-08 10:06:43  *************/

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

int N, M, K;
vi card;
vi op;
vb selected;

void Solve(void) {
    for (int i = 0; i < K; i++) {
        int idx = distance(card.begin(), upper_bound(card.begin(), card.end(), op[i]));
        while (selected[idx]) {
            idx++;
        }
        selected[idx] = true;
        cout << card[idx] << endl;
    }
}

void Init(void) {
    Boost;
    cin >> N >> M >> K;
    card.resize(N);
    op.resize(N);
    selected.resize(N, false);
    for (int i = 0; i < M; i++) {
        cin >> card[i];
    }
    sort(card.begin(), card.end());
    for (int i = 0; i < K; i++) {
        cin >> op[i];
    }
}

int main(void) {
    Init();
    Solve();
    return 0;
}