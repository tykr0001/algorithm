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
\*************  2022-03-21 19:03:37  *************/

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
int ans;
vs arr;

int check(int i, int j) {
    int row = 0;
    int col = 0;

    for (int k = j; k >= 0; k--) {
        if (arr[i][j] == arr[i][k]) row++;
        else break;
    }
    for (int k = j; k < n; k++) {
        if (arr[i][j] == arr[i][k]) row++;
        else break;
    }

    for (int k = i; k >= 0; k--) {
        if (arr[i][j] == arr[k][j]) col++;
        else break;
    }
    for (int k = i; k < n; k++) {
        if (arr[i][j] == arr[k][j]) col++;
        else break;
    }

    return max(row, col) - 1;
}

bool IsIn(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

void Solve(void) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (IsIn(i, j + 1)) {
                swap(arr[i][j], arr[i][j + 1]);
                ans = max(ans, check(i, j));
                ans = max(ans, check(i, j + 1));
                swap(arr[i][j], arr[i][j + 1]);
            }
            if (IsIn(i + 1, j)) {
                swap(arr[i][j], arr[i + 1][j]);
                ans = max(ans, check(i, j));
                ans = max(ans, check(i + 1, j));
                swap(arr[i][j], arr[i + 1][j]);
            }
        }
    }
    cout << ans;
}

void Init(void) {
    cin >> n;
    resize(arr, n);
    cin >> arr;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}