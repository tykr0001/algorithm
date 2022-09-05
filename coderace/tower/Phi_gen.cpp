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
\*************  2022-08-30 12:46:22  *************/

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

vector<bool> is_prime;
vector<ull> prime;
void Eratos(int m) {
    is_prime = vector<bool>(1000001, true);
    for (int i = 2; i * i < is_prime.size(); i++) {
        if (is_prime[i]) {
            prime.emplace_back(i);
            for (int j = i * 2; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }
}

ll depth = 0;

ull Phi(ll a) {
    ull ret = a;
    ull i = 0;
    while (i < prime.size() && prime[i] * prime[i] <= a) {
        if (!(a % prime[i])) ret = ret / prime[i] * (prime[i] - 1);
        while (!(a % prime[i])) a /= prime[i];
        i++;
    }
    if (a > 1) ret = ret / a * (a - 1);

    return ret;
}

void Solve(void) {
    ll max_depth = 0;
    ll max_phi = 0;
    for(int i=2; i<=1e9; i++) {
        depth = 0;
        ll phi = i;
        while(phi>1) {
            phi = Phi(phi);
            max_phi = max(max_phi, phi);
            depth++;
        }
        max_depth = max(max_depth, depth);
        cout << i << ' ' << max_depth << max_phi << endl;
    }
    cout << max_depth << endl; 
}

void Init(void) {
    ;
}

int main(void) {
    Boost;
    Eratos(1000000);
    Init();
    Solve();
    return 0;
}
