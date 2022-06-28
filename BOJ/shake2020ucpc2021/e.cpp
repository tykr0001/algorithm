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
\*************  2022-06-22 11:33:43  *************/

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

int n, t, p;
typedef struct {
    int t;
    int gap;
    int idx;
} user;

vector<user> User;
vb use;
vi use_idx;
int ans = 0;

void Solve(void) {
    for(int i=1; i < User.size(); i++) {
        user a = User[i-1];
        user b = User[i];
        if(!use[p]) ans += b.t-a.t;
        if(b.gap == 0) continue;
        if(b.gap < 0) {
            use[use_idx[b.idx]] = false;
            use_idx[b.idx] = 0;
            continue;
        }
        int min_dist = 0, pos = -1;
        for(int j=1; j<=n; j++) {
            if(!use[j]) {
                int tmp = INT_MAX;
                for(int d=1; j-d >= 1; d++) {
                    if (use[j-d]) {
                        tmp = min(tmp, d);
                        break;
                    }
                }
                for(int d=1; j+d <= n; d++) {
                    if (use[j+d]) {
                        tmp = min(tmp, d);
                        break;
                    }
                }
                if(min_dist < tmp) {
                    min_dist = tmp;
                    pos = j;
                }
            }
        }
        use[pos] = true;
        use_idx[b.idx] = pos;
    }
    cout << ans;
}

void Init(void) {
    cin >> n >> t >> p;
    resize(use,n+1);
    resize(use_idx,t+1);
    for (int i = 1; i <= t; i++) {
        int beg, end;
        cin >> beg >> end;
        beg = beg/100*60 + beg%100;
        end = end/100*60 + end%100;
        if(beg==end) continue;
        User.emplace_back(user{beg,end-beg,i});
        User.emplace_back(user{end,-1,i});
    }
    User.emplace_back(user{9*60,0,0});
    User.emplace_back(user{21*60,0,0});
    sort(User.begin(), User.end(), [ ](auto& a, auto& b) {return a.t == b.t ? a.gap < b.gap : a.t < b.t; });
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}