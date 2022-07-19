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

int n = 8;
int max_num = 5;
vi arr;
int dp_0[1000][2][2];
int dp_1[1000][2][2];

int DP(int idx, int use, int turn) {
    dp_0[0][0][1] = arr[0];
    dp_0[1][1][1] = 2 * (arr[0] + arr[1]);
    dp_1[0][0][0] = 0;
    dp_1[1][0][0] = 0;
    dp_1[1][0][1] = arr[1];

    for (int i = 2; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                dp_0[i][0][j] = dp_0[i - 1][0][1];
                dp_0[i][1][j] = dp_0[i - 1][1][1];
                dp_1[i][0][j] = dp_1[i - 1][0][1];
                dp_1[i][1][j] = dp_1[i - 1][1][1];
            }
            else {
                dp_0[i][0][j] = dp_0[i - 1][0][0] + arr[i];
                dp_0[i][1][j] = max(dp_0[i - 1][1][0], 2 * (dp_0[i - 2][0][0] + arr[i - 1] + arr[i]));
                dp_1[i][0][j] = dp_1[i - 1][0][0] + arr[i];
                dp_1[i][1][j] = max(dp_1[i - 1][1][0], 2 * (dp_1[i - 2][0][0] + arr[i - 1] + arr[i]));
            }
        }
    }
}

void Calc() {
    DP(0, 0, 0);
    cout << "dp_0 : " << endl << dp_0[n - 1] << endl;
    cout << "do_1 : " << endl << dp_1[n - 1] << endl;
}

void BackTrack(int idx, int val) {
    if (idx == n) {
        Calc();
        return;
    }
    for (int i = idx; i < n; i++) {
        for (int j = val; j >= 0; j--) {
            arr[i] = j;
            BackTrack(i + 1, j);
        }
    }
}

void Solve(void) {
    //BackTrack(0, max_num);
    arr = { 3,3,3,2,2,2,2,2 };
    Calc();
}

void Init(void) {
    resize(dp_0, n, 2, 2);
    resize(dp_1, n, 2, 2);
    memset(dp_0, 0xfe, sizeof(dp_0));
    memset(dp_1, 0xfe, sizeof(dp_1));

    // cin >> n;
    arr.resize(n);
    // while(n--) {
    //     cin >> arr[n];
    // }
    // sort(arr.begin(), arr.end(), greater<int>());
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}