#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<vector<int>> adj;
vector<pair<int, int>> loc;
vector<pair<int, int>> route;

vector<int> selected_portal;
vector<vector<int>> portal_comb;

vector<pair<int, int>> sync;
vector<bool> selected_sync;
vector<vector<pair<int, int>>> sync_comb;

void FloydWarshall(vector<vector<int>>& graph) {
    for (int k = 1; k <= a; k++) { // 중간
        for (int i = 1; i <= a; i++) { // 시작
            for (int j = 1; j <= a; j++) { // 끝
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

void SyncCombination(vector<int>& portal, int idx, int cnt) {
    if (cnt == m) {
        vector<pair<int, int>> tmp;
        for (int i = 0; i < m; i++) {
            if (selected_sync[i]) tmp.emplace_back(sync[i]);
        }
        sync_comb.emplace_back(tmp);
        return;
    }
    for (int i = idx; i < m; i++) {
        selected_sync[idx] = true;
        SyncCombination(portal, idx + 1, cnt + 1);
        selected_sync[idx] = false;
        SyncCombination(portal, idx + 1, cnt);
    }
}

void PortalCombination(int idx) {
    if (selected_portal.size() == n) {
        // vector<int> tmp;
        // for (int i = 1; i <= a; i++) {
        //     if (selected_portal[i]) tmp.emplace_back(i);
        // }
        portal_comb.emplace_back(selected_portal);
        return;
    }
    else if(idx<=a) {
        selected_portal.emplace_back(idx);
        PortalCombination(idx+1);
        selected_portal.pop_back();
        PortalCombination(idx+1);
    }
    // for (int i = idx; i <= a; i++) {
    //     selected_portal[idx] = true;
    //     PortalCombination(idx + 1, cnt + 1);
    //     selected_portal[idx] = false;
    //     PortalCombination(idx + 1, cnt);
    // }
}

int main(void) {
    // init
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> a >> b;

    adj.resize(a + 1);
    loc.resize(a + 1);

    for (int i = 1; i <= a; i++)
        adj[i].resize(a + 1);

    for (int i = 1; i <= a; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        loc[c].first = x;
        loc[c].second = y;
    }

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= a; j++) {
            adj[i][j] = abs(loc[i].first - loc[j].first) + abs(loc[i].second - loc[j].second);
        }
    }

    for (int i = 0; i < b; i++) {
        int s, d;
        cin >> s >> d;
    }

    // solve
    // selected_portal.resize(a + 1);
    PortalCombination(1);

    for (int i = 0; i < portal_comb.size(); i++) {
        sync.clear();
        sync.reserve(m);
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (portal_comb[i][j] && portal_comb[i][k]) {
                    sync.emplace_back(j, k);
                }
            }
        }
        selected_sync.resize(m);
        SyncCombination(portal_comb[i], 0, 0);
    }

    int ans = 0;
    for (int i = 0; i < sync_comb.size(); i++) {
        int sum = 0;
        vector<vector<int>> cost(adj);
        for (int j = 0; j < m; j++) {
            cost[sync_comb[i][j].first][sync_comb[i][j].second] = 0;
            cost[sync_comb[i][j].second][sync_comb[i][j].first] = 0;
        }
        FloydWarshall(cost);

        for (int j = 0; j < b; j++)
            sum += cost[route[j].first][route[j].second];
        if (ans < sum) {
            ans = sum;
        }
    }

    cout << ans << endl;

    return 0;
}