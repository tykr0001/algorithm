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
\*************  2021-01-18 15:23:00  *************/

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
#define INF 2e9
#define LINF 9e18
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int N;
v<pii> poles;
vi lis;
vi idx;
vi answer;
void Solve(void) {
    lis.emplace_back(poles[0].second);
    idx.emplace_back(0);
    for (int i = 1; i < N; i++) {
        if (lis.back() < poles[i].second) {
            lis.emplace_back(poles[i].second);
            idx.emplace_back(lis.size() - 1);
        }
        else {
            auto iter = lower_bound(lis.begin(), lis.end(), poles[i].second);
            *iter = poles[i].second;
            idx.emplace_back(distance(lis.begin(), iter));

        }
    }

    cout << poles.size() - lis.size() << endl;
    for (int i = N - 1, j = lis.size() - 1; i >= 0; i--) {
        if (idx[i] == j) {
            answer.emplace_back(poles[i].first);
            j--;
        }
    }

    sort(answer.begin(), answer.end());
    for (int i = 0, j = 0; i < N; i++) {
        if (poles[i].fi != answer[j]) {
            cout << poles[i].fi << endl;
        }
        else {
            j++;
        }
    }
    return;
}

void Init(void) {
    Boost;
    cin >> N;
    poles.resize(N);
    for (int i = 0; i < N; i++) {
        int src, dst;
        cin >> src >> dst;
        poles[i] = { src, dst };
    }
    sort(poles.begin(), poles.end());
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}