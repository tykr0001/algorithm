/********* github.com/tykr0001/algorithm *********\
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
*$*                                             *$*
*$*    ||||||||  ||    ||  ||   |||  |||||||    *$*
*$*       ||      ||  ||   || |||    ||    ||   *$*
*$*       ||        ||     |||       |||||||    *$*
*$*       ||        ||     || |||    ||  ||     *$*
*$*       ||        ||     ||   |||  ||   |||   *$*
*$*                                             *$*
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
\*************  2022-07-19 14:07:08  *************/

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
int arr[1000];
ll dp_0[1000][2][2]; // {idx,used_0,used_1}
ll dp_1[1000][2][2]; // {idx,used_0,used_1}
ll odd_sum[1000];
ll even_sum[1000];

int DP(int idx, int use, int turn) {
    dp_0[0][0][0] = arr[0];
    dp_0[1][1][0] = 2 * (arr[0] + arr[1]);
    dp_1[0][0][0] = 0;
    dp_1[1][0][0] = arr[1];
    dp_1[1][1][0] = 0;

    for (int i = 2; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            

            if (j == 0) { // first turn
                dp_0[i][0][j] = dp_0[i - 1][0][0];
                dp_0[i][1][j] = dp_0[i - 1][1][0];
                dp_1[i][0][j] = dp_1[i - 1][0][0];
                dp_1[i][1][j] = dp_1[i - 1][1][0];
            }
            else { // second turn
                dp_0[i][0][j] = dp_0[i - 1][0][0] + arr[i];
                dp_0[i][1][j] = max(dp_0[i - 1][1][0], 2 * (dp_0[i - 2][0][0] + arr[i - 1] + arr[i]));
                dp_1[i][0][j] = dp_1[i - 1][0][0] + arr[i];
                dp_1[i][1][j] = max(dp_1[i - 1][1][0], 2 * (dp_1[i - 2][0][0] + arr[i - 1] + arr[i]));
            }
        }
    }
}

void Solve(void) {

}

void Init(void) {
    cin >> n;
    memset(dp_0, -1, sizeof(dp_0));
    memset(dp_1, -1, sizeof(dp_1));

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i % 2)
            odd_sum[i / 2] += odd_sum[max(i / 2 - 1, 0)] + arr[i];
        else
            even_sum[i / 2] += even_sum[max(i / 2 - 1, 0)] + arr[i];
    }

    sort(arr, arr + n, greater<int>());
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}