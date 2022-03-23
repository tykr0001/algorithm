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
\*************  2022-03-22 21:49:04  *************/

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

int n, m, k;
v2i A;
v2i land;
v3i tree;

int di[] = { 0,0,-1,1,-1,-1,1,1 };
int dj[] = { -1,1,0,0,-1,1,-1,1 };

inline bool CanGo(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= n;
}

void Solve(void) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sort(tree[i][j], greater<int>());
        }
    }
    while (k--) {
        // spring
        v2i new_A;
        resize(new_A, n + 2, n + 2);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                vi new_tree;
                for (auto riter = tree[i][j].rbegin(); riter != tree[i][j].rend(); riter++) {
                    int age = *riter;
                    if (age <= land[i][j]) {
                        land[i][j] -= age;
                        new_tree.push_back(age + 1);
                    }
                    else {
                        new_A[i][j] += age / 2;
                    }
                }
                tree[i][j] = vi(new_tree.rbegin(), new_tree.rend());
            }
        }

        // summer
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                land[i][j] += new_A[i][j];
            }
        }

        // fall
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (auto& age : tree[i][j]) {
                    if (age % 5 == 0) {
                        for (int k = 0; k < 8; k++) {
                            int y = i + di[k];
                            int x = j + dj[k];
                            if (CanGo(y, x)) {
                                tree[y][x].push_back(1);
                            }
                        }
                    }
                }
            }
        }

        // winter
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                land[i][j] += A[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += tree[i][j].size();
        }
    }
    cout << ans;
}

void Init(void) {
    cin >> n >> m >> k;
    resize(A, n + 2, n + 2);
    resize(land, n + 2, n + 2);
    resize(tree, n + 2, n + 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
            land[i][j] = 5;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}