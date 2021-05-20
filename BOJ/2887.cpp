#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

struct Point {
    int idx;
    int x;
    int y;
    int z;
};

struct Edge {
    int src;
    int dst;
    int cost;
};

vector<Point> planets;
vector<Edge> edges;
vector<int> parent;

int Find(int n) {
    if (parent[n] == n) return n;
    else return parent[n] = Find(parent[n]);
}

void Union(int p, int c) {
    parent[Find(c)] = Find(p);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    planets = vector<Point>(N);
    edges = vector<Edge>(3 * (N - 1));
    parent.resize(N);

    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        planets[i] = { i,x,y,z };
        parent[i] = i;
    }

    sort(planets.begin(), planets.end(), [ ](Point& a, Point& b) {return a.x < b.x; });
    for (int i = 0; i < N - 1; i++)
        edges[i] = { planets[i].idx, planets[i + 1].idx, planets[i + 1].x - planets[i].x };

    sort(planets.begin(), planets.end(), [ ](Point& a, Point& b) {return a.y < b.y; });
    for (int i = 0; i < N - 1; i++)
        edges[N - 1 + i] = { planets[i].idx, planets[i + 1].idx, planets[i + 1].y - planets[i].y };

    sort(planets.begin(), planets.end(), [ ](Point& a, Point& b) {return a.z < b.z; });
    for (int i = 0; i < N - 1; i++)
        edges[2 * (N - 1) + i] = { planets[i].idx, planets[i + 1].idx, planets[i + 1].z - planets[i].z };

    sort(edges.begin(), edges.end(), [ ](Edge& a, Edge& b) {return a.cost < b.cost; });

    ll ans = 0;
    for (auto& edge : edges) {
        if (Find(edge.src) != Find(edge.dst)) {
            Union(edge.src, edge.dst);
            ans += edge.cost;
        }
    }
    cout << ans << endl;
    return 0;
}