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
\*************  2021-02-17 13:08:13  *************/

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

int n;
v<ll> arr;
v<ll> tree;

void InitSegmentTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
    }
    else {
        InitSegmentTree(node * 2, start, (start + end) / 2);
        InitSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end);
        if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]]) {
            tree[node] = tree[node * 2];
        }
        else {
            tree[node] = tree[node * 2 + 1];
        }
    }
}

ll MinSegmentTree(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return -1;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    ll m1 = MinSegmentTree(node * 2, start, (start + end) / 2, left, right);
    ll m2 = MinSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    if (m1 == -1) {
        return m2;
    }
    if (m2 == -1) {
        return m1;
    }
    if (arr[m1] <= arr[m2]) {
        return m1;
    }
    else {
        return m2;
    }
}

ll largest(int start, int end) {
    ll m = MinSegmentTree(1, 0, n - 1, start, end);
    ll area = ll(end - start + 1) * ll(arr[m]);
    if (start <= m - 1) {
        ll tmp = largest(start, m - 1);
        area = max(area, tmp);
    }
    if (m + 1 <= end) {
        ll tmp = largest(m + 1, end);
        area = max(area, tmp);
    }
    return area;
}

void Solve(void) {
    InitSegmentTree(1, 0, n - 1);
    cout << largest(0, n - 1) << endl;
}

void Init(void) {
    cin >> n;
    arr.clear();
    arr.resize(n);
    tree.clear();
    tree.resize(1 << int(ceil(log2(n))) + 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}