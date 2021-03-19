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
\*************  2021-03-17 06:51:24  *************/

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
#define rep(i,beg,end) for(int i=beg; i<end; i++)
typedef long long ll;
/*************************************************/

int n, m;
vector<ll> arr;
vector<ll> tree;

ll Init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = Init(node * 2, start, (start + end) / 2)
                          + Init(node * 2 + 1, (start + end) / 2 + 1, end);
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
        return Sum(node * 2, start, (start + end) / 2, left, right)
             + Sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    }
}

ll Update(int node, int start, int end, int idx, ll diff) {
    if (idx < start || idx > end) {
        return tree[node];
    }
    if (start == end) {
        return tree[node] += diff;
    }
    else {
        return tree[node] = Update(node * 2, start, (start + end) / 2, idx, diff)
                          + Update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
    }
}

void Solve(void) {
    int top = m;
    for (int i = 0; i < m; i++) {
        int idx;
        cin >> idx;
        cout << Sum(1, 1, n + m, 1, arr[idx] - 1) << ' ';
        Update(1, 1, n + m, arr[idx], -1);
        arr[idx] = top--;
        Update(1, 1, n + m, arr[idx], 1);
    }
}

void Init(void) {
    cin >> n >> m;
    arr.clear();
    arr.resize(n + m + 1);
    tree.clear();
    tree.resize(1 << int(ceil(log2(n + m + 1))) + 1);
    for (int i = 1; i <= n; i++) {
        Update(1, 1, n + m, i + m, 1);
        arr[i] = i + m;
    }
}

int main(void) {
    Boost;
    int t; cin >> t;
    while (t--) {
        Init();
        Solve();
        cout << endl;
    }
    return 0;
}