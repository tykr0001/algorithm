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
\*************  2021-01-18 20:56:38  *************/

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
#define pdd pair<double,double>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2e9
#define LINF 9e18
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int N;
double answer;
vi parent;
v<pdd> stars; // {x_pos, y_pos}
v<tuple<double, int, int>> kruskal; // {dist, src, dst}

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

double Dist(const pdd& a, const pdd& b){
    return sqrt(pow(a.fi-b.fi,2) + pow(a.se-b.se,2));
}

void Solve(void) {
    for(auto i : kruskal){
        if(Find(get<1>(i)) != Find(get<2>(i))){
            Union(get<1>(i), get<2>(i));
            answer += get<0>(i);
        }
    }
    cout << answer << endl;
    return;
}

void Init(void) {
    Boost;
    cin >> N;
    stars.resize(N);
    parent.resize(N);
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        stars[i] = { x,y };
        parent[i] = i;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            kruskal.emplace_back(Dist(stars[i], stars[j]),i,j);
        }
    }
    sort(kruskal.begin(), kruskal.end());
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}