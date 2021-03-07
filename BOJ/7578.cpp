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
\*************  2021-02-28 16:18:39  *************/

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

int N;
ll answer;
v<ll> a;
v<ll> b;
v<ll> tree;

ll Update(int node, int start, int end, int idx, ll diff) {
    if (idx < start || idx > end) {
        return tree[node];
    }
    if (start == end) {
        return tree[node] += diff;
    }
    else {
        return tree[node] = Update(node * 2, start, (start + end) / 2, idx, diff) + Update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
    }
}

ll Sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    else {
        return Sum(node * 2, start, (start + end) / 2, left, right) + Sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    }
}

void Solve(void) {
    for (int i = 0; i < N; i++) {
        answer += Sum(1, 0, N - 1, b[i] + 1, N - 1);
        Update(1, 0, N - 1, b[i], 1);
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
    a.resize(1000001);
    b.resize(N);
    tree.resize(1 << int(ceil(log2(N))) + 1);

    for (int i = 0; i < N; i++) {
        ll inp;
        cin >> inp;
        a[inp] = i;
    }
    for (int i = 0; i < N; i++) {
        ll inp;
        cin >> inp;
        b[i] = a[inp];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}