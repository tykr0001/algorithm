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
\*************  2021-03-31 13:01:36  *************/

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
template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T, class U>
void sort(T& container, U cmp) { sort(container.begin(), container.end(), cmp); }
/*************************************************/

string inp;
stack<char> bracket;
stack<ll> value;
ll answer;

void Solve(void) {
    rep(i, 0, inp.size()) {
        if (inp[i] == '(' || inp[i] == '[') {
            bracket.emplace(inp[i]);
        }
        else if (inp[i] == ')') {
            if (bracket.empty() || bracket.top() == '[') {
                cout << 0 << endl;
                return;
            }
            else if (bracket.top() == '(') {
                value.emplace(2);
                bracket.pop();
                bracket.emplace('|');
            }
            else if (bracket.top() == '|') {
                ll tmp = 0;
                while (!bracket.empty() && bracket.top() == '|') {
                    tmp += value.top();
                    value.pop();
                    bracket.pop();
                }
                if (bracket.empty() || bracket.top() == '[') {
                    cout << 0 << endl;
                    return;
                }
                else {
                    bracket.pop();
                    bracket.emplace('|');
                    value.emplace(tmp * 2);
                }
            }

        }
        else if (inp[i] == ']') {
            if (bracket.empty() || bracket.top() == '(') {
                cout << 0 << endl;
                return;
            }
            else if (bracket.top() == '[') {
                value.emplace(3);
                bracket.pop();
                bracket.emplace('|');
            }
            else if (bracket.top() == '|') {
                ll tmp = 0;
                while (!bracket.empty() && bracket.top() == '|') {
                    tmp += value.top();
                    value.pop();
                    bracket.pop();
                }
                if (bracket.empty() || bracket.top() == '(') {
                    cout << 0 << endl;
                    return;
                }
                else {
                    bracket.pop();
                    bracket.emplace('|');
                    value.emplace(tmp * 3);
                }
            }
        }
    }
    while (!bracket.empty()) {
        if (bracket.top() == '|') {
            answer += value.top();
            value.pop();
            bracket.pop();
        }
        else {
            cout << 0 << endl;
            return;
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> inp;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}