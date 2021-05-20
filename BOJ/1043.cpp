#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> party;
vector<int> know;
vector<int> parent;
int N, M;
int know_size;
int ans;

int Find(int n) {
    if (parent[n] == n) return n;
    else return parent[n] = Find(parent[n]);
}

void Union(int p, int c) {
    parent[Find(c)] = Find(p);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> know_size;

    party.resize(M);
    know.resize(know_size);
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < know_size; i++)
        cin >> know[i];

    for (int i = 0; i < M; i++) {
        int party_size, root;
        cin >> party_size;
        party[i].resize(party_size);
        for (int j = 0; j < party_size; j++) {
            int node;
            cin >> node;
            if (j == 0)
                root = node;
            else
                Union(root, node);
            party[i][j] = node;
        }
    }

    for (int i = 0; i < M; i++) {
        bool can_lie = true;
        for (int j = 0; j < party[i].size() && can_lie; j++) {
            for (int k = 0; k < know.size() && can_lie; k++) {
                if (Find(party[i][j]) == Find(know[k]))
                    can_lie = false;
            }
        }
        if (can_lie)
            ans++;
    }
    cout << ans;
    return 0;
}