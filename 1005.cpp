#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <functional>

using namespace std;

vector<list<int>> tech;
vector<bool> is_built;
vector<int> cost;
vector<int> D;

class CanBuild {
public:
    bool operator()(int b1, int b2) {
        if (tech[b1].empty()) {
            return false;
        }
        auto iter = tech[b1].begin();
        while (iter != tech[b1].end()) {
            if (!is_built[*iter])
                return true;
            iter++;
        }
        return false;
    }
};

priority_queue<int, vector<int>, CanBuild> build_queue;

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int N, K, goal;
        cin >> N >> K;

        is_built.resize(N + 1, false);
        cost.resize(N + 1, 0);
        D.resize(N + 1, 0);
        tech.resize(N + 1, list<int>());

        for (int i = 1; i <= N; ++i) {
            cin >> D[i];
            cost[i] = D[i];
        }

        while (K--) {
            int b1, b2;
            cin >> b1 >> b2;
            tech[b1].push_back(b2);
        }

        for (int i = 1; i <= N; ++i) {
            build_queue.push(i);
        }

        while (!build_queue.empty()) {
            int building = build_queue.top();
            build_queue.pop();
            if (!tech[building].empty()) {
                auto iter = tech[building].begin();
                while (iter != tech[building].end()) {
                    if (cost[*iter] < cost[building] + D[*iter]) {
                        cost[*iter] = cost[building] + D[*iter];
                        build_queue.push(*iter);
                    }
                    iter++;
                }
            }
        }

        cin >> goal;
        cout << cost[goal] << endl;

        tech.clear();
        is_built.clear();
        cost.clear();
        D.clear();
    }
}