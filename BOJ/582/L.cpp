#include <bits/stdc++.h>

using namespace std;

vector<list<int>> g;
vector<int> in;
vector<int> out;
int V, E;

bool isHamiltonianPath(){
    int init = 0;
    int goal = 0;
    for(int i=1; i<=V; i++){
        if(in[i] != out[i]){
            if(in[i] == out[i]+1)
                init++;
            else if(in[i] == out[i]-1)
                goal++;
            else
                return false;
        }
    }
}
int main(void){
    cin >> V >> E;
    g.resize(V+1);
    in.resize(V+1, 0);
    out.resize(V+1, 0);
    for(int i=0; i<E; i++){
        int src, dst;
        cin >> src >> dst;
        g[src].push_back(dst);
        in[dst]++;
        out[src]++;
    }

    if(isHamiltonianPath()){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}