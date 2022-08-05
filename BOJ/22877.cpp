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
\*************  2022-07-21 16:34:01  *************/

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

int n, t;
string s;
string ans;

char cur_char;
int cur_num;
char next_char;
int next_num;
int idx = 0;
int i = 0;
bool changed = true;

bool CanExchange(char cur_char, char next_char) {
    return cur_char == 'R' && next_char == 'S' ||
        cur_char == 'S' && next_char == 'P' ||
        cur_char == 'P' && next_char == 'R';
}

void Solve(void) {
    while (true) {
        if (changed) {
            cur_char = s[idx];
            i = idx;
            for (; i < s.size(); i++) {
                if (s[i] == cur_char)
                    cur_num++;
                else
                    break;
            }
            idx = i;

            if (idx == s.size()) {
                while (cur_num--) ans += cur_char;
                break;
            }
        }

        next_num = 0;
        next_char = s[i];
        for (; i < s.size(); i++) {
            if (s[i] == next_char)
                next_num++;
            else
                break;
        }
        idx = i;

        if (CanExchange(cur_char, next_char)) {
            int cnt = max(0, cur_num - t);
            while (cnt--) ans += cur_char;
            while (next_num--) ans += next_char;

            if (idx != s.size() && s[idx] != cur_char) {
                int cnt = min(cur_num, t);
                while (cnt--) ans += cur_char;
                cur_num = 0;
            }
            else {
                cur_num = min(cur_num, t);
            }
            changed = true;
        }
        else {
            while (cur_num--) ans += cur_char;
            cur_char = next_char;
            cur_num = next_num;
            changed = false;
        }

        if (idx == s.size()) {
            while (cur_num--) ans += cur_char;
            break;
        }
    }
    cout << ans << '\n';
}

void Init(void) {
    cin >> n >> t >> s;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}