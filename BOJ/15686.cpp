#include <bits/stdc++.h>

using namespace std;

int N; // N^2 size
int M; // max chicken
vector<vector<int>> city; // 0:blank, 1:house, 2:chicken
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<bool> is_selected;

// i:index of house
// j:index of chicken
int Distance(int i, int j) {
    return abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
}

int BruteForce(int idx, int depth) {
    int ret;
    if (depth == 0) {
        ret = 0;
        for (int i = 0; i < house.size(); i++) {
            int tmp = INT32_MAX;
            for (int j = 0; j < chicken.size(); j++) {
                if (is_selected[j]) {
                    tmp = min(tmp,Distance(i, j));
                }
            }
            ret += tmp;
        }
    }
    else {
        ret = INT32_MAX;
        for (int i = idx; i < chicken.size(); i++) {
            if (!is_selected[i]) {
                is_selected[i] = true;
                ret = min(ret, BruteForce(i, depth - 1));
                is_selected[i] = false;
            }
        }
    }

    return ret;
}

int main(void) {
    cin >> N >> M;
    city.resize(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) {
                house.emplace_back(i, j);
            }
            else if (city[i][j] == 2) {
                chicken.emplace_back(i, j);
            }
        }
    }
    is_selected.resize(chicken.size(), false);
    cout << BruteForce(0, M) << endl;
}