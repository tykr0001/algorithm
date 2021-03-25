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
\*************  2021-03-25 14:11:09  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vc = vector<char>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pair<int, int>>;
using vvpii = vector<vector<pair<int, int>>>;
using vpll = vector<pair<ll, ll>>;
using vvpll = vector<vector<pair<ll, ll>>>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
/*************************************************/

vs color(3);
map<string, ll> val;
map<string, ll> mul;

void Solve(void) {
    cout << (val[color[0]] * 10 + val[color[1]]) * mul[color[2]];
}

void Init(void) {
    val["black"] = 0;
    val["brown"] = 1;
    val["red"] = 2;
    val["orange"] = 3;
    val["yellow"] = 4;
    val["green"] = 5;
    val["blue"] = 6;
    val["violet"] = 7;
    val["grey"] = 8;
    val["white"] = 9;

    mul["black"] = 1e0;
    mul["brown"] = 1e1;
    mul["red"] = 1e2;
    mul["orange"] = 1e3;
    mul["yellow"] = 1e4;
    mul["green"] = 1e5;
    mul["blue"] = 1e6;
    mul["violet"] = 1e7;
    mul["grey"] = 1e8;
    mul["white"] = 1e9;

    cin >> color[0] >> color[1] >> color[2];
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}