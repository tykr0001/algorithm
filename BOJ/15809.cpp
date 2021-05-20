#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M;
vector<int> A;
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
    cin >> N >> M;

    A.resize(N + 1);
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    while (M--) {
        int O, P, Q;
        cin >> O >> P >> Q;
        // µø∏Õ
        if (O == 1) {
            A[Find(P)] += A[Find(Q)];
            A[Find(Q)] = 0;
        }
        // ¿¸¿Ô
        else {
            A[Find(P)] = abs(A[Find(P)] - A[Find(Q)]);
            A[Find(Q)] = 0;
        }
        Union(P, Q);
    }

    int ans = 0;
    sort(A.begin(), A.end());
    for (int i = 1; i <= N; i++)
        if (A[i]) ans++;
    cout << ans << endl;
    for (int i = N - ans + 1; i <= N; i++)
        cout << A[i] << ' ';
    return 0;
}