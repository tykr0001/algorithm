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
\*************  2021-02-17 12:56:29  *************/

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

int N, M;
v<ll> arr;
v<ll> min_tree;
v<ll> max_tree;

ll InitMinSegmentTree(int node, int start, int end) {
    if (start == end) {
        return min_tree[node] = arr[start];
    }
    else {
        return min_tree[node] = min(InitMinSegmentTree(node * 2, start, (start + end) / 2), InitMinSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end));
    }
}


ll InitMaxSegmentTree(int node, int start, int end) {
    if (start == end) {
        return max_tree[node] = arr[start];
    }
    else {
        return max_tree[node] = max(InitMaxSegmentTree(node * 2, start, (start + end) / 2), InitMaxSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end));
    }
}

ll MinSegmentTree(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return INF;
    }
    if (left <= start && end <= right) {
        return min_tree[node];
    }
    return min(MinSegmentTree(node * 2, start, (start + end) / 2, left, right), MinSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

ll MaxSegmentTree(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return max_tree[node];
    }
    return max(MaxSegmentTree(node * 2, start, (start + end) / 2, left, right), MaxSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

void Solve(void) {
    InitMinSegmentTree(1, 0, N - 1);
    InitMaxSegmentTree(1, 0, N - 1);
    while (M--) {
        int a, b;
        cin >> a >> b;
        cout << MinSegmentTree(1, 0, N - 1, a - 1, b - 1) << " "
             << MaxSegmentTree(1, 0, N - 1, a - 1, b - 1) << endl;
    }
}

void Init(void) {
    cin >> N >> M;
    arr.resize(N);
    min_tree.resize(1 << int(ceil(log2(N))) + 1);
    max_tree.resize(1 << int(ceil(log2(N))) + 1);
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