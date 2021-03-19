#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

int N, M;
ll answer;
vector<vector<ll>> prefix_sum;

ll PartialSum(int beg_i, int beg_j, int end_i, int end_j) {
    ll ret = prefix_sum[end_i][end_j];
    if (beg_i != 0)
        ret -= prefix_sum[beg_i][end_j];
    if (beg_j != 0)
        ret -= prefix_sum[end_i][beg_j];
    if (beg_i != 0 && beg_j != 0)
        ret += prefix_sum[beg_i][beg_j];
    return ret;
}

void Solve() {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            ll a = PartialSum(0, 0, i, j);
            ll b = PartialSum(0, j, i, M);
            ll c = PartialSum(i, 0, N, j);
            ll d = PartialSum(i, j, N, M);
            answer = max(answer, (min(a, d) + min(b, c)) * max(a, d) * max(b, c));
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; i + j < N; j++) {
            ll a = PartialSum(0, 0, i, M);
            ll b = PartialSum(i, 0, i + j, M);
            ll c = PartialSum(i + j, 0, N, M);
            answer = max(answer, a * b * c);
        }
    }
    for (int i = 1; i < M; i++) {
        for (int j = 1; i + j < M; j++) {
            ll a = PartialSum(0, 0, N, i);
            ll b = PartialSum(0, i, N, i + j);
            ll c = PartialSum(0, i + j, N, M);
            answer = max(answer, a * b * c);
        }
    }
    cout << answer;
}

void Init() {
    cin >> N >> M;
    prefix_sum.resize(N + 1, vector<ll>(M + 1));
    for (int i = 0; i < N; i++) {
        string inp;
        cin >> inp;
        ll column_sum = 0;
        for (int j = 0; j < M; j++) {
            column_sum += inp[j] - '0';
            prefix_sum[i + 1][j + 1] = prefix_sum[i][j + 1] + column_sum;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Init();
    Solve();
    return 0;
}