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
\*************  2022-06-28 13:53:34  *************/

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
using vd = vector<double>;
using v2d = vector<vd>;

v2d GaussElimination(v2d mat) {
    int size = mat.size();
    v2d ret(size, vd(size));
    for(int i=0; i<size; i++)
        ret[i][i] = 1;

    for(int i=0; i<size; i++) {
        double tmp = mat[i][i];
        for(int j=0; j<size; j++) {
            mat[i][j] /= tmp;
            ret[i][j] /= tmp;
        }

        for(int j=1; j<size; j++) {
            double a = - mat[(i+j)%size][i] / mat[i][i];

            for(int k=0; k<size; k++) {
                mat[(i+j)%size][k] += a * mat[i][k];
                ret[(i+j)%size][k] += a * ret[i][k];
            }
        }
    }

    return ret;
}

void Solve(void) {
    ;
}

void Init(void) {
    v2d arr(3, vd(3));
    arr[0] = {1, 2, 3};
    arr[1] = {2, 5, 3};
    arr[2] = {1, 0, 8};
    cout << arr;
    v2d ret = GaussElimination(arr);
    cout << ret;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}