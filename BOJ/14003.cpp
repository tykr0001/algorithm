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
\*************  2021-01-15 22:56:51  *************/

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

int N;
vi arr;
vi lis;
vi idx;
vi answer;

void Solve(void) {
    lis.emplace_back(arr[0]);
    idx.emplace_back(0);
    for (int i = 1; i < N; i++) {
        if (lis.back() < arr[i]) {
            lis.emplace_back(arr[i]);
            idx.emplace_back(lis.size() - 1);
        }
        else {
            auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
            *iter = arr[i];
            idx.emplace_back(distance(lis.begin(), iter));

        }
    }

    for (int i = N - 1, j = lis.size() - 1; i >= 0; i--) {
        if (idx[i] == j) {
            answer.emplace_back(arr[i]);
            j--;
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}

void Init(void) {
    Boost;
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main(void) {
    Init();
    Solve();
    return 0;
}