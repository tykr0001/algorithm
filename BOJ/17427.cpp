#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
    ll N, answer = 0;
    cin >> N;

    for (ll i = 1; i <= N; ++i) {
        answer += (N / i) * i;
    }
    cout << answer << endl;
    return 0;
}