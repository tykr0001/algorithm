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
\*************  2021-02-28 15:45:15  *************/

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
v<ll> lazy;
v<ll> tree;

ll InitSegmentTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = InitSegmentTree(node * 2, start, (start + end) / 2) + InitSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end);
    }
}

void UpdateLazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll UpdateRangeSegmentTree(int node, int start, int end, int left, int right, ll diff) {
    UpdateLazy(node, start, end);
    if (left > end || right < start) {
        return tree[node];
    }
    if (left <= start && end <= right) {
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return tree[node] += (end - start + 1) * diff;
    }
    else {
        return tree[node] = UpdateRangeSegmentTree(node * 2, start, (start + end) / 2, left, right, diff) + UpdateRangeSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
    }
}

ll SumSegmentTree(int node, int start, int end, int left, int right) {
    UpdateLazy(node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    else {
        return SumSegmentTree(node * 2, start, (start + end) / 2, left, right) + SumSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    }
}

void Solve(void) {
    InitSegmentTree(1, 0, N - 1);
    M += K;
    while (M--) {
        ll a, b, c, d;
        cin >> a >> b >> c;
        if (a == 1) {
            cin >> d;
            UpdateRangeSegmentTree(1, 0, N - 1, b - 1, c - 1, d);
        }
        else {
            cout << SumSegmentTree(1, 0, N - 1, b - 1, c - 1) << endl;
        }
    }
}

void Init(void) {
    cin >> N >> M >> K;
    arr.resize(N);
    lazy.resize(1 << int(ceil(log2(N))) + 1);
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