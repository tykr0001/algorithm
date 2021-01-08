#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));
    for(int i=0; i<N; i++){
        string tmp;
        cin >> tmp;
        for(int j=0; j<M; j++){
            v[i][j] = tmp[j] - '0';
        }
    }
    
}