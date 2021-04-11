#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

vector<ll> cubes;
int n;
ll l, w, h;
ll prev_num;
ll answer;

void Solve() {
    for (int i = n - 1; i >= 0; i--) {
        prev_num *= 8;
        ll left_num = (l >> i) * (w >> i) * (h >> i) - prev_num;
        ll cube_num = min(left_num, cubes[i]);
        answer += cube_num;
        prev_num += cube_num;
    }

    if (prev_num == l * w * h)
        cout << answer;
    else
        cout << -1;
}

void Init() {
    cin >> l >> w >> h >> n;
    cubes.resize(n);
    for (int i = 0; i < n; i++) {
        int idx, num;
        cin >> idx >> num;
        cubes[idx] = num;
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