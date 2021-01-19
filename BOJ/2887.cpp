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
\*************  2021-01-18 19:09:18  *************/

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
v<tuple<int, int, int, int>> planets; // {idx, x, y, z}
v<tuple<int, int, int>> kruskal; // {src, dst, dist}
vi parent;
ll answer;

int Find(int node) {
    if (parent[node] == node) {
        return node;
    }
    else {
        return parent[node] = Find(parent[node]);
    }
}

void Union(int a, int b) {
    parent[Find(a)] = Find(b);
}

bool CompX(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
    return get<1>(a) < get<1>(b);
}

bool CompY(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
    return get<2>(a) < get<2>(b);
}

bool CompZ(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
    return get<3>(a) < get<3>(b);
}

bool CompW(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return get<2>(a) < get<2>(b);
}

void Solve(void) {
    for (auto i : kruskal) {
        if (Find(get<0>(i)) != Find(get<1>(i))) {
            Union(get<0>(i), get<1>(i));
            answer += get<2>(i);
        }
    }
    cout << answer << endl;
    return;
}

void Init(void) {
    Boost;
    cin >> N;
    planets.resize(N);
    kruskal.resize(3 * N);
    parent.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        planets[i] = { i,x,y,z };
        parent[i] = i;
    }
    sort(planets.begin(), planets.end(), CompX);
    for (int i = 0; i < N - 1; i++) {
        kruskal[i] = { get<0>(planets[i]), get<0>(planets[i + 1]), abs(get<1>(planets[i]) - get<1>(planets[i + 1])) };
    }
    sort(planets.begin(), planets.end(), CompY);
    for (int i = 0; i < N - 1; i++) {
        kruskal[N + i] = { get<0>(planets[i]), get<0>(planets[i + 1]), abs(get<2>(planets[i]) - get<2>(planets[i + 1])) };
    }
    sort(planets.begin(), planets.end(), CompZ);
    for (int i = 0; i < N - 1; i++) {
        kruskal[2 * N + i] = { get<0>(planets[i]), get<0>(planets[i + 1]), abs(get<3>(planets[i]) - get<3>(planets[i + 1])) };
    }
    sort(kruskal.begin(), kruskal.end(), CompW);

    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}