#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int G;
vector<int> answer;

void Solve() {
    int lo = 1;
    int hi = 1;
    while (lo <= (G - 1) / 2 && hi <= (G - 1) / 2 + 1) {
        if (hi * hi - lo * lo == G) {
            answer.push_back(hi);
            hi++;
            lo++;
        }
        else if (hi * hi - lo * lo < G)
            hi++;
        else
            lo++;
    }
    if (!answer.empty())
        for (auto& num : answer)
            cout << num << endl;
    else
        cout << -1;
}

void Init() {
    cin >> G;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Init();
    Solve();
    return 0;
}