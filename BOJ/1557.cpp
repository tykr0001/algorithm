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
\*************  2022-03-31 21:06:03  *************/

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

ll k;
vi mobius(1000001);

// 메르텐스 함수
ll Query(int n) {
    ll ret = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        ret += (mobius[i] * (n / (i * i)));
    }
    return ret;
}

// 지수의 합이 홀수면 -1
// 지수의 합이 짝수면 1
// 제곱수를 인수로 가지면 0
void InitMobius(void) {
    mobius[1] = 1;
    for (int i = 1; i <= 1000000; i++) {
        if (mobius[i] != 0) {
            for (int j = i * 2; j <= 1000000; j += i) {
                mobius[j] -= mobius[i];
            }
        }
    }
    for(int i=1; i<=1000; i++) {
        cout << i << " : " << mobius[i] << endl;
    }
}

void Solve(void) {
    ll lo = 0;
    ll hi = 2e9;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (Query(mid) < k) lo = mid + 1;
        else hi = mid - 1;
    }
    cout << lo;
}

void Init(void) {
    cin >> k;
    InitMobius();
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}