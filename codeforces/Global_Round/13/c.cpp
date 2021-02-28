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
\*************  2021-03-01 00:29:51  *************/

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
#define Deb(x) cout<<#x<<" = "<<x<<endl;
typedef long long ll;
/*************************************************/

int t;
int N;
ll next_pos;
ll answer;
v<ll> S;

void Solve(void) {
    for (int i = 1; i <= N; i++) {
        while (S[i] != 1) {
            if (S[i] + i > N) {
                if (i != N) {
                    answer += S[i] + i - N;
                    S[i] = N - i;
                }
                else {
                    answer += S[i] - 1;
                    S[i] = 1;
                }
            }
            else {
                next_pos = i;
                while (next_pos <= N) {
                    if (S[next_pos] == 1) {
                        next_pos++;
                    }
                    else {
                        next_pos = S[next_pos]-- + next_pos;
                    }
                }
                answer++;
            }
        }
        for(int j=1; j<=N; j++){
            cout << S[j] << " ";
        }
        cout << endl;
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
    answer = 0;
    S.clear();
    S.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }
}

int main(void) {
    Boost;
    cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}