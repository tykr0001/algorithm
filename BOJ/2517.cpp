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
\*************  2021-03-18 00:24:01  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define v vector
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define vs vector<string> 
#define vc vector<char> 
#define vl vector<ll> 
#define vvl vector<vector<ll>> 
#define pii pair<int,int>
#define pll pair<ll,ll> 
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
typedef long long ll;
/*************************************************/

int N;
vector<ll> arr;
vector<ll> tree;
vpii runners; // {idx, performance}

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

void Solve(void) {
    rep(i, 0, N) {
        Update(1, 0, N - 1, runners[i].fi, 1);
        cout << Sum(1, 0, N - 1, 0, runners[i].fi) << endl;
    }
}

void Init(void) {
    cin >> N;
    arr.resize(N);
    runners.resize(N);
    rep(i, 0, N) {
        int inp;
        cin >> inp;
        runners[i] = { i,inp };
    }
    sort(runners.begin(), runners.end(), [ & ](const pii& lhs, const pii& rhs) { return lhs.se < rhs.se; });
    tree.resize(1 << int(ceil(log2(N))) + 1);
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}