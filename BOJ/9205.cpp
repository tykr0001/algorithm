#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;
vector<int> cost;
pair<int, int> init;
pair<int, int> conv;
pair<int, int> goal;

class Compare {
public:
    bool operator()(const int& a, const int& b) {
        return cost[a] > cost[b];
    }
};
priority_queue<int, vector<int>, Compare> pq;

bool CanGo(int src, int dst) {
    return abs(v[src].first - v[dst].first) + abs(v[src].second - v[dst].second) <= 1000;
}

bool Dijkstra(void) {
    pq.emplace(0);
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        for (int i = 0; i < n + 2; i++) {
            if (top != i) {
                if (CanGo(top, i)) {
                    if (v[i] == goal) {
                        return true;
                    }
                    if (cost[i] > cost[top] + 1) {
                        pq.emplace(i);
                        cost[i] = cost[top] + 1;
                    }
                }
            }
        }
    }
    return false;
}

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int x, y;

        v.clear();
        cost.clear();
        while (!pq.empty()) {
            pq.pop();
        }
        cin >> n;
        cin >> x >> y;
        init = { x,y };
        cost.resize(n + 2, INT32_MAX);
        cost[0] = 0;
        v.resize(n + 2);
        v[0] = init;

        for (int i = 1; i < n + 1; i++) {
            cin >> x >> y;
            v[i] = { x, y };
        }

        cin >> x >> y;
        goal = { x,y };
        v[n + 1] = goal;
        if (Dijkstra()) {
            cout << "happy" << endl;
        }
        else {
            cout << "sad" << endl;
        }
    }
}