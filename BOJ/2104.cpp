#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int N;
vector<ll> A;

// @brief       : calculate max score that can exist within range [start, end] by divide and conquer
// @param start : left most index of subarray
// @param end   : right most index of subarray
// @return      : max score
ll CalcMaxScore(int start, int end) {
    // basis
    if (start == end)
        return A[start] * A[start];

    int mid = (start + end) / 2;
    int lo  = mid;
    int hi  = mid + 1;

    ll  left = CalcMaxScore(start, mid);
    ll right = CalcMaxScore(mid + 1, end);

    // middle      : score in the range inclusive of mid, mid + 1
    // partial_sum : sum of range [lo, hi]
    // min_val     : minimum value of range [lo, hi]
    ll partial_sum = A[lo] + A[hi];
    ll min_val     = min(A[lo], A[hi]);
    ll middle      = partial_sum * min_val;
    
    // calculate max middle score with greedy algorithm using 2-pointer
    while (start < lo || hi < end) {
        // search left
        // when low is not left most and
        // high is right most or next low left value is bigger than next right value
        if (start != lo && (end == hi || A[lo - 1] > A[hi + 1])) {
            lo--;
            partial_sum += A[lo];
            min_val = min(min_val, A[lo]);
        }
        // search right
        else {
            hi++;
            partial_sum += A[hi];
            min_val = min(min_val, A[hi]);
        }
        middle = max(middle, partial_sum * min_val);
    }

    return max({ left, right, middle });
}

void Solve() {
    cout << CalcMaxScore(1, N);
}

void Init() {
    cin >> N;
    A.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
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