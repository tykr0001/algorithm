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

int N, M, K;
v<ll> arr;
v<ll> tree;

ll InitSegmentTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = InitSegmentTree(node * 2, start, (start + end) / 2) + InitSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end);
    }
}

void UpdateSegmentTree(int node, int start, int end, int idx, ll k) {
    if (idx < start || idx > end) {
        return;
    }
    if (start == end) {
        tree[node] = k;
    }
    else {
        UpdateSegmentTree(node * 2, start, (start + end) / 2, idx, k);
        UpdateSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end, idx, k);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

ll SumSegmentTree(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return SumSegmentTree(node * 2, start, (start + end) / 2, left, right) + SumSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void Solve(void) {
    InitSegmentTree(1, 0, N - 1);
    M += K;
    while (M--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            arr[b - 1] = c;
            UpdateSegmentTree(1, 0, N - 1, b - 1, c);
        }
        else {
            cout << SumSegmentTree(1, 0, N - 1, b - 1, c - 1) << endl;
        }
    }
}

void Init(void) {
    cin >> N >> M >> K;
    arr.resize(N);
    tree.resize(1 << int(ceil(log2(N))) + 1);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}