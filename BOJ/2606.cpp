#include <bits/stdc++.h>

using namespace std;

vector<list<int>> table;
vector<bool> is_visited;
queue<int> q;
int answer = 0;

int main(void){
    int N, M;
    cin >> N >> M;
    table.resize(N+1);
    is_visited.resize(N+1, false);
    for(int i=0; i<M; i++){
        int src, dst;
        cin >> src >> dst;
        table[src].emplace_back(dst);
        table[dst].emplace_back(src);
    }

    q.emplace(1);
    is_visited[1] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(list<int>::iterator iter = table[front].begin();iter != table[front].end();iter++){
            if(!is_visited[*iter]){
                q.emplace(*iter);
                is_visited[*iter] = true;
                answer++;
            }
        }
    }
    cout << answer << endl;
}