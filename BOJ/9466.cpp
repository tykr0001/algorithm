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
\*************  2021-01-21 16:21:11  *************/

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
#define INF 2e9
#define LINF 9e18
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int T;
int N;
int answer;
vi stud;
vb visited;
vb done;


void DFS(int root){
    visited[root] = true;
    int next = stud[root];
    if(!visited[next]){
        DFS(next);
    }
    else if(!done[next]){
        int i = root;
        do {
            answer--;
            i = stud[i];
        } while(i != root);
    }
    done[root] = true;
}

void Solve(void) {
    for (int i = 1; i < N + 1; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
    answer = N;
    stud.clear();
    stud.resize(N + 1);
    visited.clear();
    visited.resize(N + 1, false);
    done.clear();
    done.resize(N + 1, false);

    for (int i = 1; i < N + 1; i++) {
        cin >> stud[i];
    }
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