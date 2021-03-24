#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;

int N, C;
int min_len;
int max_len;
int answer;
vector<int> x;

void BinarySearch(int lo, int hi) {
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        auto it = x.begin();
        for (int i = 0; i < C - 1 && it != x.end(); i++) {
            it = lower_bound(x.begin(), x.end(), *it + mid);
        }
        if (it != x.end()) {
            answer = max(answer, mid);
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
}

void Solve() {
    sort(x.begin(), x.end());
    min_len = 1;
    max_len = x[N - 1] - x[0];
    BinarySearch(min_len, max_len);
    cout << answer;
}

void Init() {
    cin >> N >> C;
    x.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
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