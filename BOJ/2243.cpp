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
\*************  2021-03-17 05:44:03  *************/

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

int n;
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

int Query(int node, int start, int end, int n) {
    if (start == end) {
        return start;
    }
    if (tree[node * 2] >= n) {
        return Query(node * 2, start, (start + end) / 2, n);
    }
    else {
        return Query(node * 2 + 1, (start + end) / 2 + 1, end, n - tree[node * 2]);
    }
}

void Solve(void) {
    while (n--) {
        int A;
        cin >> A;
        if (A == 1) {
            int B;
            cin >> B;
            int ans = Query(1, 1, 1000001, B);
            cout << ans << endl;
            Update(1, 1, 1000001, ans, -1);
        }
        else {
            int B, C;
            cin >> B >> C;
            arr[B] += C;
            Update(1, 1, 1000001, B, C);
        }
    }
}

void Init(void) {
    cin >> n;
    arr.resize(1000001);
    tree.resize(1 << int(ceil(log2(1000001))) + 1);
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}