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
\*************  2022-03-25 19:05:54  *************/

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
vs op;
v2c UP;
v2c DOWN;
v2c LEFT;
v2c RIGHT;
v2c FRONT;
v2c BACK;

void cw(v2c& arr) {
    v2c temp(3, vc(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[j][2 - i] = arr[i][j];
        }
    }
    arr = temp;
}

void ccw(v2c& arr) {
    cw(arr); cw(arr); cw(arr);
}

void fill(v2c& arr, char c) {
    resize(arr, 3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = c;
        }
    }
}

void Solve(void) {
    for (int i = 0; i < n; i++) {
        if (op[i][0] == 'U') {
            int loop = op[i][1] == '+' ? 1 : 3;
            for (int j = 0; j < loop; j++) {
                cw(UP);
                vc temp = FRONT[0];
                FRONT[0] = RIGHT[0];
                RIGHT[0] = BACK[0];
                BACK[0] = LEFT[0];
                LEFT[0] = temp;
            }
        }
        if (op[i][0] == 'D') {
            int loop = op[i][1] == '+' ? 1 : 3;
            for (int j = 0; j < loop; j++) {
                cw(DOWN);
                vc temp = FRONT[2];
                FRONT[2] = LEFT[2];
                LEFT[2] = BACK[2];
                BACK[2] = RIGHT[2];
                RIGHT[2] = temp;
            }
        }
        if (op[i][0] == 'L') {
            int loop = op[i][1] == '+' ? 1 : 3;
            for (int j = 0; j < loop; j++) {
                cw(LEFT);
                vc temp = { FRONT[0][0], FRONT[1][0], FRONT[2][0] };
                FRONT[0][0] = UP[0][0];
                FRONT[1][0] = UP[1][0];
                FRONT[2][0] = UP[2][0];

                UP[0][0] = BACK[2][2];
                UP[1][0] = BACK[1][2];
                UP[2][0] = BACK[0][2];

                BACK[2][2] = DOWN[0][0];
                BACK[1][2] = DOWN[1][0];
                BACK[0][2] = DOWN[2][0];

                DOWN[0][0] = temp[0];
                DOWN[1][0] = temp[1];
                DOWN[2][0] = temp[2];
            }
        }
        if (op[i][0] == 'R') {
            int loop = op[i][1] == '+' ? 1 : 3;
            for (int j = 0; j < loop; j++) {
                cw(RIGHT);
                vc temp = { FRONT[0][2], FRONT[1][2], FRONT[2][2] };
                FRONT[0][2] = DOWN[0][2];
                FRONT[1][2] = DOWN[1][2];
                FRONT[2][2] = DOWN[2][2];

                DOWN[0][2] = BACK[2][0];
                DOWN[1][2] = BACK[1][0];
                DOWN[2][2] = BACK[0][0];

                BACK[2][0] = UP[0][2];
                BACK[1][0] = UP[1][2];
                BACK[0][0] = UP[2][2];

                UP[0][2] = temp[0];
                UP[1][2] = temp[1];
                UP[2][2] = temp[2];
            }
        }
        if (op[i][0] == 'F') {
            int loop = op[i][1] == '+' ? 1 : 3;
            for (int j = 0; j < loop; j++) {
                cw(FRONT);
                vc temp = UP[2];
                UP[2][0] = LEFT[2][2];
                UP[2][1] = LEFT[1][2];
                UP[2][2] = LEFT[0][2];

                LEFT[2][2] = DOWN[0][2];
                LEFT[1][2] = DOWN[0][1];
                LEFT[0][2] = DOWN[0][0];

                DOWN[0][2] = RIGHT[0][0];
                DOWN[0][1] = RIGHT[1][0];
                DOWN[0][0] = RIGHT[2][0];

                RIGHT[0][0] = temp[0];
                RIGHT[1][0] = temp[1];
                RIGHT[2][0] = temp[2];
            }
        }
        if (op[i][0] == 'B') {
            int loop = op[i][1] == '+' ? 1 : 3;
            for (int j = 0; j < loop; j++) {
                cw(BACK);
                vc temp = UP[0];
                UP[0][0] = RIGHT[0][2];
                UP[0][1] = RIGHT[1][2];
                UP[0][2] = RIGHT[2][2];

                RIGHT[0][2] = DOWN[2][2];
                RIGHT[1][2] = DOWN[2][1];
                RIGHT[2][2] = DOWN[2][0];

                DOWN[2][2] = LEFT[2][0];
                DOWN[2][1] = LEFT[1][0];
                DOWN[2][0] = LEFT[0][0];

                LEFT[2][0] = temp[0];
                LEFT[1][0] = temp[1];
                LEFT[0][0] = temp[2];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << UP[i][j];
        }
        cout << endl;
    }
}

void Init(void) {
    cin >> n;
    op.clear();
    op.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> op[i];
    }
    fill(UP, 'w');
    fill(DOWN, 'y');
    fill(LEFT, 'g');
    fill(RIGHT, 'b');
    fill(FRONT, 'r');
    fill(BACK, 'o');
}

int main(void) {
    Boost;
    int t; cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}