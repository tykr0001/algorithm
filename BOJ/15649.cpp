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
\*************  2021-01-15 22:04:52  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define eb emplace_back
#define v vector 
#define s stack
#define q queue 
#define l list 
#define p pair
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
/*************************************************/

int N, M;
vector<bool> selected;
vector<int> cache;

void Permutation(int idx, int depth) {
    if (depth == M) {
        for (auto i : cache) {
            cout << i << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= N; i++) {
        if (!selected[i]) {
            cache.push_back(i);
            selected[i] = true;
            Permutation(i, depth + 1);
            cache.pop_back();
            selected[i] = false;
        }
    }
}

void Solve(void) {
    Permutation(0, 0);
    return;
}

void Init(void) {
    Boost;
    cin >> N >> M;
    selected.resize(N + 1, false);
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}