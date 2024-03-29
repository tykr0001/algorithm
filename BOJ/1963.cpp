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
\*************  2022-03-23 17:27:56  *************/

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

vb prime;

void Eratos() {
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(10000); i++) {
		if (prime[i]) {
			for (int j = i * 2; j < 10000; j += i)
				prime[j] = false;
		}
	}
}

int main(void) {
	Boost;
	queue<int> q;
	prime = vb(10000, true);
	int t; cin >> t;
	Eratos();
	while (t--) {
		int init, goal;
		cin >> init >> goal;
		queue<int> q;
		bool visited[10000] = {};
		int depth[10000] = {};
		q.push(init);
		visited[init] = true;

		int ans = 0;
		bool flag = false;
		while (!q.empty()) {
			int n = q.front();
			q.pop();
			if (n == goal) {
				ans = depth[goal];
				flag = true;
				break;
			}
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 4; j++) {
					int k = n - n / int(pow(10, 3 - j)) % 10 * int(pow(10, 3 - j))
						+ int(pow(10, 3 - j)) * i;
					if (!visited[k] && prime[k] && k >= 1000) {
						q.push(k);
						visited[k] = true;
						depth[k] = depth[n] + 1;
					}
				}
			}
		}
		if (flag) cout << ans << endl;
		else cout << "Impossible" << endl;
	}
	return 0;
}