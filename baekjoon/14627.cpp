#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

typedef long long LL;

LL S, C;
vector<LL> v;
LL length;
LL sum;

// 입력 O(S)
// 선형탐색 O(S)
// 이분탐색 O(logL)
// O(S*logL)

LL binary_search(LL low, LL high) {
    LL ret;
    while (low <= high) {
        LL mid = (low + high) / 2;
        LL cnt = 0;
        for (LL i = 0; i < S; i++) {
            cnt += v[i] / mid;
        }
        if (cnt < C) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
            ret = mid;
        }
    }
    return ret;
}

int main(void) {
    cin >> S >> C;
    v.resize(S);
    for (LL i = 0; i < S; i++) {
        cin >> v[i];
        sum += v[i];
    }

    length = binary_search(1, 1e9);
    cout << sum - length * C << endl;
    
    return 0;
}