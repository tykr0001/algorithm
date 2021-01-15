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
\*************  2021-01-15 13:54:36  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define eb emplace_back
#define v vector
#define s stack
#define q queue
#define pq priority_queue
#define l list
#define p pair
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define Deb(x) cout<<#x<<" = "<<x<<endl;
/*************************************************/

v<l<int>> builds;
v<int> costs;
v<int> cache;
v<int> left_builds;
class Compare {
public:
    bool operator()(const int& lhs, const int& rhs) {
        return cache[lhs] > cache[rhs];
    }
};

int main(void) {
    Boost;
    int N;
    cin >> N;
    builds.resize(N + 1);
    costs.resize(N + 1, 0);
    cache.resize(N + 1, 0);
    left_builds.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        int inp;
        cin >> inp;
        costs[i] = inp;
        while (inp != -1) {
            cin >> inp;
            if (inp == -1) {
                break;
            }
            builds[inp].pb(i);
            left_builds[i]++;
        }
    }

    pq<int, vector<int>, Compare> search_queue;
    for (int i = 1; i <= N; i++) {
        if (left_builds[i] == 0) {
            cache[i] = costs[i];
            search_queue.push(i);
        }
    }
    while (!search_queue.empty()) {
        auto top = search_queue.top();
        search_queue.pop();
        for (auto i : builds[top]) {
            left_builds[i]--;
            if (cache[i] < cache[top] + costs[i]) {
                cache[i] = cache[top] + costs[i];
            }
            if (left_builds[i] == 0) {
                search_queue.push(i);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << cache[i] << endl;
    }
    return 0;
}