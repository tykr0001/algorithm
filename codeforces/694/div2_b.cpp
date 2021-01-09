#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long LL;

LL t;
LL n, x;
LL sum;
vector<pair<LL, LL>> a;
LL end_point;

int main(void) {
    cin >> t;
    while (t--) {
        cin >> n >> x;
        sum = 0;
        end_point = 0;
        a.clear();
        a.resize(n);
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            a[i] = { tmp,tmp };
            sum += tmp;
        }

        for (int i = 0; a[i].second % x == 0; i++) {
            a.push_back({ a[i].first, a[i].second / x });
            sum += a[i].first;
        }

        cout << sum << endl;

    }

    return 0;
}