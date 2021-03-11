#include<bits/stdc++.h>
#define M 1000000007

using namespace std;

typedef long long int LL;

vector<double> a;
vector<double> a_parital_sum;
vector<double> c;
vector<vector<double>> edge;
vector<vector<double>> expected;

// Exponential
// return a^x (mod M)
LL Exp(LL a, LL x) {
    if (x == 0) {
        return 1;
    }
    LL tmp = Exp(a, x / 2);
    if (x % 2) {
        return tmp * tmp % M * a % M;
    }
    else {
        return tmp * tmp % M;
    }
}

int main(void) {
    int N, Q;
    cin >> N >> Q;

    a.resize(N);
    a_parital_sum.resize(N, 0);
    for (int i = 1; i < N; i++) {
        int inp;
        cin >> inp;
        a[i] = inp;
        a_parital_sum[i] = a_parital_sum[i - 1] + a[i];
    }

    c.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        int inp;
        cin >> inp;
        c[i] = inp;
    }
    edge.resize(N + 1, vector<double>(N + 1, 0));
    expected.resize(N + 1, vector<double>(N + 1, 0));

    for (int j = 1; j <= N - 1; j++) {
        for (int i = i + 1; i <= N; i++) { // i가 j로 연결될 때 가중치 * 확률
            expected[j][i] = expected[i][j] = (c[i] + c[j]) * (a[i] / a_parital_sum[j - 1]);
        }
    }
    for (int j = 1; j <= N - 1; j++) {
        for (int i = j + 1; i <= N; i++) { //i에서 j로 가는 기댓값
            for (int k = 1; k <= N; i++) {
                if (k != i && k != j) {
                    expected[j][i] = expected[i][j] += ((c[i] + c[k]) + expected[k][j]) * (a[k] / a_parital_sum[j - 1]);
                }
            }
        }
    }


    while (Q--) {
        int u, v;
        cin >> u >> v;

    }
}