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
\*************  2021-01-18 09:36:34  *************/

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
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int N,M;
vi answer;
vi need;
v<li> graph;

void Solve(void) {
    qi  search_q;
    for(int i=1; i<=N; i++){
        if(need[i]==0){
            search_q.push(i);
        }
    }
    while(!search_q.empty()){
        int idx = search_q.front();
        search_q.pop();
        if(need[idx] == 0){
            answer.push_back(idx);
        }
        while(!graph[idx].empty()){
            int i = graph[idx].back();
            graph[idx].pop_back();
            if(--need[i] == 0){
                search_q.push(i);
            }
        }
    }

    for(int i : answer){
        cout << i << " ";
    }
	return;
}

void Init(void) {
	Boost;
    cin >> N >> M;
    need.resize(N+1, 0);
    graph.resize(N+1);
    for(int i=0; i<M;i++){
        int src, dst;
        cin >> src >> dst;
        graph[src].push_back(dst);
        need[dst]++;
    }
	return;
}

int main(void) {
	Init();
	Solve();
	return 0;
}