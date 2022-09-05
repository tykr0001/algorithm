#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
using vi = vector<int>;

int n, k;
int t[101];
vector<pii> arr;

void Solve() {
    int ans = INT_MAX;
    for (int cnt = 1; cnt <= k; cnt++) {
        if (cnt == 1) {
            int tmp = 0;
            for (int i = 0; i < arr.size(); i++) {
                tmp = max(tmp,
                    30 + (arr[i].first - arr[0].first) * arr[i].second);
            }
            ans = min(ans, tmp);
        }
        else if (cnt == 2 && n >= cnt) {
            int tmp = INT_MAX;
            // j == boundary
            for (int j = 1; j < arr.size(); j++) {
                // k == idx of upper bound
                for (int k = j; k < arr.size(); k++) {
                    int a_tmp = 30;
                    int b_tmp = 30;
                    int upper =
                        30 + (arr[k].first - arr[j].first) * arr[k].second;
                    b_tmp = upper;
                    for (int i = j; i < arr.size(); i++) {
                        int val_a =
                            30 + (arr[i].first - arr[0].first) * arr[i].second;
                        int val_b =
                            30 + (arr[i].first - arr[j].first) * arr[i].second;

                        if (val_b > upper) a_tmp = max(a_tmp, val_a);
                    }
                    for (int i = 0; i < j; i++) {
                        int val_a =
                            30 + (arr[i].first - arr[0].first) * arr[i].second;

                        a_tmp = max(a_tmp, val_a);
                    }
                    tmp = min(tmp, a_tmp + b_tmp);
                }
            }
            ans = min(ans, tmp);
        }
        else if (cnt == 3 && n >= cnt) {
            int tmp = INT_MAX;
            // j == boundary_1
            for (int j = 1; j < arr.size(); j++) {
                // k == boundary_2
                for (int k = j; k < arr.size(); k++) {
                    // l == idx of upper_bound 2
                    for (int l = k; l < arr.size(); l++) {
                        int a_tmp = 30;
                        int b_tmp = 30;
                        int c_tmp = 30;
                        int upper2 =
                            30 + (arr[l].first - arr[k].first) * arr[l].second;
                        c_tmp = upper2;
                        vector<int> flag;
                        for (int i = j; i < k; i++)
                            flag.emplace_back(i);

                        // c
                        for (int i = k; i < arr.size(); i++) {
                            int val_c = 30 + (arr[i].first - arr[k].first) *
                                arr[i].second;

                            if (val_c > upper2)
                                flag.emplace_back(i);
                        }

                        // m == idx of upper bound 1
                        for (int idx = 0; idx < flag.size(); idx++) {
                            int m = flag[idx];
                            int upper1 = 30 + (arr[m].first - arr[j].first) *
                                arr[m].second;
                            b_tmp = upper1;

                            for (int i = 0; i < flag.size(); i++) {
                                int ii = flag[i];
                                if (ii >= j) {
                                    int val_a = 30 + (arr[ii].first - arr[0].first) *
                                        arr[ii].second;
                                    int val_b = 30 + (arr[ii].first - arr[j].first) *
                                        arr[ii].second;

                                    if (val_b > upper1) a_tmp = max(a_tmp, val_a);
                                }
                                else {
                                    int val_a = 30 + (arr[ii].first - arr[0].first) *
                                        arr[ii].second;

                                    a_tmp = max(a_tmp, val_a);
                                }
                                tmp = min(tmp, a_tmp + b_tmp + c_tmp);
                            }
                        }
                    }
                }
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}

void Init() {
    cin >> n >> k;
    for (int i = 40; i < 101; i++) {
        t[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        t[a] = max(t[a], b);
    }
    for (int i = 40; i < 101; i++) {
        if (t[i] != -1) arr.emplace_back(i, t[i]);
    }

    sort(arr.begin(), arr.end());
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Init();
    Solve();
    return 0;
}