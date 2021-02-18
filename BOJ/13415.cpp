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
\*************  2021-02-14 15:03:04  *************/

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

int N, K;
vi seq;
v<pii> candidate;
v<pii> op;
int max_len;
int max_idx;
// 0 => ascend, 1 => descend
int order;

bool Compare(pii a, pii b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    else {
        return a.second < b.second;
    }
}

void Solve(void) {
    order = op[0].second % 2;
    if (order) { // descend
        sort(seq.begin(), seq.begin() + op[0].first, greater<int>());
    }
    else { // ascend
        sort(seq.begin(), seq.begin() + op[0].first);
    }

    for (int i = 1; i < op.size(); i++) {
        if (op[i].second % 2 != order) {
            order = op[i].second % 2;
            si tmp;
            for (int i = 0; i < op[i].first; i++) {
                tmp.emplace(seq[i]);
            }
            for (int i = 0; i < op[i].first; i++) {
                seq[i] = tmp.top();
                tmp.pop();
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << seq[i] << " ";
    }
}

void Init(void) {
    cin >> N;
    seq.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }
    cin >> K;
    candidate.resize(2 * K);
    for (int i = 0; i < 2 * K; i++) {
        cin >> candidate[i].first;
        candidate[i].second = i;
    }
    sort(candidate.begin(), candidate.end(), Compare);
    op.emplace_back(candidate[0]);
    for (int i = 1; i < 2 * K; i++) {
        if (op.back().second < candidate[i].second) {
            op.emplace_back(candidate[i]);
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}