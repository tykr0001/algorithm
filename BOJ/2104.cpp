#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int N;
vector<ll> A;
vector<ll> prefix_sum;

/**
 *  @brief  returns max score which is the maximum value of (A[i]+ ... +A[j]) * min({A[i], ..., A[j]})
 *          when (start <= i <= j <= end) by divide and conquer
 *  @param  start  left most index of subarray
 *  @param  end  right most index of subarray
 *  @return  max score that can exist within range [start, end]
 */
ll MaxScore(int start, int end) {
    if (start == end) return A[start] * A[start];

    int mid = (start + end) / 2;
    ll left = MaxScore(start, mid);
    ll right = MaxScore(mid + 1, end);

    int lo = mid;       // left most index of subarray
    int hi = mid + 1;   // right most index of subarray
    ll min_val = min(A[lo], A[hi]);

    // middle is the max score in the range inclusive of mid, mid + 1
    ll middle = (A[lo] + A[hi]) * min_val;

    // calculate max middle score with greedy algorithm using 2-pointer
    while (!(lo == start && hi == end)) {
        // search left when low is not left most and
        // high is right most or next low left value is bigger than next right value
        if (lo != start && (hi == end || A[lo - 1] > A[hi + 1])) {
            lo--;
            min_val = min(min_val, A[lo]);
        }
        else { // else search right
            hi++;
            min_val = min(min_val, A[hi]);
        }
        middle = max(middle, (prefix_sum[hi] - prefix_sum[lo - 1]) * min_val);
    }

    return max({ left, right, middle });
}

void Solve() {
    cout << MaxScore(1, N);
}

void Init() {
    cin >> N;
    A.resize(N + 1);
    prefix_sum.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
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