#include <bits/stdc++.h>

using namespace std;

// union find 직접구현해보기

vector<vector<int>> party;
vector<int> know;
vector<int> parent;
int answer;
int N, M;
int know_size;

void Init(void);
void Solve(void);
void Union(int src, int dst);
int Find(int node);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Init();
    Solve();

    return 0;
}

void Init(void) {
    cin >> N >> M;
    cin >> know_size;

    party.resize(M);
    parent.resize(N + 1);
    know.resize(know_size);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < know_size; i++) {
        int inp;
        cin >> inp;
        know[i] = inp;
    }

    for (int i = 0; i < M; i++) {
        int inp, root;
        cin >> inp;
        for (int j = 0; j < inp; j++) {
            int tmp;
            cin >> tmp;
            if (j == 0) {
                root = tmp;
            }
            else {
                Union(tmp, root);
            }
            party[i].push_back(tmp);
        }
    }
}

void Solve(void) {
    for (int i = 0; i < M; i++) {
        bool say_lie = true;
        for (int j = 0; j < party[i].size(); j++) {
            if (say_lie == false) {
                break;
            }
            for (int k = 0; k < know.size(); k++) {
                if (Find(party[i][j]) == Find(know[k])) {
                    say_lie = false;
                    break;
                }
            }
        }
        if (say_lie) {
            answer++;
        }
    }

    cout << answer;
    return;
}

void Union(int src, int dst) {
    parent[Find(src)] = Find(dst);
    return;
}

int Find(int node) {
    if (parent[node] == node) {
        return node;
    }
    else {
        return parent[node] = Find(parent[node]);
    }
}