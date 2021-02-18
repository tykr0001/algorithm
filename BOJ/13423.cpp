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
\*************  2021-01-15 22:56:51  *************/

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

int T;
int N;
int answer;
vi dots;

void Solve(void) {
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 2; j < N; j++) {
            int a, b, c;
            a = dots[i];
            c = dots[j];
            if ((c + a) % 2) continue;
            b = *lower_bound(dots.begin() + i + 1, dots.begin() + j, (c + a) / 2);
            if (b - a == c - b) {
                answer++;
            }
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
    dots.clear();
    dots.resize(N);
    answer = 0;
    for (int i = 0; i < N; i++) {
        cin >> dots[i];
    }
    sort(dots.begin(), dots.end());
}

int main(void) {
    Boost;
    cin >> T;
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}