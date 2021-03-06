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
\*************  2021-03-28 05:05:02  *************/

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

int N;
int answer;
vpii meetings;

void Solve(void) {
	auto cmp = [ ](const pii& lhs, const pii& rhs) { return lhs.se != rhs.se ? lhs.se < rhs.se : lhs.fi < rhs.fi; };
	sort(meetings.begin(), meetings.end(), cmp);
	for (int i = 0, cur = 0; i < N; i++) {
		if (cur <= meetings[i].fi) {
			answer++;
			cur = meetings[i].se;
		}
	}
	cout << answer << endl;
}

void Init(void) {
	cin >> N;
	meetings.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> meetings[i].fi >> meetings[i].se;
	}
}

int main(void) {
	Boost;
	Init();
	Solve();
	return 0;
}