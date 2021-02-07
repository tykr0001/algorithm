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
\*************  2021-02-07 20:42:58  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define v vector 
#define s stack
#define q queue 
#define l list 
#define pq priority_queue 
#define p pair
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define si stack<int>
#define qi queue<int>
#define li list<int> 
#define pii pair<int,int>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

string str;
string answer;
string tmp;
// 0 => NULL, 1 => (, 2 => (n, 3 => (n) 
int state;
int n;

void Solve(void) {
	for (int i = 0; i < str.length(); i++) {
		switch (state) {
		case 0:
			if (str[i] == '(') {
				tmp += str[i];
				state = 1;
			}
			else {
				answer += tmp + str[i];
				state = 0;
			}
			break;
		case 1:
			if ('1' <= str[i] && str[i] <= '9') {
				tmp += str[i];
				n = str[i] - '0';
				state = 2;
			}
			else {
				answer += tmp + str[i];
				state = 0;
			}
			break;
		case 2:
			if (str[i] == ')') {
				tmp = "";
				state = 3;
			}
			else {
				answer += tmp + str[i];
				state = 0;
			}
			break;
		case 3:
			while (n--) {
				answer += str[i];
			}
			state = 0;
			break;
		default:
			break;
		}
	}

	answer += tmp;
	cout << answer << endl;
}

void Init(void) {
	Boost;
	cin >> str;
}

int main(void) {
	Init();
	Solve();
	return 0;
}