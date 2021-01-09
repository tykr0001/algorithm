#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

LL t;
LL m, n;

vector<vector<bool>> block;

int dfs(int x, int y){
    if(x==0){
        if(!block[x][y+1] && block[x+1][y])
            return -1;
    }
    else{
        if(!block[x][y+1] && block[x-1][y])
            return -1;
    }
    for(int i=0; i<m; ++i){
        if(block[x][]){
            
        }
        if(block[x][x]){

        }
    }
}

int main(void) {
    cin >> t;
    while (t--) {
        cin >> m >> n;
        block.resize(2, vector<bool>(m,true));

        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            block[x][y] = false;
        }

        int ret;
        for(int i=0; i<m; i++){
            if(block[0][i]){
                ret = dfs(0,i);
                break;
            }
            else if(block[1][i]){
                ret = dfs(1,i);
                break;
            }
        }


        block.clear();
    }
}