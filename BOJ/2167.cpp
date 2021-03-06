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
\*************  2021-03-15 04:13:34  *************/

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
#define For(i,beg,end) for(int i=beg; i<end; i++)
typedef long long ll;
/*************************************************/

int N, M, K;
int answer;
vvi arr;
vvi tree;
ll Init(int node, int start, int end, vector<int>& arr, vector<int>& tree) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = Init(node * 2, start, (start + end) / 2, arr, tree) + Init(node * 2 + 1, (start + end) / 2 + 1, end, arr, tree);
    }
}

ll Update(int node, int start, int end, int idx, ll k, vector<int>& arr, vector<int>& tree) {
    if (idx < start || idx > end) {
        return tree[node];
    }
    if (start == end) {
        return tree[node] = k;
    }
    else {
        return tree[node] = Update(node * 2, start, (start + end) / 2, idx, k, arr, tree) + tree[node * 2 + 1] + Update(node * 2 + 1, (start + end) / 2 + 1, end, idx, k, arr, tree);
    }
}

ll Sum(int node, int start, int end, int left, int right, vector<int>& arr, vector<int>& tree) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    else {
        return Sum(node * 2, start, (start + end) / 2, left, right, arr, tree) + Sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right, arr, tree);
    }
}

void Solve(void) {
    cin >> K;
    while (K--) {
        int ii, ij, gi, gj;
        cin >> ii >> ij >> gi >> gj;
        answer = 0;
        For(i, ii - 1, gi) {
            answer += Sum(1, 0, M - 1, ij - 1, gj - 1, arr[i], tree[i]);
        }
        cout << answer << endl;
    }
}

void Init(void) {
    cin >> N >> M;
    arr.resize(N, vi(M));
    tree.resize(N, vi(1 << (int(ceil(log2(M))) + 1)));
    For(i, 0, N) {
        For(j, 0, M) {
            cin >> arr[i][j];
        }
        Init(1, 0, M - 1, arr[i], tree[i]);
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}