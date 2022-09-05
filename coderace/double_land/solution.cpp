/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using vb = vector<bool>;
using v2b = vector<vb>;
using vs = vector<string>;
using v2s = vector<vs>;
using vc = vector<char>;
using v2c = vector<vc>;
using vl = vector<ll>;
using v2l = vector<vl>;
using v3l = vector<v2l>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T1, typename T2>
void sort(T1& container, T2 cmp) { sort(container.begin(), container.end(), cmp); }
template<class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (const T& elem : rhs) os << elem << ' '; os << endl; return os; }
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... Size>
void resize(T& container, int _size, Size... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }
/*************************************************/

int n;
int arr[10000];
int odd_sum[10000];
int even_sum[10000];
int dp[10000][2];

void Solve(void) {
    if (n <= 3) {
        cout << (arr[0] + arr[1]) * 2 << endl;
        return;
    }
    for (int i = n - 2; i >= 0; i--) {
        int tmp_A = 0, tmp_B = 0;
        for (int j = i + 2; j < n - 1; j += 2) {
            // if A uses op.2 first
            if (i % 2 == 0) {
                tmp_A = (even_sum[i] + arr[i + 1]) * 2;
                tmp_A += odd_sum[j] - odd_sum[i + 1] + even_sum[n - 1] - even_sum[j];
                tmp_B = (odd_sum[i] + even_sum[j] - even_sum[i] + arr[j + 1]) * 2;
                tmp_B += odd_sum[n - 1] - odd_sum[j + 1];

                if (dp[i][1] <= tmp_B) {
                    dp[i][1] = tmp_B;
                    if (dp[i][0] == 0) dp[i][0] = tmp_A;
                    else dp[i][0] = min(dp[i][0], tmp_A);
                }

                if (dp[i][0] <= dp[i + 1][0]) {
                    dp[i][0] = dp[i + 1][0];
                    if (dp[i][1] == 0) dp[i][1] = dp[i + 1][1];
                    else dp[i][1] = min(dp[i + 1][1], dp[i][1]);
                }
            }
            // if B uses op.2 first
            else {
                tmp_B = (odd_sum[i] + arr[i + 1]) * 2;
                tmp_B += even_sum[j] - even_sum[i + 1] + odd_sum[n - 1] - odd_sum[j];
                tmp_A = (even_sum[i] + odd_sum[j] - odd_sum[i] + arr[j + 1]) * 2;
                tmp_A += even_sum[n - 1] - even_sum[j + 1];

                if (dp[i][0] <= tmp_A) {
                    dp[i][0] = tmp_A;
                    if (dp[i][1] == 0) dp[i][1] = tmp_B;
                    else dp[i][1] = min(dp[i][1], tmp_B);
                }

                if (dp[i][1] <= dp[i + 1][1]) {
                    dp[i][1] = dp[i + 1][1];
                    if (dp[i][0] == 0) dp[i][0] = dp[i + 1][0];
                    else dp[i][0] = min(dp[i + 1][0], dp[i][0]);
                }
            }
        }
    }

    cout << dp[0][0] << endl;
}

void Init(void) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            odd_sum[i] += odd_sum[max(i - 1, 0)] + arr[i];
            odd_sum[min(i + 1, n - 1)] = odd_sum[i];
        }
        else {
            even_sum[i] += even_sum[max(i - 1, 0)] + arr[i];
            even_sum[min(i + 1, n - 1)] = even_sum[i];
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}