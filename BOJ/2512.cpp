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
\*************  2021-03-30 12:15:53  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vc = vector<char>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pair<int, int>>;
using vvpii = vector<vector<pair<int, int>>>;
using vpll = vector<pair<ll, ll>>;
using vvpll = vector<vector<pair<ll, ll>>>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
/*************************************************/

int N;
int sum;
int answer;
vi budget;
vi prefix_sum;

void Solve(void) {
    if (prefix_sum[N] <= sum) {
        cout << budget[N - 1];
        return;
    }
    int lo = 0;
    int hi = budget[N - 1];
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int idx = lower_bound(budget.begin(), budget.end(), mid) - budget.begin();
        int tmp = prefix_sum[idx] + mid * (N - idx);
        if (tmp > sum) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
            answer = max(answer, mid);
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
    budget.resize(N);
    prefix_sum.resize(N + 1);
    rep(i, 0, N) {
        cin >> budget[i];
    }
    cin >> sum;
    sort(budget.begin(), budget.end());
    rep(i, 1, N + 1) {
        prefix_sum[i] = prefix_sum[i - 1] + budget[i - 1];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}